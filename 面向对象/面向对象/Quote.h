#include<string>
#include<iostream>
using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const string &c, const double p) :bookNo(c), price(p) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const
	{
		return n*price;
	}
	virtual ~Quote() = default;
	virtual void debug();
private:
	string bookNo;
protected:
	double price = 0.0;
};
class Blk_quote :public Quote
{
public:
	Blk_quote() :Quote(), discount(0.0), min_size(0) {}
	Blk_quote(const string &c, const double p, double d, size_t s) :Quote(c, p), discount(d), min_size(s) {}
	double net_price(size_t n) const override;
private:
	double discount = 0.0;
	size_t min_size = 0;
};
double Blk_quote::net_price(size_t n) const
{
	if (n > min_size)
		return{ (1 - discount)*price*n };
	else
		return (n*price);
}


double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "booknumber: " << item.isbn() << " sold: " << n << " total:" << ret << endl;
	return ret;
}

void Quote::debug() {
	cout << "booknumber " << isbn() << " price " << price << endl;
}