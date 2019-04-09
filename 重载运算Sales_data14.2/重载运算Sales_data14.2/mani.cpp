#include"Sales_data.h"
#include<iostream>

using namespace std;


int main()
{
	Sales_data s1;
	Sales_data s2("JTong", 10, 2.5);
	Sales_data s3("TT", 20, 5.5);
	s1 += s2;
	cout << s1;
	Sales_data s4;
	cin >> s4;
	cout << s4;
	Sales_data s5;
	s5 = s3;
	cout << s5;
	return 0;
}