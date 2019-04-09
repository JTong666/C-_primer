#include<iostream>
#include<string>

#include<boost/thread.hpp>
using namespace std;

void mythread()
{
	cout << " hello,thread! " << endl;
}

int main()
{
	boost::function<void()> f(mythread);
	boost::thread t(f);
	t.join();
	cout << " thread is over! " << endl;

	return 0;
}
