#include"StrBlob.h"
#include<iostream>
#include<stdio.h>
using namespace std;


int main()
{
	StrBlob s1;
	StrBlob s2{ "a","aa", "aaa", "b" };
	const StrBlob s3{ "q","qq","w","ww" };

	//cout << s1.back() << s1.front() << endl;
	cout << s2.front() << s2.back() << endl;
	cout << s3.front() << s3.back() << endl;
	return 0;
}