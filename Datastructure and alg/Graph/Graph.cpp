// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph_data.h"
#include <sstream>
#include <iostream>

int main(int argc, char* argv[])
{
    Graph* g = new Graph();
	g->LoadGraphFromFile("MaxNetworkFlow_edges.txt");
	//g->PrintOut();
	GraphAlg a(g);
	std::cout << a.MaxNetworkFLow() << std::endl;
	//a.SP_Dijkstra();

	printf("Hello World!\n");
	system("pause");
	return 0;
}

