#include<iostream>
using namespace std;

class road
{
public:

protected:
	int road_id;
	int size;
	int rate_limiting;
	int number_lanes;
	int begin_id;
	int end_id;
	int bothway;
};

class cross
{
public:

protected:
	int cross_id;
	int road_ids1, road_ids2, road_ids3, road_ids4;
};

struct ArcNode
{
	road roads;
	road* next;
};

struct VertexNode
{
	cross cs;
	road* first;
};

class ALGraph
{
public:
	ALGraph()
};