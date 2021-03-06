#include "stdafx.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm> 
#include <queue>
#include <stack>
#include "graph_data.h"

#define MAX_VAL  999999 

Edge::Edge(Vertex* start, Vertex* end):m_startVertex(start), m_endVertex(end)
{
   m_weight = 1;
   
}
Vertex::Vertex(const string& name):m_vertexName(name)
{
   m_distance = 0;
   m_pParent = NULL;
   m_bVisted = false;
}

void Vertex::AddEdges(Edge* e)
{	
	m_adjEdges.push_back(e);
}

Edge* Vertex::GetEdge(Vertex* endvertex)
{
	vector<Edge*>::iterator iter;
	for(iter = m_adjEdges.begin(); iter != m_adjEdges.end(); iter++)
	{
		Edge* e = *iter;
		if(e->GetEndVertex() == endvertex)
		{
			return e;
		}
	}

	return NULL;

}

Graph::Graph()
{
    
}

Graph::~Graph()
{
	for(int i = 0; i < m_edgeList.size(); i++)
	{
		Edge* e = m_edgeList[i];
		delete e;
	}
	m_edgeList.clear();

	for(int j=0; j < m_vertexList.size(); j++)
	{
		Vertex* v = m_vertexList[j];
		delete v;
	}
	m_vertexList.clear();
}

void Graph::AddEdge(Edge* e)
{
    m_edgeList.push_back(e); 
}

Edge* Graph::GetEdge(Vertex* startVertex, Vertex* endVertex)
{
	vector<Edge*>::iterator iter;
	for(iter=m_edgeList.begin(); iter != m_edgeList.end(); iter++)
	{
		Edge* e = *iter;
		if(e->GetStartVertex() == startVertex && e->GetEndVertex() == endVertex)
		{
			return e;
		}
	}
	return NULL;

}

void Graph::AddVertex(Vertex* v)
{
	m_vertexList.push_back(v);
}
Vertex* Graph::GetVertex(string name)
{
	Vertex* ret = NULL;

    vector<Vertex*>::iterator iter = std::find_if(m_vertexList.begin(), m_vertexList.end(), VertexEqual(name));
	if (iter!= m_vertexList.end())
	{
		return *iter;
	}

	return ret;
}

void Graph::LoadGraphFromFile(string filename)
{
	ifstream file(filename.c_str());
	string line;
	while(getline(file, line))
	{
		string start, end;
		float weight = 0;
		unsigned pos1 = line.find(" ");
		start = line.substr(0, pos1);
		unsigned pos2 = pos1 + line.substr(pos1+1).find(" ");
		end = line.substr(pos1+1, pos2-pos1);		
		weight = atof(line.substr(pos2+1).c_str());

	    Vertex* vstart = GetVertex(start);
		Vertex* vend = GetVertex(end);

		if(vstart == NULL)
		{
			vstart = new Vertex(start);
			m_vertexList.push_back(vstart);
		}
		if(vend == NULL)
		{
			vend = new Vertex(end);
			m_vertexList.push_back(vend);
		}

		Edge* e = new Edge(vstart, vend);
		e->SetWeight(weight);
		m_edgeList.push_back(e);
		vstart->AddEdges(e);
	}

}

void Graph::PrintOut()
{
	for(int i = 0; i <m_vertexList.size(); i++)
	{
		Vertex* v = m_vertexList[i];
		std::cout << v->GetName() << ":";
		vector<Edge*> adj = v->GetAdjEdges();
		for(int j =0; j < adj.size(); j++)
		{
			Edge* e = adj[j];
			std::cout << e->GetEndVertex()->GetName() << ",";
		}
		std::cout << std::endl;

	}
}


//////////////////Grap Algorithm////////////////////////////
GraphAlg::GraphAlg(Graph* g)
{
	m_pGraph = g;
}

struct cmp
{
		operator() (Vertex* v1, Vertex* v2)
		{
			return v1->GetDistance() > v2->GetDistance();
		}
};
bool vertex_cmp(Vertex* v1, Vertex* v2)
{
	return v1->GetDistance() > v2->GetDistance();
}
void GraphAlg::MST_Prime()
{
	//Initialize Vertexes
//	std::priority_queue<Vertex*, vector<Vertex*>, cmp> Q;
	vector<Vertex*> vertexes = m_pGraph->GetVertexList();
	

	Vertex* root = vertexes[0];
	root->SetDistance(0);
	root->SetParent(NULL);
//	Q.push(root);
	for(int i = 1; i< vertexes.size(); i++)
	{
		Vertex* v = vertexes[i];
		v->SetDistance(MAX_VAL);
		v->SetParent(NULL);
	//	Q.push(v);
	}

	
	make_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
	vector<Vertex*>::iterator  iter = NULL;
	double MSTcost = 0;
	while(!vertexes.empty())
	{
		Vertex* u = vertexes.front();
		MSTcost += u->GetDistance();
		pop_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
		vertexes.pop_back();
		vector<Edge*> edges = u->GetAdjEdges();
		for(int i = 0; i < edges.size(); i++)
		{
			Edge* e = edges[i];
			Vertex* endvertex = e->GetEndVertex();
			iter = find(vertexes.begin(), vertexes.end(), endvertex);
			if(iter != NULL && e->GetWeight() < endvertex->GetDistance())
			{
				endvertex->SetParent(u);
				endvertex->SetDistance(e->GetWeight());
				make_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
			}			
		}
	
	}
    
	std::cout << "MST cost: " << MSTcost << std::endl;
	//std::make_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
	//Vertex* top = pop_heap()	
}

