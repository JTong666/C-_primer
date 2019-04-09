#include<string>
#include<memory>
#include<iostream>
#include<Windows.h>

using namespace std;
class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &t) :ps(new string(*t.ps)), i(t.i) {}
	HasPtr& operator = (const HasPtr& hw)
	{
		string *p = new string(*hw.ps);
		i = hw.i;
		delete ps;
		return *this;
	}
private:
	string *ps;
	int i;
};

class numbered
{

public:
	numbered() = default;
	//numbered(const numbered &p) :it(2) {}
	int it = 1;
};

void f(numbered s)
{
	cout << s.it << endl;
}

int main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	Sleep(1000);
	return 0;
}