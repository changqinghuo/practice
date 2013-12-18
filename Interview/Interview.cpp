// Interview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "001.h"
#include "wind.h"
#include "operator_overload.h"
#include "global.h"
#include "substr.h"
#include "honeywell.h"


char* strop()
{
	static char a[10];
	char b[5];
	strcpy(a, "aaaaaaaaaa");
	strcpy(b,"bbbbb");
	strcat(a,b);
	return a;

}

template <typename T>
void func(vector<T>& v)
{
    T& ref = v.front();
	std::cout << ref << std::endl;
}

int main(int argc, char* argv[])
{
	
	
	Interview* a = (Interview*)new HoneyWell();
	a->Run();

// 	std::vector<bool> a(16);
// 	std::cout << a.begin() << endl;
// 	std::cout << a.end() << endl;
// 	
// 	std::vector<int> vint(10, 1);
//     func(a);
// 	//std::cout << testbool << std::endl;
// 
// 
// // 	for(;itertest != a.end(); itertest++)
// // 	{
// // 		std::cout << itertest << endl;
// // 	}
// 
// 	vector<bool> testv(5);
// 	
// 	bool * testb = &testv.front();
// 
// 	std::cout << testb << std::endl;
// 	std::cout << &testv.back() << std::endl;
// 	std::cout << &a[0] << std::endl;
// 	std::cout << &a[1] << std::endl;
// 
// 	std::cout << a.size() << "capacity: " << a.capacity() << std::endl;
// 
// 	std::vector<bool>::iterator iter = find(a.begin(), a.end(), true);
// 
// 	std::cout << iter << std::endl;
// 	std::cout << iter + 1 << std::endl;
// 
// 
// 
// 	std::cout << sizeof(a) << std::endl;
// 
// 	std::vector<int> b;
// 	std::cout << b.size() << "capacity: " << b.capacity() << "; sizeof vector: " << sizeof(b) << std::endl; 
// 	b.resize(100);
// 	std::cout << b.size() << "capacity: " << b.capacity() << "; sizeof vector: " << sizeof(b) << std::endl; 
// 

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

