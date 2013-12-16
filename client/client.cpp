// client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "winsock.h"



int main(int argc, char* argv[])
{
	 // Initialize Winsock

  WSADATA wsaData;

  int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);

  if (iResult != NO_ERROR)

    printf("Client: Error at WSAStartup().\n");

  else

    printf("Client: WSAStartup() is OK.\n");

 

  // Create a SOCKET for connecting to server

  SOCKET ConnectSocket;

  ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (ConnectSocket == INVALID_SOCKET)

  {

    printf("Client: Error at socket(): %ld.\n", WSAGetLastError());

    WSACleanup();

    return 0;

  }

  else

    printf("Client: socket() is OK.\n");

 

  // The sockaddr_in structure specifies the address family,

  // IP address, and port of the server to be connected to.

  sockaddr_in clientService;

  clientService.sin_family = AF_INET;

  clientService.sin_addr.s_addr = inet_addr("127.0.0.1");

  clientService.sin_port = htons(5150);

 

  // Connect to server.

  if (connect(ConnectSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR)

  {

    printf("Client: Failed to connect.\n");

    WSACleanup();

    return 0;

  }
  else
    printf("Client: connect() is OK.\n");

 

  // Declare and initialize variables.

  int bytesSent;

  int bytesRecv = SOCKET_ERROR;

  char sendbuf[100] = "Client: Sending some data.";

  char recvbuf[100] = "";

 

//   while(bytesRecv == SOCKET_ERROR )
// 
//   {
// 
//     bytesRecv = recv(ConnectSocket, recvbuf, 100, 0);
// 
//     if (bytesRecv == 0 || bytesRecv == WSAECONNRESET)
// 
//     {
// 
//       printf("Client: Connection Closed.\n");
// 
//       break;
// 
//     }
// 
//     else
// 
//     {
// 
//        printf("Client: recv() is OK.\n");
// 
//        printf("Client: Bytes received: %ld\n", bytesRecv);
// 
//     }
// 
//   }

 

  // Send and receive data.

  bytesSent = send(ConnectSocket, sendbuf, strlen(sendbuf), 0);

  printf("Client: Bytes sent: %ld\n", bytesSent);

  bytesRecv = recv(ConnectSocket, recvbuf, 100, 0);

  printf("Client: Bytes recv: %s", recvbuf);

  WSACleanup();
	printf("Hello World!\n");
	return 0;
}

