// Basic algorithm

/*
  Find the highest index i such that s[i] < s[i+1]. If no such index exists, the permutation is the last permutation.
  Find the highest index j > i such that s[j] > s[i]. Such a j must exist, since i+1 is such an index.
  Swap s[i] with s[j].
  Reverse the order of all of the elements after index i till the last element.

*/



#include <bits/stdc++.h>
using namespace std;

string find_next(string word)
{
	int i, j, first, second;

	for(i=0; i<word.size()-1; i++)
	{
		if(word[i] < word[i+1])     
			first = i;
	}

	second = first;

	for(i=first+1; i<word.size(); i++)
	{
		if(word[i] > word[first])
			second = i;
	}

	if(first == second)
		return "-1";
	else
	{
		string ans = "";
		
		char temp;
		temp = word[first];
		word[first] = word[second];
		word[second] = temp;

		for(i=0; i<=first; i++)
			ans += word[i];

		for(i=word.size()-1; i>first; i--)
			ans += word[i];

		return ans;
	}
}

int main()
{
	//vector<string> all_permu;
	freopen("sol.out", "w", stdout);  //writing all solution in a file
	string word = "abcdef";   //word to which we have to find permutations
	//all_permu.push_back(word);
	cout << word << endl;

	while(find_next(word) != "-1")
	{
		word = find_next(word);  // function find next permutation
		//all_permu.push_back(word);
		cout << word << endl;
	}
	
	return 0;
}
