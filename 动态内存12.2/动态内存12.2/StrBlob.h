#pragma once
#include<vector>
#include<memory>
#include<string>
#include<list>
using namespace std;


class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> li);
	size_type size() { return data->size(); }
	bool emplty() { return data->empty(); }
	void push_back(const string &st);
	void pop_back();
	string &front();
	string &back();
	const string &front() const;
	const string &back() const;

private:
	shared_ptr <vector<string>> data;
	void check(size_type i, const string &msg) const;

};

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> li) : data(make_shared<vector<string>>(li)) {}


void StrBlob::check(size_type i, const string &msg) const
{
	if (i > data->size())
		throw out_of_range(msg);
}

void StrBlob::push_back(const string &st)
{
	data->push_back(st);
}

void StrBlob::pop_back()
{
	data->pop_back();
}

string& StrBlob::front()
{
	check(0, "fornt on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::front() const
{
	check(0, "fornt on empty StrBlob");
	return data->front();
}
const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}


