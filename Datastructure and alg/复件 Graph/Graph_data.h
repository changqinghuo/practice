#ifndef GRAPH_H
#define GRAPH_H
#include <iostream.h>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include "public.h"

using namespace std;
class Edge_Compare;
class Vertex_Compare;
class Vertex;
class GraphElement{};
// class Iterator
// {
// public:
// 	virtual bool HasNext();
// 	virtual GraphElement* Next();	
// };
// class EdgeIterator:public Iterator{
// public:
//     EdgeIterator(Vertex* vertex);
// 	virtual bool HasNext();
// 	virtual GraphElement* Next();
// private:
// 	Vertex* _vertex;
// };

class Edge:public GraphElement{
public:
	Edge(Vertex* v1, Vertex* v2);
	void SetWeight(float& weight) {_weight = weight;};
	float GetWeight() const{return _weight;};
	Vertex* GetStartVertex() const { return _startVertex;};
	Vertex* GetEndVertex() const {return _endVertex;};	
// 	bool operator <(const Edge &edge) const {return _weight < edge.GetWeight();};
// 	bool operator <(const Edge* edge) const {return _weight < edge->GetWeight();};
	friend class Edge_Compare;
private:
	Vertex* _startVertex;
	Vertex* _endVertex;
	float   _weight;
	
};
class Vertex:public GraphElement{
public:
	Vertex(const string& name);
	~Vertex();
	string GetvertexName() const{return _vertexName;};
	void AddEdges(Vertex* v);
	friend class Vertex_Compare;
// 	bool operator <(const Vertex &vertex) const {return _vertexName.compare(vertex.GetvertexName()) < 0 ;};
// 	bool operator <(const Vertex* vertex) const {return _vertexName.compare(vertex->GetvertexName()) < 0 ;};
    /*vector<Edge*>::iterator createIterator();*/
	/*bool operator == (const Vertex& v);*/
private:
	string _vertexName;	
	struct Edge_Compare:public std::binary_function<Edge* , Edge* , bool>{
	public:
		bool operator()(Edge* e1, Edge* e2) const
		{
			return e1->GetStartVertex() < e2->GetEndVertex() || 
			e1->GetEndVertex() < e2 ->GetEndVertex();
		};
};

    set<Edge*, Edge_Compare> _adjEdges;
//	set<Edge*, Edge_Compare> _adjEdges;
};
class Vertex_Compare:public std::binary_function<Vertex* , Vertex* , bool>{
public:
	bool operator()(Vertex* v1, Vertex * v2) const
	{
		return v1->GetvertexName().compare(v2->GetvertexName()) < 0;
	};
	
};
class Graph{
public:
       Graph();
	   void AddVertex(Vertex* v);
	   void AddEdge(Vertex* startVertex, Vertex* endVertex);
	   int  GetVertexCount(){return _vertexList.size();}
	   Vertex* GetVertex(const string& name);
	   bool SetDirectDiagram(bool isDirect){_isDirect = isDirect;};
	   bool IsDirectedDiagram() {return _isDirect;};
	   Graph* LoadGraphFromFile(string filename);

private:	
	bool  _isDirect;
// 	class Vertex_Compare:public std::binary_function<Vertex* , Vertex* , bool>{
// 	public:
// 		bool operator()(Vertex* v1, Vertex * v2) const
// 		{
//             return v1->GetvertexName().compare(v2->GetvertexName()) < 0;
// 		};
// 		
// };
	std::set<Vertex*, Vertex_Compare> _vertexList;
	

};

#endif