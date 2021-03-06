// socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stdio.h"
#include "winsock2.h"
#include "windows.h"

using namespace std;

#define  PORT 5150
#define DATA_BUFSIZE 1024

typedef struct {
	OVERLAPPED Overlapped;
	WSABUF DataBuf;
	CHAR Buffer[DATA_BUFSIZE];
	DWORD BytesSEND;
	DWORD BytesRECV;
} PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA; 

typedef struct{
	SOCKET Socket;
}PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

DWORD WINAPI ServerWorkerThread(LPVOID CompletionPortID);

int main(int argc, char* argv[])
{
	SOCKADDR_IN InternetAddr;
	SOCKET Listen;
	HANDLE ThreadHandle;
	SOCKET Accept;
	HANDLE CompletionPort;
	SYSTEM_INFO SystemInfo;
	LPPER_HANDLE_DATA PerHandleData;
	LPPER_IO_OPERATION_DATA PerioData;
	int i;
	DWORD RecvBytes;
	DWORD Flags;
	DWORD ThreadID;
	WSADATA wsaData;
	DWORD Ret;

	if(Ret = WSAStartup((2,2), &wsaData) != 0)
	{
		printf("WSAStartup() failed with error %d\n", Ret);		
        return 1;
	}
	else
	{
		std::cout << "WSAStartup() is OK!" << std::endl;
	}

	if ((Listen = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
	{
		cout << "Listen socket failed: " << WSAGetLastError() << endl;
		return 1;
	}
	else
	{
		cout << "Listen socket is ok" << endl;
	}

	// Setup an I/O completion port
	
	if ((CompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0)) == NULL)		
	{
		
		printf("CreateIoCompletionPort() failed with error %d\n", GetLastError());
		
		return 1;
		
	}
	
	else
		
		printf("CreateIoCompletionPort() is damn OK!\n");
	
	
	
	
	
	// Determine how many processors are on the system
	
	GetSystemInfo(&SystemInfo);
	
	// Create worker threads based on the number of processors available on the
	
	// system. Create two worker threads for each processor
	
	for(i = 0; i < (int)SystemInfo.dwNumberOfProcessors * 2; i++)
		
	{
		
		// Create a server worker thread and pass the completion port to the thread
		
		if ((ThreadHandle = CreateThread(NULL, 0, ServerWorkerThread, CompletionPort,  0, &ThreadID)) == NULL)			
		{
			
			printf("CreateThread() failed with error %d\n", GetLastError());
			
			return 1;
			
		}
		
		else
			
			printf("CreateThread() is OK!\n");
		
		// Close the thread handle
		
		CloseHandle(ThreadHandle);		
      }

	InternetAddr.sin_family = AF_INET;
	InternetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	InternetAddr.sin_port = htons(PORT);

	if(bind(Listen, (PSOCKADDR)&InternetAddr, sizeof(InternetAddr)) == SOCKET_ERROR)
	{
		cout << "bind listening socket error" <<  endl;
		return 1;
	}
	else
	{
		cout << "bind listening socket is ok" << endl;
	}



	if(listen(Listen, 5) == SOCKET_ERROR)
	{
		cout << "listen error" <<  endl;
		return 1;
	}
	else
	{		
		cout << "listen is working" << endl;
	}

	while(1)
	{
		if((Accept = WSAAccept(Listen, 0, 0, 0, 0)) == SOCKET_ERROR)
		{
			cout << "accept error" << endl;
			return 1;
		}

		PerHandleData = new PER_HANDLE_DATA;
		cout << "Socket Number " << Accept << " connected" << endl;
		PerHandleData->Socket = Accept;

		if (CreateIoCompletionPort((HANDLE) Accept, CompletionPort, (DWORD) PerHandleData, 0) == NULL)			
		{			
			printf("CreateIoCompletionPort() failed with error %d\n", GetLastError());			
			return 1;			
		}		
		else
			
                        printf("CreateIoCompletionPort() is OK!\n");

		PerioData = new PER_IO_OPERATION_DATA;

		PerioData->BytesSEND = 0;
		PerioData->BytesRECV = 0;
		PerioData->DataBuf.len = DATA_BUFSIZE;
		PerioData->DataBuf.buf = PerioData->Buffer;

		Flags = 0;
		if(WSARecv(Accept, &(PerioData->DataBuf), 1, &RecvBytes, &Flags,  &(PerioData->Overlapped), NULL) == SOCKET_ERROR)
		{
			cout << "Recv error" << endl;
			return 1;
		}
		else
		{
			cout << "Recv OK" << endl;
		}

	}


	printf("Hello World!\n");
	return 0;
}


DWORD WINAPI ServerWorkerThread(LPVOID CompletionPortID)
{
      HANDLE CompletionPort = (HANDLE) CompletionPortID;
      DWORD BytesTransferred;
      LPPER_HANDLE_DATA PerHandleData;
      LPPER_IO_OPERATION_DATA PerIoData;
      DWORD SendBytes, RecvBytes;
      DWORD Flags;

 

            while(TRUE)
            {

                        if (GetQueuedCompletionStatus(CompletionPort, &BytesTransferred,
                                    (LPDWORD)&PerHandleData, (LPOVERLAPPED *) &PerIoData, INFINITE) == 0)

                        {

                                    printf("GetQueuedCompletionStatus() failed with error %d\n", GetLastError());

                                    return 0;

                        }

                        else

                                    printf("GetQueuedCompletionStatus() is OK!\n");

 

                        // First check to see if an error has occurred on the socket and if so

                        // then close the socket and cleanup the SOCKET_INFORMATION structure

                        // associated with the socket

                        if (BytesTransferred == 0)

                        {

                                    printf("Closing socket %d\n", PerHandleData->Socket);

                                    if (closesocket(PerHandleData->Socket) == SOCKET_ERROR)

                                    {

                                                printf("closesocket() failed with error %d\n", WSAGetLastError());

                                                return 0;

                                    }

                                    else

                                                printf("closesocket() is fine!\n");

 

                                    GlobalFree(PerHandleData);

                                    GlobalFree(PerIoData);

                                    continue;

                        }

 

                        // Check to see if the BytesRECV field equals zero. If this is so, then

                        // this means a WSARecv call just completed so update the BytesRECV field

                        // with the BytesTransferred value from the completed WSARecv() call

                        if (PerIoData->BytesRECV == 0)

                        {

                                    PerIoData->BytesRECV = BytesTransferred;

                                    PerIoData->BytesSEND = 0;

                        }

                        else

                        {

                                    PerIoData->BytesSEND += BytesTransferred;

                        }

 

                        if (PerIoData->BytesRECV > PerIoData->BytesSEND)

                        {

                                    // Post another WSASend() request.

                                    // Since WSASend() is not guaranteed to send all of the bytes requested,

                                    // continue posting WSASend() calls until all received bytes are sent.

                                    ZeroMemory(&(PerIoData->Overlapped), sizeof(OVERLAPPED));

                                    PerIoData->DataBuf.buf = PerIoData->Buffer + PerIoData->BytesSEND;

                                    PerIoData->DataBuf.len = PerIoData->BytesRECV - PerIoData->BytesSEND;

 

                                    if (WSASend(PerHandleData->Socket, &(PerIoData->DataBuf), 1, &SendBytes, 0,

                                                &(PerIoData->Overlapped), NULL) == SOCKET_ERROR)

                                    {

                                                if (WSAGetLastError() != ERROR_IO_PENDING)

                                                {

                                                            printf("WSASend() failed with error %d\n", WSAGetLastError());

                                                            return 0;

                                                }

                                    }

                                    else

                                                printf("WSASend() is OK!\n");

                        }

                        else

                        {

                                    PerIoData->BytesRECV = 0;

                                    // Now that there are no more bytes to send post another WSARecv() request

                                    Flags = 0;

                                    ZeroMemory(&(PerIoData->Overlapped), sizeof(OVERLAPPED));

                                    PerIoData->DataBuf.len = DATA_BUFSIZE;

                                    PerIoData->DataBuf.buf = PerIoData->Buffer;

 

                                   if (WSARecv(PerHandleData->Socket, &(PerIoData->DataBuf), 1, &RecvBytes, &Flags,

                                                &(PerIoData->Overlapped), NULL) == SOCKET_ERROR)

                                    {

                                                if (WSAGetLastError() != ERROR_IO_PENDING)

                                                {

                                                            printf("WSARecv() failed with error %d\n", WSAGetLastError());

                                                            return 0;

                                                }

                                    }

                                    else

                                                printf("WSARecv() is OK!\n");

                        }

            }

}
