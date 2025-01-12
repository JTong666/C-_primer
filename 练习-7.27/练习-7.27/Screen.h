#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;


class Screen {
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd):height(ht), width(wd), contents(ht*wd, ' '){}
	Screen(pos ht, pos wd, char c):height(ht), width(wd),contents(ht*wd, c){}
	char get() const { return contents[cursor]; }
	char get(pos r, char c) const { return contents[r*width+c]; }
	inline Screen &move(pos r, pos c);
	inline Screen &set(char c);
	inline Screen &set(pos r, pos c, char ch);

	Screen &display(ostream &os) { do_display(os); return *this; }
	const Screen& display(std::ostream &os) const { do_display(os); return *this; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	void do_display(ostream &os) const {os<<contents; }
};

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r*width+c;
	return *this;
}
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
	cursor = r*width + c;
	contents[cursor] = ch;
	return *this;
}







