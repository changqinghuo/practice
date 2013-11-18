#include <vector>
#include <iostream>

using namespace std;



class Permulation{

public:
	Permulation(vector<int> data);
	void Run();
	void backtrack(vector<int>& ary, int current, int length);
	void ConstuctCandidates(vector<int>& ary, int current, int length, vector<int>& candidates);
	bool IsSolution(vector<int>& ary, int current, int length);
	void PrintSolution(vector<int>& ary);
private:
	void print(int i)
	{
			std::cout << m_data[i] << " ";
	}
	vector<int> m_data;
	struct output{
		void operator()(int i)
		{
			std::cout << i << " ";
		}
	}outobj;

	class Candfunc{
	public:
		Candfunc(int index, vector<int>& data){
			m_index = index;
			m_data = data;
		}
		bool operator ()(int i)
		{
			return m_data[i] == m_data[m_index];
		}
	private:
		int m_index;
		vector<int> m_data;
		
	};

	
};