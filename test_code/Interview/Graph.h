#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

class Graph{
public:
	Graph();
	void Run();
	void MST_Prime();
	void MST_Kruskal();
	void Shortest_Bellman();
	void Shortest_Dijkstra();

private:
	vector< vector<int> > m_graph;


}
;













#endif