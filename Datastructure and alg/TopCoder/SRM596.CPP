#include "stdafx.h"
#include <iostream>
#include <algorithm>

#include "SRM596.H"

IncrementAndDoubling::IncrementAndDoubling()
{
	minArray = std::vector<int>(1001, 9999);
	minArray[0] = 0;
	minArray[1] = 1;
	//DP(1000);
}

int IncrementAndDoubling::getMin(std::vector <int> desiredArray)
{
	return minCount(desiredArray);

// 	int count =0;
// 	for(int i=0; i< desiredArray.size(); i++)
// 	{
// 		count += minArray[desiredArray[i]];
// 	}

//	return count;
}

bool notzero(int a)
{
	return a != 0;
}

bool Isdivideby2(int a)
{
	return a%2 != 0;
}

void divideby2(int &ele)
{
	ele = ele/2;
}
void multiby2(int &ele)
{
	ele = ele/2;
}


int IncrementAndDoubling::minCount(std::vector<int>& desiredArray)
{
	vector<int>::iterator iter = find_if(desiredArray.begin(), desiredArray.end(), notzero);
	if(iter == desiredArray.end())
	{
		return 0;
	}

	int mincount = 9999;

	iter = find_if(desiredArray.begin(), desiredArray.end(), Isdivideby2);
	if(iter == desiredArray.end())
	{
		for_each(desiredArray.begin(), desiredArray.end(), 	divideby2);
		int count = minCount(desiredArray);
		if(mincount > count + 1)
		{
			mincount = count + 1;
		}
		for_each(desiredArray.begin(), desiredArray.end(), 	multiby2);
		
	}

	for(iter = desiredArray.begin(); iter != desiredArray.end(); iter++)
	{
		*iter = *iter-1;
		if(*iter >= 0)
		{
			int count = minCount(desiredArray);
			if(mincount > count + 1)
			{
				mincount = count + 1;
			}
		}	
		
		*iter = *iter+1;		
	}
	

	return mincount;

}
void IncrementAndDoubling::DP(int goal)
{
    
	for(int i =1; i <= goal; i++)
		for(int j=0; j<i; j++)
	{
// 		int k = j;
// 		int count =0;
// 		while(k <= i)
// 		{
// 			k++;
// 			count++;
// 		}
// 
// 		k  =j;
// 		int count_double =0;
// 		while( k <= i)
// 		{
// 			k=k*2;
// 			count_double++;
// 		}
// 
// 		if(k == i)
// 		{
// 			count = count < count_double? count: count_double;			
// 		}


		if( j+1 == i)
		{
			if(minArray[i] > minArray[j] +1)
			{
				minArray[i] = minArray[j] +1;
			}
		}

	    if(j*2 == i)
		{
			if(minArray[i] > minArray[j] +1)
			{
				minArray[i] = minArray[j] +1;
			}
		}
	}

	
}

void IncrementAndDoubling::Test()
{
	std::vector <int> desiredAry;
	int step;

	//Test Case 1:

// 	desiredAry.push_back(2);
// 	desiredAry.push_back(1);
// 	step = getMin(desiredAry);
// 	if(step == 3)
// 	{
// 		std::cout << "TestCase 1 success!" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "TestCase 1 failed, expected: " << 3 << ", actual: " << step << std::endl;
// 	}
// 
// 	std::vector<int> ary;
// 	ary.push_back(1);
// 	ary.push_back(2);
// 	
// 
// 	std::cout << (desiredAry == ary) << std::endl;
// 
// 
// 	//Test Case 2:
// 	desiredAry.clear();
// 	desiredAry.push_back(16);
// 	desiredAry.push_back(16);
// 	desiredAry.push_back(16);
// 	step = getMin(desiredAry);
// 
// 	if(step == 7)
// 	{
// 		std::cout << "TestCase 2 success!" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "TestCase 2 failed, expected: " << 7 << ", actual: " << step << std::endl;
// 	}

	//Test Case 3:

	desiredAry.clear();
	desiredAry.push_back(123);
	desiredAry.push_back(234);
	desiredAry.push_back(345);
	desiredAry.push_back(456);
	desiredAry.push_back(567);
	desiredAry.push_back(789);
	step = getMin(desiredAry);
	
	if(step == 40)
	{
		std::cout << "TestCase 3 success!" << std::endl;
	}
	else
	{
		std::cout << "TestCase 3 failed, expected: " << 40 << ", actual: " << step << std::endl;
	}




}