#include<new>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<memory>
#include<Windows.h>

using namespace std;


/*vector<int> *creat()
{
	return new vector<int>();
}

void input(vector<int>* vc)
{
	int i;
	while (cin >> i&&i!=0)
		vc->push_back(i);
}

void output(vector<int>* gc)
{
	for (auto it : *gc)
		cout << it << " ";
}

int main()
{
	vector<int>* p = creat();
	input(p);
	output(p);
	delete p;
	Sleep(1000);
	return 0;
}*/



shared_ptr<vector<int>> creat()
{
	return make_shared<vector<int>>();
}


void input(shared_ptr<vector<int>> p)
{
	int i;
	while (cin >> i)
		p->push_back(i);
}


void output(shared_ptr<vector<int>> p)
{
	for (auto it : *p)
		cout << it << " ";
}

int main()
{
	shared_ptr<vector<int>> p = creat();
	input(p);
	output(p);
	return 0;
}