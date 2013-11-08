#include "stdafx.h"

#include "operator_overload.h"



void PrintInt(int nValue)  
{  
    cout << "PrintInt called: " <<nValue << std::endl;  
}  

void Interview_operator::Run()
{
	Cents c7(7);
	PrintInt(c7);
	

	
	std::vector<Cents>  v;  
    Cents c1(1);  
    Cents c2(2);  
    Cents c3(3);  
    Cents c4(4);  
    v.push_back(c7);  
    v.push_back(c1);      
	
    v.push_back(c2);      
	
    v.push_back(c3);  
	
    v.push_back(c4);  
	std::vector<Cents>::iterator pos = find_if(v.begin(), v.end(), Cents(3));
	PrintInt(*pos);
	PrintInt(Cents(3));

}