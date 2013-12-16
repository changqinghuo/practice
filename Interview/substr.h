#include <iostream>
#include <vector>
#include "global.h"

using namespace std;

class SubStr: public Interview
{
public:
	void Run();
	void NaiveSubStr(string pattern, string text);
	void KMPSubStr(string pattern, string text);
	void HashSubStr(string pattern, string text);
	void WildcardSubStr(string pattern, string text);
private:
	 vector<int> ComputeOverlay(const string& pattern);

};