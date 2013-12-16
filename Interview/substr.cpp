#include "stdafx.h"

#include "substr.h"


void SubStr::Run()
{
	string pattern = "AABA";
	string text = "AABAACAADAABAAABAA";
	KMPSubStr(pattern, text);


}

void SubStr::NaiveSubStr(string pattern, string text)
{
	
	for(int i=0; i<text.length(); i++)
	{
		int currindex = i;
		int j = 0;
		while(j < pattern.length() && currindex < text.length() && pattern[j] == text[currindex])
		{
			currindex++;
			j++;
		}

		if( j == pattern.length())
		{
			cout << "pattern found at index: " << i << std::endl;
		}
	}

}

vector<int> SubStr::ComputeOverlay(const string& pattern)
{
	vector<int> overlay_value = vector<int>(pattern.length());	
	overlay_value[0] = -1;
	for(int i = 1; i<pattern.length(); i++)
	{
		int index = overlay_value[i-1];
		while(index >= 0 && pattern[i] != pattern[index+1])
		{
			index = overlay_value[index];				
		}

		if(pattern[i] == pattern[index+1])
		{
			overlay_value[i] = index + 1;
		}
		else
		{
			overlay_value[i] = -1;
		}	
	}

	return overlay_value;
}

void SubStr::KMPSubStr(string pattern, string text)
{
	vector<int> overlay_value = ComputeOverlay(pattern);
	int pattern_index = 0;
	for(int i=0; i < text.length(); )
	{
	
		if(text[i] == pattern[pattern_index])
		{
			i++;
			pattern_index++;
		}
		else if(pattern_index == 0)
		{	
			i++;
		}
		else
		{
			pattern_index = overlay_value[pattern_index-1] + 1;
		}	
		
		if(pattern_index == pattern.length())
		{
			std::cout << i-pattern_index << std::endl;
			pattern_index = overlay_value[pattern_index -1] + 1;			
		}
		
	}
}