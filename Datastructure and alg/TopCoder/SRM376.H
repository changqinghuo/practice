
/*

  Problem Statement
  ????
  You've been given the blueprint for a trainyard which was laid out on a grid. 
  Some grid cells have East-West track segments (marked with '-'), some have North-South track segments (marked with '|'),
  and others are intersections (marked with '+'). 
  Cells with no track are marked with a '.' character. A train may enter an intersection square from any direction and may leave in any direction. T
  rains may enter a North-South track segment from either the North or South, 
  and must exit the square moving in the same direction. 
  Thus if a train enters a North-South segment from the South, it must leave to the North.
  East-West tracks work the same way, except with directions East and West. 
  Squares without track may not be entered, and the train may not leave the area covered by the grid. 
  The train always occupies a single grid location, and each square moved requires one unit of fuel.
  ?
  The train's starting location is marked on the map with an 'S' character. Trains may exit this location going any direction. Given the trainyard map in layout and the fuel available in fuel, you want to determine how many grid squares may be reached. You do not need to construct one route that reaches all these squares; rather, you are determining which squares could be reached using any legal route beginning at the 'S' location. A legal route may use some, all, or none of the fuel. Return the number of distinct grid squares that can be reached, including the initial 'S' location.
  Definition
  ????
  Class:
  Trainyard
  Method:
  reachableSquares
  Parameters:
  vector <string>, int
  Returns:
  int
  Method signature:
  int reachableSquares(vector <string> layout, int fuel)
  (be sure your method is public)
  ????
  
	Constraints
	-
	layout will contain between 1 and 10 elements, inclusive.
	-
	Each element of layout will contain between 1 and 10 characters, inclusive.
	-
	Each element of layout will contain the same number of characters.
	-
	Each element of layout will contain only the characters '-','|','+','.', and 'S'.
	-
	layout will contain exactly one 'S' character.
	-
	fuel will be between 1 and 10, inclusive.
	Examples
	0)
	
	  ????
	  {
	  ".-....",
	  "-S---.",
	  "......"}
	  2
	  Returns: 4
	  The train can reach the initial 'S', as well as one square to the West. It could also reach two squares to the East (but not the third, as there's only 2 units of fuel). It can't move North to start, as it can't enter an East-West segment from the South.
	  1)
	  
		????
		{
		"..+-+.",
		"..|.|.",
		"S-+-+."}
		10
		Returns: 10
		All 9 of the track segments are reachable, plus 1 for the 'S' square. Be sure not to count squares twice!
		2)
		
		  ????
		  {
		  "-....-",
		  "|....+",
		  "+-S++|",
		  "|.|..|",
		  "..+-++"}
		  8
		  Returns: 15
		  All of the track segments are reachable except for the two at the North end that seem to be oriented the wrong way.
		  3)
		  
			????
			{
			".|...",
			"-+S+|",
			".|..."}
			5
			Returns: 6
			The track segment on the far East side is not reachable - as you can't enter a North-South segment from the West.
This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Trainyard
{
public:
	int reachableSquares(std::vector<string> layout, int fuel);
	void Test();
private:
    void getStart(std::vector<string>& layout, int& row, int& col);
	void makeCandidates(std::vector<string>& layout, int fuel,  bool** visited, int row, int col, std::vector< std::pair<int, int> >& vecCan);
	void backtrack(std::vector<string>& layout, int fuel,  bool** visited, int row, int col, int numSquare);
	int m_iSquare;
	int m_rowSize;
	int m_colSize;
};
