// Ctest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A
{
public:
int m_data;
public:
A(int data = 0){m_data = data;}
int GetData(){return doGetData();}
virtual int doGetData(){return m_data;}
};

class B : public A
{
public:
int m_data;
public:
	B(int data = 1){m_data = data;}
int doGetData(){return m_data;}
};

class C : public B
{
public:
	C(int data = 2):B(8){m_data = data;}
public:
	int m_data;

};

int main(int argc, char* argv[])
{
	C c(10);
	cout << c.A::m_data << endl;
	cout << c.B::m_data << endl;
	cout << c.m_data << endl;
	cout << c.GetData() << endl;
	cout << c.doGetData() << endl;
	cout << c.A::GetData() << endl;
	cout<< c.A::doGetData() << endl;

//	float * po;
//	
//	int addr = 0x00481c40;
//	po = (float*)(int*)addr;
//	*(int*)addr = 3;
//	*po = 19;
//	std::cout << (float*)addr << endl;
//	int* p = new int(100);
//	std::cout << p << std::endl;
//    std::cout << p[1] << std::endl;
//	*(int*)addr = 7;
//	std::cout << p[0] << std::endl;
//	//(unsigned int*)0x100000 = 1234;
//	int a = 3.0f;
//	int* apointer = (int*)a;
//	std::cout << apointer << std::endl;
//	std::cout << (int&)apointer << std::endl;
//
//	printf("Hello World!\n");
	return 0;
}

