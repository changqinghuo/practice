#include "StdAfx.h"
#include "honeywell.h"
#include <iostream>
using namespace std;

void HoneyWell::Run()
{
	sizeof_array();
}

void HoneyWell::sizeof_array()
{
	int *p[10];
	cout << sizeof(p) << endl;
	cout << sizeof(p[0]) <<endl;

	int (*p1)[10];
	cout << sizeof(p1) << endl;
	cout << sizeof(p1[0]) << endl;
}
