#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;



void emDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto result = unique(word.begin(), word.end());
	word.erase(result, word.end());
}


void ch(vector<string> &word,vector<string>::size_type sz)
{
	emDups(word);
	auto t = count_if(word.begin(), word.end(), [sz](const string &s) {return s.size() > sz; });
	cout << t;
}



