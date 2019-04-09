//#include<string>
//using namespace std;


/*class HasPtr
{
private:
	HasPtr();
	HasPtr(const string &li) :ps(new string(li)), use(new size_t(1)), i(0) {}
	HasPtr(const HasPtr &p) :ps(new string(*p.ps)), use(new size_t(*p.use)), i(p.i) { *++use; }
	HasPtr& operator=(const HasPtr &);
	~HasPtr();
private:
	string *ps;
	size_t *use;
	int i;
};
HasPtr& HasPtr::operator=(const HasPtr &pw)
{
	++*pw.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	ps = pw.ps;
	use = pw.use;
	i = pw.i;
	return *this;
}
HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}*/



