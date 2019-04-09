#pragma once
#include<vector>
#include<memory>
#include<string>
#include<list>
using namespace std;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	StrBlobPtr begin();
	StrBlobPtr end();
	typedef vector<string>::size_type size_type;
	StrBlob()=default;
	StrBlob(initializer_list<vector<string>> li) :data(make_shared<vector<string>>(li)) {}
	StrBlob(const StrBlob &p) :data(make_shared<vector<string>>(*p.data)) {}
	StrBlob operator=(const StrBlob &);
	size_type size() { return data->size(); }
	bool empty() { return data->empty; }
	void push(string& i) { data->push_back(i); }
	void pop() { data->pop_back(); }
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const
	{ 
		if (i > data->size())
			throw out_of_range(msg);
	}
};

class StrBlobPtr
{
public:
	StrBlobPtr &operator++();
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string& deref() const;
	StrBlobPtr& incr();

private:
	weak_ptr<vector<string>> wptr;
	shared_ptr<vector<string>> check(size_t i, const string& msg) const;
	size_t curr;
};
shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	auto it = wptr.lock();
	if (!it)
		throw runtime_error("............");
	if (i > it->size())
		throw out_of_range(msg);
	return it;
}
string& StrBlobPtr::deref() const
{
	auto t = check(curr, "...........");
	return (*t)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

StrBlob StrBlob::operator=(const StrBlob &ph)
{
	auto newptr = make_shared<vector<string>>(*ph.data);
	data = newptr;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "       ");
	curr++;
	return *this;
}
