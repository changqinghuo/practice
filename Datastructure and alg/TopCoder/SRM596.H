
/*Problem Statement
????
You have an array with N elements. Initially, each element is 0. You can perform the following operations:
Increment operation: Choose one element of the array and increment the value by one.
Doubling operation: Double the value of each element.
You are given a vector <int> desiredArray containing N elements. Compute and return the smallest possible number of operations needed to change the array from all zeros to desiredArray.
Definition
????
Class:
IncrementAndDoubling
Method:
getMin
Parameters:
vector <int>
Returns:
int
Method signature:
int getMin(vector <int> desiredArray)
(be sure your method is public)
????

Constraints
-
desiredArray will contain between 1 and 50 elements, inclusive.
-
Each element of desiredArray will be between 0 and 1,000, inclusive.
Examples
0)

????
{2, 1}
Returns: 3
			 One of the optimal solutions is to apply increment operations to element 0 twice and then to element 1 once. Total number of operations is 3.
			 1)
			 
			 ????
		 {16, 16, 16}
Returns: 7
			 The optimum solution looks as follows. First, apply an increment operation to each element. Then apply the doubling operation four times. Total number of operations is 3+4=7.
			 2)
			 
			 ????
		 {100}
Returns: 9
			 
			 3)
			 
			 ????
		 {0, 0, 1, 0, 1}
Returns: 2
			 Some elements in desiredArray may be zeros.
			 4)
			 
			 ????
		 {123, 234, 345, 456, 567, 789}
Returns: 40
			 
			 5)
			 
			 ????
		 {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7}
Returns: 84
			 
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#include <vector>

using namespace std;

class IncrementAndDoubling
{
public:
	int getMin(std::vector <int> desiredArray);
	IncrementAndDoubling();
	void Test();
private:
	void DP(int goal);
	int minCount(std::vector <int>& desiredArray);
	std::vector<int> minArray;	

};