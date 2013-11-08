#ifndef OPERATOR_OVERLOAD_H
#define  OPERATOR_OVERLOAD_H


#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include "global.h"

using namespace std;

class Cents  
{  
private:  
    int m_nCents;  
public:  
    Cents(int nCents=0)  
    {  
        m_nCents = nCents;  
    }  

	bool operator()(Cents c){   std::cout << "bool operatro called by stl:" << std::endl;
	                            return c.GetCents() == m_nCents;}
    
	operator int() {return m_nCents;}
     
    int GetCents() { return m_nCents; }  
    void SetCents(int nCents) { m_nCents = nCents; }  
}; 

class Interview_operator: public Interview
{
public:
	void Run();

};

#endif