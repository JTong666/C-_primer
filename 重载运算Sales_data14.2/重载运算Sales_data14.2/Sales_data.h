#include<string>
#include<iostream>
using namespace std;


class Sales_data
{
	friend bool operator==(const Sales_data &, const Sales_data &);
	friend bool operator!=(const Sales_data &, const Sales_data &);
	friend istream& operator >> (istream &, Sales_data &);
	friend ostream& operator << (ostream &, Sales_data &);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
	Sales_data():bookNo(""), units_sold(0), revenue(0.0){}
	Sales_data(const string &p, int i, double j) :bookNo(p), units_sold(i), revenue(i*j) {}
	Sales_data(const string &s) :bookNo(s), units_sold(0), revenue(0) {}
	Sales_data(istream &is);
	Sales_data(const Sales_data &m) :bookNo(m.bookNo), units_sold(m.units_sold), revenue(m.revenue) {}
	Sales_data &operator+=(const Sales_data &);
	string isbn()const { return bookNo; }
private:
	inline double avg_price() const;
	string bookNo;
	int units_sold;
	double revenue;
};

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}
Sales_data::Sales_data(istream &is):Sales_data()
{
	is >> *this;
}


Sales_data& Sales_data::operator+=(const Sales_data &ph)
{
	units_sold += ph.units_sold;
	revenue += ph.revenue;
	return *this;
}

Sales_data operator+(const Sales_data &iter1, const Sales_data &iter2)
{
	Sales_data new_data = iter1;
	new_data += iter2;
	return new_data;
}

istream& operator >> (istream &is, Sales_data &phs)
{
	double price = 0.0;
	is >> phs.bookNo >>price>>phs.units_sold;
	if (is)
		phs.revenue = price*phs.units_sold;
	else
		Sales_data();
	return is;

}

ostream& operator<<(ostream &os, Sales_data &phs)
{
	os << phs.isbn() <<" "<< phs.avg_price() <<" "<< phs.units_sold <<" "<< phs.revenue << endl;
	return os;
}

bool operator==(const Sales_data &ph1, const Sales_data &ph2)
{
	return ph1.isbn() == ph2.isbn() && ph1.revenue == ph2.revenue&&ph1.units_sold == ph2.units_sold;
}

bool operator!=(const Sales_data &ph1, const Sales_data &ph2)
{
	return !(ph1 == ph2);
}