void GraphAlg::MST_Kruskal()
{

}

void GraphAlg::SP_Dijkstra()
{

	vector<Vertex*> vertexes = m_pGraph->GetVertexList();
	

	Vertex* root = vertexes[0];
	root->SetDistance(0);
	root->SetParent(NULL);

	for(int i = 1; i< vertexes.size(); i++)
	{
		Vertex* v = vertexes[i];
		v->SetDistance(MAX_VAL);
		v->SetParent(NULL);
	}

	
	make_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
	vector<Vertex*>::iterator  iter = NULL;
	double MSTcost = 0;
	while(!vertexes.empty())
	{
		Vertex* u = vertexes.front();
		MSTcost += u->GetDistance();
		pop_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
		vertexes.pop_back();
		vector<Edge*> edges = u->GetAdjEdges();
		for(int i = 0; i < edges.size(); i++)
		{
			Edge* e = edges[i];
			Vertex* endvertex = e->GetEndVertex();
			iter = find(vertexes.begin(), vertexes.end(), endvertex);
			if((e->GetWeight() + u->GetDistance()) < endvertex->GetDistance())
			{
				endvertex->SetParent(u);
				endvertex->SetDistance(e->GetWeight() + u->GetDistance());
				make_heap(vertexes.begin(), vertexes.end(), vertex_cmp);
			}			
		}
		
	}
    
	vector<Vertex*>  SP_vertex = m_pGraph->GetVertexList();
	for(iter = SP_vertex.begin(); iter != SP_vertex.end(); iter++ )
	{
		Vertex* v = *iter;
		std::cout <<  v->GetName() << ": " << v->GetDistance() <<  std::endl;

	}	

}

int GraphAlg::MaxNetworkFLow()
{
	
	Vertex* s = m_pGraph->GetVertex("0");
	Vertex* t = m_pGraph->GetVertex("5");
	float maxflow = 0;

	while(MNF_BFS(m_pGraph, s, t))
	{
		Vertex* dest = t;
		float pathflow = 99999;
		while(dest != s)
		{
			Vertex* parent = dest->GetParent();
			Edge* e = parent->GetEdge(dest);			
			pathflow = pathflow > e->GetWeight() ? e->GetWeight(): pathflow;
			dest = parent;
		}

		//update residual graph weight
		dest = t;
		while(dest != s)
		{
			Vertex* parent = dest->GetParent();
			Edge* e = parent->GetEdge(dest);

			////////////need back edge? why
			e->SetWeight(e->GetWeight() - pathflow);
			//�����
			//
			dest = parent;
		}
		maxflow += pathflow;
	}

	return maxflow;

}

bool GraphAlg::MNF_BFS(Graph* rGraph, Vertex* s, Vertex* t)
{
	vector<Vertex*> vertexlist = rGraph->GetVertexList();
	vector<Vertex*>::iterator iter = vertexlist.begin();
	for(; iter != vertexlist.end(); iter++)
	{
		Vertex* v = *iter;
		v->SetParent(NULL);
	}

	queue<Vertex*> Q;
	Q.push(s);
	while(!Q.empty())
	{
		Vertex* v = Q.front();
		Q.pop();
		vector<Edge*> edges = v->GetAdjEdges();
		vector<Edge*>::iterator iter;
		for(iter = edges.begin(); iter != edges.end(); iter++)
		{
			Edge* e = *iter;
			Vertex* endvertex = e->GetEndVertex();
			if(endvertex->GetParent() == NULL && e->GetWeight() > 0)
			{
				endvertex->SetParent(v);
				Q.push(e->GetEndVertex());
			}
			
		}
	}
	return t->GetParent() != NULL;

}

// All paht in between s and t
void GraphAlg::RunAllPath()
{
	Vertex* s = m_pGraph->GetVertex("2");
	Vertex* t = m_pGraph->GetVertex("5");
	s->SetVisited(true);
	AllPath(m_pGraph, s, t);
}

