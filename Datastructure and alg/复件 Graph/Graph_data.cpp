#include "stdafx.h"
#include "graph_data.h"


Edge::Edge(Vertex* v1, Vertex* v2):_startVertex(v1), _endVertex(v2)
{
   _weight = 1;
}
Vertex::Vertex(const string& name):_vertexName(name)
{


}
Vertex::~Vertex()
{
// 	set<Edge*>::iterator iter = _adjEdges.begin();
// 	for(; iter != _adjEdges.end(); iter++)
// 	{
// 		delete iter;
// 	}
// 	_adjEdges.clear();

}
void Vertex::AddEdges(Vertex* v)
{
	Edge* edge = new Edge(this, v);
	_adjEdges.insert(edge);
}
// vector<Edge*>::iterator Vertex::createIterator()
// {
//      vector<Edge*>::iterator iter;
// 	 iter = _adjEdges.begin();
// 	 return iter;
// }

// bool Edge::operator ==(const Edge& edge)
// {
// 	return this->GetStartVertex() == edge.GetStartVertex() &&
// 		   this->GetEndVertex() == edge.GetEndVertex();
// 
// }
// 
// bool Vertex::operator ==(const Vertex& v)
// {
// 	return _vertexName == v.GetvertexName();
// }
// EdgeIterator::EdgeIterator(Vertex* vertex):_vertex(vertex)
// {
// 
// }
// bool EdgeIterator::Next()
// {
//   _vertex->
// }
Graph::Graph()
{
    _isDirect = false;
}

void Graph::AddEdge(Vertex* startVertex, Vertex* endVertex)
{
     startVertex->AddEdges(endVertex);
	 if(!_isDirect)
	 endVertex->AddEdges(startVertex);
}
void Graph::AddVertex(Vertex* v)
{
	_vertexList.insert(v);
}
Vertex* Graph::GetVertex(const string& name)
{
	Vertex v(name);
	set<Vertex*, Vertex_Compare>::iterator iter;
	iter =_vertexList.find(&v);	 
	return *iter;  
}
