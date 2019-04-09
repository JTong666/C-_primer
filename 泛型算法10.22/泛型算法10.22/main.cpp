#include<stdio.h>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>
#include<iostream>
using namespace std;




bool check_size(vector<string> &s, vector<string>::size_type sz)
{
	return s.size() > sz;
}


void number_size(vector<string> &word, vector<string>::size_type sz)
{
	auto result = find_if(word.begin(), word.end(), bind(check_size, placeholders::_1, sz));
	cout << result;
}