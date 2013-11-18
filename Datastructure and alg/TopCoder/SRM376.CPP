#include "StdAfx.h"
#include "SRM376.H"
#include <bitset>
#include <vector>
#include <utility>


void Trainyard::Test()
{
	std::vector<string> layout;
	int fuel;
	int count=0;

// 	{
// 		".-....",
// 		"-S---.",
// 		"......"}
// 	2
// 	  Returns: 4
	layout.push_back(".-....");
	layout.push_back("-S---.");
	layout.push_back("......");
	fuel = 2;
	count = reachableSquares(layout, fuel);
    
	if(count == 4)
	{
		std::cout << "Test case 1 Success" << std::endl;
	}
	else
	{
	
		std::cout << "Test case 1 failed: expected: " << 4 << "; actual: " << count << std::endl;	

	}
	//Testcase 2
	
// 		"-....-",
// 		"|....+",
// 		"+-S++|",
// 		"|.|..|",
// 		"..+-++"}
// 		  8
// 		  Returns: 15
	// All of the track segments are reachable except for the two at the North end that seem to be oriented the wrong way.

	layout.clear();
	layout.push_back("-....-");
	layout.push_back("|....+");
	layout.push_back("+-S++|");
	layout.push_back("|.|..|");
	layout.push_back("..+-++");
	fuel = 8;
	count = reachableSquares(layout, fuel);

	if(count == 15)
	{
		std::cout << "Test case 2 Success" << std::endl;
	}
	else
	{
	
		std::cout << "Test case 2 failed: expected: " << 15 << "; actual: " << count << std::endl;	
		
	}

	//Testcase 3
// 		"..+-+.",
// 		"..|.|.",
// 		"S-+-+."}
// 10
// Returns: 10
// 		All 9 of the track segments are reachable, plus 1 for the 'S' square. Be sure not to count squares twice!
	layout.clear();
	layout.push_back("..+-+.");
	layout.push_back("..|.|.");
	layout.push_back("S-+-+.");
	fuel = 10;
	count = reachableSquares(layout, fuel);
	if(count == 10)
	{
		std::cout << "Test case 3 Success" << std::endl;
	}
	else
	{
	
		std::cout << "Test case 3 failed: expected: " << 10 << "; actual: " << count << std::endl;		
	}

	//TestCase 4
// 		".|...",
// 		"-+S+|",
// 		".|..."}
// 5
// Returns: 6
// 			The track segment on the far East side is not reachable - as you can't enter a North-South segment from the West.

	layout.clear();
	layout.push_back(".|...");
	layout.push_back("-+S+|");
	layout.push_back(".|...");
	fuel = 5;
	count = reachableSquares(layout, fuel);
	if(count == 6)
	{
		std::cout << "Test case 4 Success" << std::endl;
	}
	else
	{
		std::cout << "Test case 4 failed: expected: " << 6 << "; actual: " << count << std::endl;		
	}



}
int Trainyard::reachableSquares(std::vector<string> layout, int fuel)
{
	int startRow, startCol;
	getStart(layout, startRow, startCol);
    m_iSquare = 0;
	int rowsize = layout.size();
	int colsize = layout[0].length();
	m_rowSize = rowsize;
	m_colSize = colsize;

	bool** visited = new bool*[rowsize];

	for(int i=0; i<rowsize; i++)
	{
		visited[i] = new bool[colsize];
	}

	int j, k;
	for(j=0; j < rowsize; j++)
		for(k=0; k<colsize; k++)
		{
			
			visited[j][k] = false;
		}

	
	//std::vector<std::vector<bitset>> vis(rowsize, std::vector<bitset>(colsize, 0));
	backtrack(layout, fuel, visited, startRow, startCol, 0);


	int count = 0;
	for(j=0; j < rowsize; j++)
		for(k=0; k<colsize; k++)
		{
			if(visited[j][k])
			{
			//	std::cout << "(" << j <<"," << k <<")" << ";";
				count++;
			}		
		}
	//	std::cout << std::endl;

		return count;

	
//	return count;
	
}

void Trainyard::backtrack(std::vector<string>& layout, int fuel,  bool** visited, int row, int col, int numSquare)
{
	visited[row][col] = true;
	m_iSquare++;
	if(row == 3 && col == 2 )
	{
		int j=0;
		j=1;
	}
	if(fuel == 0)
	{		 
		return ;
	}

	std::vector< std::pair<int, int> > vecCan;
	makeCandidates(layout, fuel, visited, row, col, vecCan);
    
	int count = 0;
	std::vector< std::pair<int, int> >::iterator iter = vecCan.begin();
	for(; iter != vecCan.end(); iter++)
	{
		std::pair<int, int> p = *iter;
		int nexrow = p.first;
		int nexcol = p.second;
		backtrack(layout, fuel-1, visited, nexrow, nexcol, numSquare+1);
	}






}


void Trainyard::makeCandidates(std::vector<string>& layout, int fuel,  bool** visited, int row, int col, std::vector< std::pair<int, int> >& vecCan)
{
//	if(layout[row][col] == '-' || layout[row][col] == '+' || layout[row][col] == 'S')
//	{
		col = col -1; //left
		if( col >=0 && 
			(layout[row][col] == '-' || layout[row][col] == '+')&& 
			!visited[row][col])
		{
			vecCan.push_back(std::pair<int, int>(row, col));
		}
		
		col = col +2; //right
		if(col < m_colSize)
		{
			if((layout[row][col] == '-' || layout[row][col] == '+')&& 
				!visited[row][col]	)
			{
				vecCan.push_back(std::pair<int, int>(row, col));				
			}
		}

		col = col -1;		
		
//	}

//	 if(layout[row][col] == '|' || layout[row][col] == '+' || layout[row][col] == 'S')
//	{
		//up
		row = row-1;
		if(row >=0 &&
			(layout[row][col] == '|' || layout[row][col] == '+')&& 
			!visited[row][col])
		{
			vecCan.push_back(std::make_pair(row, col));
		}

		//down

		row = row+2;		
		if(row < m_rowSize&&
			(layout[row][col] == '|' || layout[row][col] == '+')&& 
			!visited[row][col])
		{
			vecCan.push_back(std::make_pair(row, col));
		}
		
		row = row -1;
		
//	}
	

}

void Trainyard::getStart(std::vector<string>& layout, int& row, int& col)
{
    row = -1;
    col = -1;
    for(row=0; row < layout.size(); row++)
    {        
		for(col=0; col<layout.size(); col++)
		{
			if(layout[row][col] == 'S')
			{
				return;
			}
			
		}
    }
    
}