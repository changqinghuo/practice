#include <vector>

using namespace std;

class BackTrack{
public:
	virtual void BTAlg(vector<int>& data, int currindex, int n);
	virtual void ConstructCandidates(vector<int>& data, int currindex, int n, vector<int>& candidates);
	virtual void MakeMove();
	virtual void UnMove();
	virtual bool IsSolution();
	virtual bool Prune();
	virtual void PrintSolution();
};