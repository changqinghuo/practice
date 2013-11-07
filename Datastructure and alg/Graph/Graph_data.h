#ifndef GRAPH_H
#define GRAPH_H
#include <iostream.h>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include "public.h"

using namespace std;

class Vertex;
class Edge{
public:
	Edge(Vertex* v1, Vertex* v2);
	void SetWeight(float weight) {m_weight = weight;};
	float GetWeight() const{return m_weight;};
	Vertex* GetStartVertex() const { return m_startVertex;};
	Vertex* GetEndVertex() const {return m_endVertex;};	

private:
	Vertex* m_startVertex;
	Vertex* m_endVertex;
	float   m_weight;
	
};
class Vertex{
public:
	Vertex(const string& name);
	string GetName() const{return m_vertexName;};
	void AddEdges(Edge* e);
	vector<Edge*>& GetAdjEdges() {return m_adjEdges;};
	void SetDistance(float f) {m_distance = f;};
	float GetDistance() {return m_distance;};

	void SetParent(Vertex* v) {m_pParent = v;};
	Vertex* GetParent() {return m_pParent;};

	Edge* GetEdge(Vertex* endvertex);

private:
	string m_vertexName;	
	float  m_distance;
	vector<Edge*> m_adjEdges;
	Vertex* m_pParent;
};


class Graph{
public:
       Graph();
	   ~Graph();
	   void AddVertex(Vertex* v);
	   void AddEdge(Edge* e);
       
	   Vertex* GetVertex(string name);
	   Edge* GetEdge(Vertex* startVertex, Vertex* endVertex);
	   
	   int  GetVertexCount(){return m_vertexList.size();};

	   vector<Vertex*> GetVertexList() {return m_vertexList;};
	   vector<Edge*> GetEdgeList() {return m_edgeList;};
	   void LoadGraphFromFile(string filename);
	   void PrintOut();

private:	

	std::vector<Vertex*> m_vertexList;
	std::vector<Edge*>   m_edgeList;
};

class GraphAlg{
public:
	GraphAlg(Graph* g);
	void MST_Prime();
	void MST_Kruskal();
	void SP_Dijkstra();
	void SP_BF();
    //maxnetorkflow
	int MaxNetworkFLow();
	bool MNF_BFS(Graph* rGraph, Vertex* s, Vertex* t);

private:
	Graph* m_pGraph;
};

#endif