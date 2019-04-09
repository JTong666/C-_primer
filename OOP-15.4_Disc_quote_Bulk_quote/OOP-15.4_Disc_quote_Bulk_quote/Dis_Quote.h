#include<string>
#include<iostream>
#include<set>
using namespace std;


class Quote
{
	friend bool operator!=(const Quote &, const Quote &);
public:
	Quote() = default;
	Quote(const string &c, const double p) :bookNo(c), price(p) {}
	Quote(const Quote &p) :bookNo(p.bookNo), price(p.price) {}
	Quote &operator=(const Quote &);
	const string isbn() const { return bookNo; }
	virtual Quote* clone()const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }
	virtual ~Quote() = default;
	virtual double net_price(size_t i) const { return i*price; }
private:
	string bookNo;
protected:
	double price = 0.0;
};
class Disc_Quote :public Quote
{
public:
	Disc_Quote(const string &c, const double p, double dis, size_t i) :Quote(c, p), discount(dis), n(i) {}
	Disc_Quote() = default;
	double net_price(size_t i) const = 0;
protected:
	double discount = 0.0;
	size_t n = 0;
};



class Bulk_quote :public Disc_Quote
{
public:
	Bulk_quote(const string &c, const double p, double dis, size_t n) :Disc_Quote(c, p, dis, n) {}
	//using Disc_Quote::Disc_Quote;//继承Disc_quote的构造函数
	Bulk_quote(const Bulk_quote &q) :Disc_Quote(q) {}
	Bulk_quote* clone()const & { return new Bulk_quote(*this); }
	Bulk_quote* clone() && {return new Bulk_quote(std::move(*this)); }
	Bulk_quote &operator=(const Bulk_quote &p);
	double net_price(size_t i) const override
	{
		if (i > n)
			return (i*price*(1 - discount));
		else
			return (i*price);
	}
};

double print_total(ostream &os, Quote &p, size_t i)
{
	double ret = p.net_price(i);
	os << "booknumber: " << p.isbn() << " price:" << ret << endl;
	return ret;
}
Quote &Quote::operator=(const Quote &p)
{
	bookNo = p.bookNo;
	price = p.price;
	return *this;
}

Bulk_quote &Bulk_quote::operator=(const Bulk_quote &p)
{
	Disc_Quote::operator=(p);
	return *this;
}

bool operator!=(const Quote &it1, const Quote &it2)
{
	if (it1.bookNo == it2.bookNo&&it1.price == it2.price)
		return true;
	else
		return false;
}


class Basket
{
public:
	void add_item(const Quote & sales)
	{
		items.insert(shared_ptr<Quote>(sales.clone()));
	}
	void add_item(const Quote && sales)
	{
		items.insert(shared_ptr<Quote>(std::move(sales.clone)));
	}
	double total_receipt(ostream &) const;
private:
	static bool compare(const shared_ptr<Quote> &ph1, const shared_ptr<Quote> &ph2) { return ph1->isbn() < ph2->isbn(); }
	multiset<shared_ptr<Quote>, decltype(compare)*>items{ compare };
};

double Basket::total_receipt(ostream &os) const
{
	double sum = 0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	{
		sum += print_total(cout, **iter, items.count(*iter));
	}
	os << " total sum:" << sum << endl;
	return sum;
}

