#include<iostream>
#include<stdio.h>
#include<string>
using namespace::std;

class Screen {
public: 
	typedef string::size_type pos;
	Screen() = default;
	Screen(const pos ht, const pos wd) :height(ht), width(wd), contents(ht * wd, ' '){}
	Screen(const pos ht, const pos wd, string c) : height(ht), width(wd),contents(ht * wd, c){}

	char get()const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r * width + c]; }
private:
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
	string contents;
};