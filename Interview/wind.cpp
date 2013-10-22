#include "StdAfx.h"
#include <iostream>
#include "wind.h"

void Interview_Wind::Item1()
{
	class A1
	{
	public :
		virtual void Name() {printf("A");}
		void Hello() {printf("HA");}
	};
	
	class B1:public A1
	{
	public:
		void Name(){printf("B");}
		void Hello(){
			printf("HB");
		}
	};
	
	class C1:public B1
	{
	public:
		virtual void Name() { printf("C");}
		void Hello() {printf("HC");}
	};
	
	A1* Base = new A1();
	B1* B = new B1();
	C1* C = new C1();
	
	Base->Name();
	Base->Hello();
	printf("\n");
	
	B->Name();
	B->Hello();
	printf("\n");
	
	Base = (A1*) B;
	Base->Name();
	Base->Hello();
	printf("\n");
	
	Base = (A1*) C;
	Base->Name();
	Base->Hello();
	printf("\n");

	delete Base;
	delete B;
	delete C;
	
	
}

void Interview_Wind::Item2()
{
	class A
	{
	public:
		A() {std::cout << "A";};
		~A(){
			std::cout << "Base Constructor:" << m_str.c_str() << std::endl ;
		}
		A& operator = (A&)
		{
			std::cout << "C";
			return *this;
		}
		A(A&)
		{
			std::cout << "D";
		}
		std::string m_str;
	};
	class B:public A
	{
	public:
		B() {
			std::cout << "E";
		}
		~B()
		{
			std::cout << "derive constructor:" << m_str.c_str() << std::endl;
		}
		B& operator=(B&)
		{
			std::cout << "G";
			return *this;
		}
		B(B&)
		{
			std::cout << "H";
		}
	};

	B b;  //constructor:  Base->derive
	b.m_str = "B";
	B c;
	c.m_str = "C";
	std::cout << std::endl;

	A a = b; // copy constructor called
	a.m_str = "A";
	std::cout << std::endl;

	b = c; // assignment operator called
	std::cout << std::endl;

	B d = b;  //base constructor called and copy constructor  
	d.m_str = "D";
	std::cout << std::endl;


	std::cout << std::endl;
	// deconstructor called sequence: D, A, C, B
	// derive->base

}
void Interview_Wind::Item3()
{
	struct s{
		int a;
		char b;
		unsigned int c;
		double d;
	};

	s a;
	char b[] = "wind";
	
	char* c = b;
	wchar_t d[] = L"万得wind";	
	char* e = "大家好";
	wchar_t f[] = L"wind";
	std::cout << sizeof(a) << std::endl;
	std::cout << sizeof(b) <<  ", " << strlen(b) <<  std::endl;
	std::cout << sizeof(c) << ", " << strlen(c) <<  std::endl;
	std::cout << sizeof(d) << ", " << wcslen(d) << std::endl;
    std::cout << sizeof(e) << ", " << strlen(e) << std::endl;
	std::cout << sizeof(f) << ", " << wcslen(f) << std::endl;

	

}
   //swap two variables
	void swap(int& a, int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	};
	//This does not change anything
	void swap(int* a, int* b)
	{
		int* tmp = a;
		a = b;
		b = tmp;
	};
//	void swap(int* a, int* b)
//	{
//		int tmp = *a;
//		*a = *b;
//		*b = tmp;
//	};
void Interview_Wind::Item4()
{
	int a =1;
	int b = 2;
	swap(a, b); 
	std::cout << a << "," << b << std::endl;  //2,1
	swap(&a, &b);
	std::cout << a << "," << b << std::endl; // 2,1
	int* c = &a;
	int* d = &b;
	swap(c, d);             // 2, 1
	std::cout << *c << "," << *d << std::endl;
	swap(*c, *d); //This call swap(int&, int&) // 1,2
	std::cout << *c << "," << *d << std::endl;
}

void Interview_Wind::Item5()
{
   //一元二次方程解 a*x*x + b*x +c = 0
	float a, b, c;
	 a= 1.2;
	 b = 3;
	 c = 1;

	int num_soltion = 0;
	if(a == 0)
	{
		if(b == 0)
		{
			num_soltion = 0;
		}
		else
		{
			num_soltion = 1;
		}
		std::cout << num_soltion << std::endl;
		return;

	}
	float root = b*b - 4*a*c;
	if(root < 0)
	{
		num_soltion = 0;
	}
	else if(root == 0)
	{
		num_soltion = 1;

	}
	else
	{
		num_soltion = 2;
	}
	std::cout << num_soltion << std::endl;
}

void Interview_Wind::Item6()
{
	//给定一个无序数组s，其范围在1-N之间，N为一个大整数；求满足下列条的个数，复杂度为O(N)
	//a: s中存在数对为相邻关系i = j+1
	//b：并且这两个数的和也在数组s中
	int N = 1000;
	int count = 0;
	bool* bucket = new bool[N+1];
	for(int j= 0; j < N+1; j++)
	{
		bucket[j] = false;
	}
	int a[] = {100, 33,1, 8,9 , 17, 99, 199};
	for(int i= 0; i<8;  i++)
	{
		bucket[a[i]] = true;
	}
	for(i = 1; i< N; i++)
	{
		if(bucket[i] && bucket[i+1] && bucket[i+i+1])
		{
			count ++;
		}
	}
	std::cout << count << std::endl;

}
void Interview_Wind::Item7()
{

	//Substring problem
}
void Interview_Wind::Run()
{
	//
	Item2();
}

