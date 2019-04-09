#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto result = unique(word.begin(), word.end());
	word.erase(result, word.end());
}


bool isShorter(const string &s, const string &t)
{
	return s.size() < t.size();
}

int main()
{
	vector<string> word;
	string ch;
	while (cin >> ch&&ch!="end")
		word.push_back(ch);
	elimDups(word);
	stable_sort(word.begin(), word.end(), isShorter);
	for (auto it : word)
		cout << it << " ";
	cout << endl;
	return 0;
}