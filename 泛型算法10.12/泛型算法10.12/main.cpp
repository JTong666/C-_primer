#include<vector>
#include<string>
#include<algorithm>
#include"Sales_data.h"
#include<iostream>
using namespace std;




bool compareIsbn( Sales_data &s, Sales_data &t)
{
	return s.isbn().size() < t.isbn().size();
}




int main()
{
	Sales_data d1("a"), d2("aaxx"), d3("csad"), d4("aaxx");
	vector<Sales_data> v{ d1,d2,d3,d4 };
	sort(v.begin(),v.end(),compareIsbn);

	for (auto it : v)
		cout << it.bookNo << " ";
	cout << endl;
	return 0;
}