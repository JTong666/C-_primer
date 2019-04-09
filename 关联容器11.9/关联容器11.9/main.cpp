#include<stdio.h>
#include<map>
#include<string>
#include<list>
#include<utility>
#include<vector>
#include<iostream>

using namespace std;


list<int> lists{ 12, 564, 64981, 3218941, 312184,331 };
map<string, list<int>> maps;

/*int main()
{
	vector<pair<string, int>> pairs;
	string st;
	int i;
	while (cin >> st >> i)
	{
		pairs.push_back(pair<string, int>(st, i));
	}

	for (auto &i : pairs)
		cout << i.first << " " << i.second << endl;
	return 0;

}*/



map<string, vector<pair<string, int>> maps;



class Families
{
public:
	using child = pair<string, string>;
	using children = vector<child>;
	using Data = map<string, children>;


	void add(string const &families_name, string const& name, string birthday)
	{
		auto child = pair<string, string>(name, birthday);
		_data[families_name].push_back(child);
	}
	void print()
	{
		for (auto &it : _data)
		{
			cout << it.first << " ";
			for (auto &its : it.second)
				cout << its.first << " " << its.second;
			cout << endl;
		}
	}
private:
	Data _data;


};

int main()
{
	Families families;
	auto msg = "Please enter last name, first name and birthday:\n";
	for (string l, f, b; cout << msg, cin >> l >> f >> b; families.add(l, f, b));
	families.print();

	return 0;
}