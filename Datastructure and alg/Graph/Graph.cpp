// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph_data.h"
#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
    Graph* g = new Graph();
	g->LoadGraphFromFile("cycle_undirected.txt");
	//g->PrintOut();
	GraphAlg a(g);
	std::cout << "the graph has cycle: " << a.IsCyclic_unDirected(g) << std::endl;
	//a.SP_Dijkstra();

	printf("Hello World!\n");
	system("pause");
	return 0;
}

