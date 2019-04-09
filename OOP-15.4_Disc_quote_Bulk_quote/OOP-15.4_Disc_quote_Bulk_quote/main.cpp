#include<iostream>
#include<vector>
#include<memory>
#include"Dis_Quote.h"



void creat_Quote_vector()
{
	vector<shared_ptr<Quote>> ptr1;
	ptr1.push_back(make_shared<Quote>("jiaotong", 10));
	ptr1.push_back(make_shared<Bulk_quote>("TongTong", 50, 0.25, 10));
	cout << ptr1.back()->net_price(15) << endl;
	cout << ptr1.front()->net_price(15) << endl;
}



int main()
{
	creat_Quote_vector();
	return 0;
}