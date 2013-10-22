// OOTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class BaseTemplate 
{ 
public: 

    void step1(void)  // 不可被更改的实现细节 
    { 
		std::cout << "Base: step1不能更改" << std::endl;
    } 
    virtual void step2(void ) // 可以被派生类修改的实现细节 
    { 
         std::cout << "Base: step2可以更改" << std::endl;
    } 

protected: 
    virtual void step3(void ) =0; // 必须被派生类修改的实现细节     

public: 
    void work(void) // 骨架函数，实现了骨架 
    { 
       step1() ; 
       step2() ; 
       step3() ;     
    } 
};
class Dervie:public BaseTemplate
{
public:
	void step1(void)  // 不可被更改的实现细节 
    { 
		std::cout << "Derive: step1不能更改" << std::endl;
    } 
	void step2(void ) // 可以被派生类修改的实现细节 
    { 
         std::cout << "Derive: step2可以更改" << std::endl;
    } 
	
protected:
	void step3(void)
	{
		std::cout << "Derive: step3" << std::endl;

	}
};
int main(int argc, char* argv[])
{
    BaseTemplate* a = new Dervie;
	a->work();
	
	Dervie* b = new Dervie;
	b->work();
	system("pause");
	return 0;
}

