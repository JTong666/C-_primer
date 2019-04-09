#include"Employee.h"
#include<iostream>
using namespace std;



int main()
{
	HasPtr p("jiaotong");
	HasPtr p2("TTT");
	HasPtr p3 = p;
	p3.print(p2);
	return 0;
}