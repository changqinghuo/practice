#include <iostream>
#include <string>
using namespace std;
// Problem Statement
// ????
// Little Elephant from the Zoo of Lviv likes strings.
// 
// You are given a string A and a string B of the same length. In one turn Little Elephant can choose any character of A and move it to the beginning of the string (i.e., before the first character of A). Return the minimal number of turns needed to transform A into B. If it's impossible, return -1 instead.
// Definition
// ????
// Class:
// LittleElephantAndString
// Method:
// getNumber
// Parameters:
// string, string
// Returns:
// int
// Method signature:
// int getNumber(string A, string B)
// (be sure your method is public)
// ????
// 
// Constraints
// -
// A will contain between 1 and 50 characters, inclusive.
// -
// B will contain between 1 and 50 characters, inclusive.
// -
// A and B will be of the same length.
// -
// A and B will consist of uppercase letters ('A'-'Z') only.
// Examples
// 0)
// 
// ????
// "ABC"
// "CBA"
// Returns: 2
// 		 The optimal solution is to make two turns. On the first turn, choose character 'B' and obtain string "BAC". On the second turn, choose character 'C' and obtain "CBA".
// 		 1)
// 		 
// 		 ????
// 		 "A"
// 		 "B"
// Returns: -1
// 		 In this case, it's impossible to transform A into B.
// 		 2)
// 		 
// 		 ????
// 		 "AAABBB"
// 		 "BBBAAA"
// Returns: 3
// 		 
// 		 3)
// 		 
// 		 ????
// 		 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// 		 "ZYXWVUTSRQPONMLKJIHGFEDCBA"
// Returns: 25
// 		 
// 		 4)
// 		 
// 		 ????
// 		 "A"
// 		 "A"
// Returns: 0
// 		 
// 		 5)
// 		 
// 		 ????
// 		 "DCABA"
// 		 "DACBA"
// Returns: 2
// 		 
// This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

class LittleElephantAndString{
public:
	int getNumber(string A, string B);
private:
	int minStep(string& A, string& B);
	int distance(const string& A, const string& B);
	int longestSequence(const string& A, const string& B);
	
    void move(string& A, int index);
	void unmove(string& A, int index);


};
int LittleElephantAndString::getNumber(string A, string B)
{
	for(int i= B.length() -1; i>=0; i--)
	{
	

	}
	return 0;

}

void LittleElephantAndString::move(string& A, int index)
{
	char tmp = A[index];	
	A.erase(index, 1);
	A.insert(0,tmp);

}

void LittleElephantAndString::unmove(string& A, int index)
{
	char tmp = A[0];
	A.insert(1, tmp);
	A.erase(0, 1);
	
}

int LittleElephantAndString::minStep(string& A, string& B)
{
	if(distance(A, B) == 0)
	{
		return 0;
	}

	int max = -1;
	int maxindex = 1;
	for(int i=1; i< A.length(); i++)
	{
	    move(A, i);
		int dist = distance(A, B);
		int longest = longestSequence(A, B);
		if(max < dist + longest)
		{
			max = dist+ longest;
			maxindex = i;
		}
	    move(A, i);
	}

	char tmp = A[0];


	return 0;


}

int LittleElephantAndString::distance(const string& A, const string& B)
{
	int dist = 0;
	for(int i=0; i<A.length(); i++)
	{
		if(A[i] != B[i])
		{
			dist++;
		}

	}
	return dist;
}

int LittleElephantAndString::longestSequence(const string& A, const string& B)
{
	int count = 0;
	int longest = 0;
	for(int i=0; i<A.length(); i++)
	{
		if(A[i] == B[i])
		{
			count++;
		}
		else
		{
			if(count > longest)
			{
				longest = count;
			}
			count = 0;
		}
	}
	return longest;
}