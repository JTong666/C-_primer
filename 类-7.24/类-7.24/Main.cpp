#include<stdio.h>
#include<string>
#include"Screen.h"


int main()
{
	Screen item1;
	item1.get();
	Screen item2(10, 20);
	item2.get(3, 41);

}