void GraphAlg::AllPath(Graph* graph, Vertex* s, Vertex* t)
{

	if(IsSolution(graph, s, t))
	{
		PrintSolution(graph, s, t);
		std::cout << std::endl;
		return;
	}
	vector<Vertex*> vec_can;
	
	ConstructCandidates(graph, s, t, vec_can);
	
	vector<Vertex*>::iterator iter = vec_can.begin();
	for(; iter != vec_can.end(); iter++)
	{
		Vertex* next = *iter;
		next->SetParent(s);
		next->SetVisited(true);
		
		AllPath(graph, next, t);
		next->SetParent(NULL);
		next->SetVisited(false);
	}
}

void GraphAlg::ConstructCandidates(Graph* g, Vertex* s, Vertex*t, vector<Vertex*>& vec_can)
{
	vector<Edge*> adjEdges = s->GetAdjEdges();
	vector<Edge*>::iterator iter = adjEdges.begin();
	for(; iter!=adjEdges.end(); iter++)
	{
		Edge* e = *iter;
		if(e->GetEndVertex()->GetVisited() == false)
		{
			vec_can.push_back(e->GetEndVertex());
		}
		
	}
}


bool GraphAlg::IsSolution(Graph* graph, Vertex* s, Vertex* t)
{
	return s == t;
}

void GraphAlg::PrintSolution(Graph* graph, Vertex* s, Vertex* t)
{
// 	while(t != NULL)
// 	{
// 		std::cout << t->GetName() << " ";
// 		t = t->GetParent();
// 
// 	}
	

	if(t == NULL)
	{		
		return;
	}
    PrintSolution(graph, s, t->GetParent());
	std::cout << t->GetName() << "  ";

}


//DFS
void GraphAlg::DFS(Graph* g)
{
	vector<Vertex*> vertexlist = g->GetVertexList();
	vector<Vertex*>::iterator vertex_iter = vertexlist.begin();
	for(; vertex_iter != vertexlist.end(); vertex_iter++)
	{
		Vertex* u = *vertex_iter;
		if(!u->GetVisited())
		{
			DFSUtil(g, u);
		}
	}

}

void GraphAlg::DFSUtil(Graph* g, Vertex* u)
{
	u->SetVisited(true);
	vector<Edge*> edges = u->GetAdjEdges();
	
	vector<Edge*>::iterator iter = edges.begin();
	for(; iter != edges.end(); iter++)
	{
		Edge* e = *iter;
		Vertex* end = e->GetEndVertex();
		if(!end->GetVisited())
		{
			end->SetParent(u);
			DFSUtil(g, end);
		}
	}
}


// Detect Cycle directed graph
bool GraphAlg::IsCyclic_Directed(Graph* g)
{
	std::set<Vertex*> recursionStack;
	vector<Vertex*> vertexlist = g->GetVertexList();
	vector<Vertex*>::iterator vertex_iter = vertexlist.begin();
	for(; vertex_iter != vertexlist.end(); vertex_iter++)
	{
		recursionStack.clear();
		Vertex* u = *vertex_iter;
		if(!u->GetVisited() && IsCyclic_Directed_Util(g, u, recursionStack))
		{
			return true;			
		}
	}
	return false;
}

bool GraphAlg::IsCyclic_Directed_Util(Graph* g, Vertex* u, set<Vertex*>& recursionStack)
{
	u->SetVisited(true);
	recursionStack.insert(u);
	vector<Edge*> edges = u->GetAdjEdges();
	vector<Edge*>::iterator iter = edges.begin();
	for(; iter!=edges.end(); iter++)
	{
		Edge* e = *iter;
		Vertex* end = e->GetEndVertex();
		if(!end->GetVisited())
		{
			end->SetParent(u);
			if(IsCyclic_Directed_Util(g, end, recursionStack))
			{
				return true;
			}
		}
		else
		{
			if(recursionStack.count(end) > 0)
			{
				return true;
			}
		}
	}
	recursionStack.erase(u);
	return false;	
}

//Cyclic undirected
bool GraphAlg::IsCyclic_unDirected(Graph* g)
{
	std::set<Vertex*> recursionStack;
	vector<Vertex*> vertexlist = g->GetVertexList();
	vector<Vertex*>::iterator vertex_iter = vertexlist.begin();
	for(; vertex_iter != vertexlist.end(); vertex_iter++)	{
		
		Vertex* u = *vertex_iter;
		if(!u->GetVisited() && IsCyclic_unDirected_Util(g, u, NULL))
		{
			return true;			
		}
	}
	return false;
}

bool GraphAlg::IsCyclic_unDirected_Util(Graph* g, Vertex* u, Vertex* parent)
{
	u->SetVisited(true);
	vector<Edge*> edges = u->GetAdjEdges();
	vector<Edge*>::iterator iter = edges.begin();
	for(; iter!=edges.end(); iter++)
	{
		Edge* e = *iter;
		Vertex* end = e->GetEndVertex();
		if(!end->GetVisited())
		{
			end->SetParent(u);
			if(IsCyclic_unDirected_Util(g, end, u))
			{
				return true;
			}
		}
		else
		{
			if(end != parent)
			{
				return true;
			}
		}
	}
	return false;

}