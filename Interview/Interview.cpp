// Interview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "001.h"
#include "wind.h"
#include "operator_overload.h"
#include "global.h"

char* strop()
{
	static char a[10];
	char b[5];
	strcpy(a, "aaaaaaaaaa");
	strcpy(b,"bbbbb");
	strcat(a,b);
	return a;

}

int main(int argc, char* argv[])
{
	
	
	Interview* a = (Interview*)new Interview_operator();
	a->Run();
//	union {
//          short   s;
//          char    c[sizeof(short)];
//      } un;
//
//      un.s = 0x0102;
//     //printf("%s: ", CPU_VENDOR_OS);
//     if (sizeof(short) == 2) {
//         if (un.c[0] == 1 && un.c[1] == 2)
//             printf("big-endian\n");
//         else if (un.c[0] == 2 && un.c[1] == 1)
//             printf("little-endian\n");
//        else
//             printf("unknown\n");
//     } else
//         printf("sizeof(short) = %d\n", sizeof(short));

	return 0;
}

