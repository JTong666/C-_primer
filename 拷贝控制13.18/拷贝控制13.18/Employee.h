#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;


/*class Employee
{
public:
	Employee() { i++; number = i; }
	Employee(const string &names) :name(name) { i++; number = i; }
private:
	static int i;
	string name;
	int number;

};
int Employee::i = 0;
*/



class HasPtr
{
public:
	HasPtr(const string &s) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &p) :ps(new string(*p.ps)), i(p.i) {}
	//HasPtr operator=(const HasPtr &);
	~HasPtr() { delete ps; }
	void print(const HasPtr &p) { cout<<*p.ps; }
private:
	string *ps;
	int i;
};


