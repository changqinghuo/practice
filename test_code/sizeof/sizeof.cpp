// sizeof.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class test{
private:
	int i;
	int j;
};

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	int array[10];
	test b[5];
	printf("%d\n", sizeof(b));
	char* ptr1;
	char* ptr2;
	ptr1 = (char*)&array[0];
	ptr2 = (char*)&array[1];

	printf("%016x\n", ptr1);
	printf("%016x\n", ptr2);
	int size = (char*)ptr2 - (char*)ptr1;
	printf("%d\n", size);
	
	return 0;
}

