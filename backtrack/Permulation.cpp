#include "stdafx.h"
#include <algorithm>
#include "Permulation.h"

Permulation::Permulation(vector<int> data):m_data(data)
{

}

void Permulation::Run()
{
	int len = m_data.size();
	vector<int> ary;
	ary.assign(len, -1);
	backtrack(ary, 0, len);
}
void Permulation::backtrack(vector<int>& ary, int current, int length)
{
	if(IsSolution(ary, current, length))
	{
		PrintSolution(ary);
		return;
	}

	vector<int> candidates;
	ConstuctCandidates(ary, current, length, candidates);
	vector<int>::iterator iter = candidates.begin();
	for(;iter!=candidates.end(); ++iter)
	{
		//try 
		ary[current] = *iter;

		backtrack(ary, current+1, length);

		//restore
		ary[current] = -1;
	}

}

void Permulation::ConstuctCandidates(vector<int>& ary, int current, int length, vector<int>& candidates)
{
// 	bool* used = new bool[length];
// 	int i = 0;
// 	for(i=0; i < length; i++)
// 	{
// 		used[i] = false;
// 
// 	}
// 	
// 	for(i = 0; i < current; i++)
// 	{
// 		used[ary[i]] = true;
// 	}
// 
// 	for(i = 0; i< length; i++)
// 	{
// 		if(!used[i])
// 		{
// 			candidates.push_back(i);
// 		}
// 	}

	for(int i = 0; i < length; i++)
	{
		if(find(ary.begin(), ary.begin()+current, i) == ary.begin()+current)
		{
			vector<int>::iterator iter = candidates.begin();
			//avoid duplicated element
			for(; iter != candidates.end(); iter++)
			{
				if(m_data[i] == m_data[*iter])
				{
					break;
				}
			}
			if(iter == candidates.end())
			{
				candidates.push_back(i);
			}
		}
	}


}

bool Permulation::IsSolution(vector<int>& ary, int current, int length)
{
	return current == length;
}

void Permulation::PrintSolution(vector<int>& ary)
{	
	//for_each(ary.begin(), ary.end(), Permulation::print);
//	for_each(ary.begin(), ary.end, std::bind1st(std::mem_fun(&Permulation::print), this));
	vector<int>::iterator iter;
	for(iter = ary.begin(); iter != ary.end(); iter++)
	{
		std::cout << m_data[*iter] << " ";
	}
	std::cout << std::endl;
}