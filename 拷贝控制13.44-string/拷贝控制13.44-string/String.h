#include<iostream>
#include<memory>

using namespace std;


class String
{
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	friend ostream& operator<<(ostream &, const String &);
public:
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const String &);
	String &operator=(const String &);
	String(const char*);
	~String();
	char &operator[](const size_t);
	const char &operator[](const size_t) const;
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void push_back(const char &);
	char *begin() const { return elements; }
	char *end() const { return first_free; }

private:
	static allocator<char> alloc;
	pair<char *, char *> alloc_n_copy(const char *,const char*);
	void reallocate();
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void free();
	char *elements;
	char *first_free;
	char *cap;
};
pair<char *, char *>
String::alloc_n_copy(const char *it1, const char *it2)
{
	auto p = alloc.allocate(it2 - it1);
	return{ p, uninitialized_copy(it1,it2,p) };
}
void String::push_back(const char &p)
{
	chk_n_alloc();
	alloc.construct(first_free++, p);
}

String::String(const String &p)
{
	auto data = alloc_n_copy(p.begin(), p.end());
	elements = data.first;
	cap = first_free = data.second;

}

void String::free()
{
	if (elements)
	{
		for (auto iter = first_free; iter != elements; iter--)
			alloc.destroy(iter);
		alloc.deallocate(elements, cap - elements);
	}
}
String &String::operator=(const String &ph)
{
	auto newdata = alloc_n_copy(ph.begin(), ph.end());
	free();
	elements = newdata.first;
	cap = first_free = newdata.second;
	return *this;
}
String::~String()
{
	free();
}

String::String(const char* p)
{
	char *newp = const_cast<char*>(p);
	while (*newp)
		newp++;
	auto newdata = alloc_n_copy(p, newp);
	elements = newdata.first;
	cap = first_free = newdata.second;
}


void String::reallocate()
{
	size_t newsize = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newsize);
	auto elem = newdata;
	auto set = elements;
	for (size_t t = 0; t <= size(); t++)
		alloc.construct(elem++, std::move(*set++));
	free();
	elements = newdata;
	first_free = set;
	cap = newdata + newsize;
}

ostream& operator<<(ostream &os, const String &ph)
{
	for (auto it = ph.begin(); it != ph.end(); it++)
		os << *it << " ";
	return os;
}

bool operator==(const String &ph1, const String &ph2)
{
	for (auto it1 = ph1.elements, it2 = ph2.elements; it1 != ph1.first_free&&it2 != ph2.first_free; it1++, it2++)
		if (*it1 == *it2)
			;
		else
			return false;
	return true;

}

bool operator!=(const String &ph1, const String &ph2)
{
	return !(ph1 == ph2);
}

char &String::operator[](const size_t i)
{
	return (elements[i]);
}


const char &String::operator[](const size_t i) const
{
	return (elements[i]);
}