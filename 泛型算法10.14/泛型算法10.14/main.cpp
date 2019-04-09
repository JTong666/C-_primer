#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;


/*int main()
{

	auto f =[](int i, int j){return i + j; };

	return 0;
}*/


//int i = 10;
//auto f = [i](int j) {return i + j; };


void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto result = unique(word.begin(), word.end());
	word.erase(result, word.end());
}
bool isshort(const string &s, const string &t)
{
	return s.size() < t.size();
}
void biggies(vector<string> &word, vector<string>::size_type sz)
{
	int i = 0;
	elimDups(word);
	stable_sort(word.begin(), word.end(), isshort);
	auto result = find_if(word.begin(), word.end(), [sz](const string &s) { return s.size() > sz; });
	//auto result = partition(word.begin(), word.end(),[sz](const vector<string> &s){return s.size()<sz;});
	for (auto it = result; it != word.end; it++)
		i++;
	cout << "number:" << i;
	for_each(result, word.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}