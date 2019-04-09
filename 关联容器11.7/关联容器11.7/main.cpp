#include<stdio.h>
#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;



void home()
{
	map<string, vector<string>> map1;
	string c;
	for (c;cin >> c;)
		for (string ch; cin >> ch;)
			map1[c].push_back(ch);

}


