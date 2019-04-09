#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<map>
using namespace std;


void readTxt(const string& filename, vector<string>& s)
{
	ifstream in(filename);
	if (in)
	{
		string buf;
		while (getline(in, buf))
		{
			cout << *(buf.end()-2) << endl;
		}
	}
}


int main()
{
	vector<string>Image;
	readTxt("road.txt", Image);
	//for (auto iter : Image)
		//cout << iter << endl;
	return 0;
}