#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
/*int main()
{
	vector<int> list;
	int i, j;
	while (cin >> i&&i!=0)
		list.push_back(i);
	cin >> j;
	auto result = count(list.cbegin(), list.cend(), j);
	cout << (result == 0 ? "NO" : "YES") <<endl<<result;
}*/


/*int main()
{ 
	vector<int> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	fill_n(list.cbegin(), list.size(), 0);
	for (auto it = list.cbegin(); it != list.cend(); it++)
		cout << *it << endl;

	return 0;
}*/


void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto result = unique(word.begin(), word.end());
	word.erase(result, word.end());
}



int main()
{
	vector<string> word;
	for (string i; cin >> i&&i!="end"; word.push_back(i))
		;
	elimDups(word);
	for (auto it : word)
		cout << it << " ";
	cout << endl;
	return 0;
}