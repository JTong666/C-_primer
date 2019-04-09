// main.cpp
#include"graph.h"
using namespace std;
int main()
{
	int arry[] = { 1,2,3,4,5 };
	ALGraph<int> graph(arry, 5, 7);
	graph.BFSTraverse(3);
	cout << endl;
	graph.DFSTraaverse(3);
	system("pause");
	return 0;
}