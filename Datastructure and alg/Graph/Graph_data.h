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
	void SetVisited(bool b) {m_bVisted = b;}
	bool GetVisited() {return m_bVisted;}

private:
	string m_vertexName;	
	float  m_distance;
	vector<Edge*> m_adjEdges;
	Vertex* m_pParent;
	bool m_bVisted;
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
	//Test data: maxnetworkflow.txt
	int MaxNetworkFLow();
	bool MNF_BFS(Graph* rGraph, Vertex* s, Vertex* t);
	///maxnetworkflow end

	//Find all path between s and t, it is backtrack
	//Test data: allpath.txt
	void RunAllPath();
	void AllPath(Graph* graph, Vertex* s, Vertex* t);
	void PrintSolution(Graph* graph, Vertex* s, Vertex* t);
	void ConstructCandidates(Graph* g, Vertex* s, Vertex*t, vector<Vertex*>&  vec_can);
	bool IsSolution(Graph* graph, Vertex* s, Vertex* t);


	//BFS

	//DFS
	void DFS(Graph* g);
	void DFSUtil(Graph* g, Vertex* u);

	 //detect cycle in directed and undirected graph:
	
	//Test data: cycle_directed.txt
	bool IsCyclic_Directed(Graph* g);
	bool IsCyclic_Directed_Util(Graph* g, Vertex* u, set<Vertex*>& recursionStack);

	//Test data: cycle_undirected.txt
	bool IsCyclic_unDirected(Graph* g);
	bool IsCyclic_unDirected_Util(Graph* g, Vertex* u, Vertex* parent);

	// find all the cycle in graph



private:
	Graph* m_pGraph;
};

//function object
class VertexEqual{
public:
	VertexEqual(std::string name):m_Val(name){}
	bool operator()(const Vertex* v) { return v->GetName().compare(m_Val) == 0;} 
private:
	std::string  m_Val;

};

#endif