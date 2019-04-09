#include<stdio.h>
#include<string>
#include<deque>
#include<iostream>
#include<list>
#include<Windows.h>
using namespace std;



/*int main()
{
	deque<string> lists;
	for (string str; cin >> str; lists.push_back(str))
		for (auto it = lists.cbegin(); it != lists.cend(); it++)
			cout << *it << endl;
	return 0;
}
*/


int main()
{
	list<int> lists;
	deque<int> deque1,deque2;

	for(int i;cin>>i&&i!=0;lists.push_back(i))
		for (auto it = lists.cbegin(); it != lists.cend(); it++)
		{
			if (*it % 2 == 0)
				deque1.push_back(*it);
			else
				deque2.push_back(*it);
		}
	for (auto it = deque1.cbegin(); it != deque1.cend(); it++)
		cout << *it;
	cout << endl;
	for (auto it = deque2.cbegin(); it != deque2.cend(); it++)
		cout << *it;
	Sleep(10000);
	return 0;
}
