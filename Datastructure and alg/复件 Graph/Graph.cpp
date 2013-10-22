// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph_data.h"
#include <sstream>

int main(int argc, char* argv[])
{
    Graph* g = new Graph();
	for(int i=0; i <6; i++)
	{
		stringstream s;
		s << i;
		string str;
		s >> str;
		
		Vertex* v = new Vertex(str);
		g->AddVertex(v);
		s.str("");
	}
	for(i=0, i< g->GetVertexCount(); i++)
	{
		Vertex* v= g->GetVertex();
	}
	Vertex* v = new Vertex("0");
	g->AddVertex(v);
	g->AddEdge(g->GetVertex("0"), g->GetVertex("1"));
	g->AddEdge(g->GetVertex("0"), g->GetVertex("2"));
	g->AddEdge(g->GetVertex("0"), g->GetVertex("5"));
	//g->AddEdge(g->GetVertex(""))
	printf("Hello World!\n");
	return 0;
}

