// OOTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class BaseTemplate 
{ 
public: 

    void step1(void)  // ���ɱ����ĵ�ʵ��ϸ�� 
    { 
		std::cout << "Base: step1���ܸ���" << std::endl;
    } 
    virtual void step2(void ) // ���Ա��������޸ĵ�ʵ��ϸ�� 
    { 
         std::cout << "Base: step2���Ը���" << std::endl;
    } 

protected: 
    virtual void step3(void ) =0; // ���뱻�������޸ĵ�ʵ��ϸ��     

public: 
    void work(void) // �Ǽܺ�����ʵ���˹Ǽ� 
    { 
       step1() ; 
       step2() ; 
       step3() ;     
    } 
};
class Dervie:public BaseTemplate
{
public:
	void step1(void)  // ���ɱ����ĵ�ʵ��ϸ�� 
    { 
		std::cout << "Derive: step1���ܸ���" << std::endl;
    } 
	void step2(void ) // ���Ա��������޸ĵ�ʵ��ϸ�� 
    { 
         std::cout << "Derive: step2���Ը���" << std::endl;
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

