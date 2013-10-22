// NQueen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
class Queen
{
public:
	Queen(int n);
	void SolveByBacktrack();
	void SolveByBruteforce();
private:
	void Backtrack( int k);
	int results_size;
	int* results;
	int solutions;
};
Queen::Queen(int n):results_size(n)
{
	results_size = n;
	solutions =0;
    results = new int(results_size);
	for(int i=0; i< results_size; i++)
	{
		results[i] =0;
	}
}
void Queen::SolveByBacktrack()
{
	Backtrack(0);
}
void Queen::Backtrack(int k)
{
	if(k >= results_size)
	{
		solutions++;
		std::cout << solutions << endl;
	}
	else
	{
		k = k +1;
		for(int i =0; i <results_size; i++)
		{
			results[k] = i;
			Backtrack(k);
		}
		
	}
}

int main(int argc, char* argv[])
{
	Queen q(4);
	q.SolveByBacktrack();
	printf("Hello World!\n");
	return 0;
}

