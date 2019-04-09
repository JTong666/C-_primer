#include<memory>
#include<string>
#include<list>
#include<iostream>
using namespace std;


class StrVec
{
	friend bool operator==(const StrVec &, const StrVec &);
	friend bool operator!=(const StrVec &, const StrVec &);
	friend ostream& operator<<(ostream &, const StrVec &);
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec &);
	StrVec &operator=(const StrVec &);
	StrVec(initializer_list<string>);
	~StrVec();
	string& operator[](const size_t);
	const string& operator[](const size_t) const;
	size_t size()const { return first_free - elements; }
	size_t capacity() const{ return cap - elements; }
	void push_back(const string &);
	string *begin() const{ return elements; }
	string *end() const{ return first_free; }
private:
	static allocator<string> alloc;
	pair<string *, string *> alloc_n_copy(const string*, const string*);
	void reallocate();
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	string *elements;
	string *first_free;
	string *cap;
	void free();
};


void StrVec::push_back(const string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string *, string *>
StrVec::alloc_n_copy(const string *it1, const string *it2)
{
	auto p = alloc.allocate(it2 - it1);
	return{ p, uninitialized_copy(it1,it2,p) };
}
void StrVec::free()
{
	if (elements)
	{
		for (auto it = first_free; it != first_free; it--)//ÄæÐòÏú»Ù  Ææ¹ÖµÄÒªÇó£¡£¡£¡£¡£¡£¡£¡
			alloc.destroy(it);
		alloc.deallocate(elements, cap - elements);
	}

}


StrVec::StrVec(const StrVec &p)
{
	auto newdata = alloc_n_copy(p.begin(), p.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec &ph)
{
	auto newdata = alloc_n_copy(ph.begin(), ph.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

void StrVec::reallocate()
{
	
	size_t newsize = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newsize);
	auto newelem = newdata;
	auto set = elements;
	for (size_t i = 0; i < size(); i++)
		alloc.construct(newelem, std::move(*set++));
	free();
	elements = newdata;
	first_free = set;
	cap = elements + size();
}
StrVec::~StrVec()
{
	free();
}
StrVec::StrVec(initializer_list<string> li)
{
	auto p = alloc_n_copy(li.begin(), li.end());
	elements = p.first;
	first_free = cap = p.second;
}


bool operator==(const StrVec &ph1, const StrVec &ph2)
{
	for (auto it1 = ph1.elements, it2 = ph2.elements; it1 != ph1.first_free&&it2 != ph2.first_free; it1++, it2++)
		if (*it1 == *it2)
			;
		else
			return false;
	return true;
}

bool operator!=(const StrVec &ph1, const StrVec &ph2)
{
	return !(ph1 == ph2);
}

string &StrVec::operator[](const size_t i)
{
	return (elements[i]);
}
const string &StrVec::operator[](const size_t i) const
{
	return (elements[i]);
}