// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph_data.h"
#include <sstream>

int main(int argc, char* argv[])
{
    Graph* g = new Graph();
	g->LoadGraphFromFile("edges.txt");
	//g->PrintOut();
	GraphAlg a(g);
	a.MST_Prime();
	//a.SP_Dijkstra();

	printf("Hello World!\n");
	system("pause");
	return 0;
}

