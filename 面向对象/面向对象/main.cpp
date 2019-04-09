#include<string>
#include"Quote.h"
#include<iostream>
using namespace std;


int main()
{
	Quote q1("994144293", 20);
	Quote q2();
	Quote q3("jiaootng", 50);
	Blk_quote b1();
	Blk_quote b2("tontont", 60, 0.2, 30);
	print_total(cout,q1, 20);
	print_total(cout, b2, 40);
	return 0;
}