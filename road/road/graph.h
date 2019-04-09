/*


#include<vector>
#include<memory>
using namespace std;


class road
{
	friend class cross;
public:
	road() = default;
	road(const int id, const int size, const int limiting, const int lanes, const int beginid, int endid, int both) :road_id(id), size(size), rate_limiting(limiting),
		number_lanes(lanes), begin_id(beginid), end_id(endid), bothway(both) {}

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
	cross() = default;
	cross(const int id, const int road_id1, const int road_id2, const int road_id3, const int road_id4) :cross_id(id), 
		road_ids1(road_id1), road_ids2(road_id2), road_ids3(road_id3), road_ids4(road_id4) {}
private:
    int cross_id;
	int road_ids1, road_ids2, road_ids3, road_ids4;
	shared_ptr<road> p1;

};

class car
{
public:
	car(int id, int begin, int end, int speed, int time) :car_id(id), begin_cross(begin), end_cross(end), max_speed(speed), time(time) {}

protected:
	int car_id;
	int begin_cross;
	int end_cross;
	int max_speed;
	int time;
};

typedef struct edge
{
	road roads;
	shared_ptr<road> iter;
}EDGE;

*/


// graph.h
#pragma once
#include<iostream>
#include"queue.h"
// ����߱���
struct ArcNode
{
	int adjvex;// �ڽӵ���
	ArcNode* next;
};
// ���嶥�����
struct VertexNode
{
	int vertex;
	ArcNode* firstedge;
};

// �����ڽӱ�洢�ṹ��ͼ����ʵ��
const int MaxSize = 10;
int visited[MaxSize] = { 0 };// �����Ƿ񱻷��ʵı��
							 //typedef VertexNode AdjList[MaxSize];    //�ڽӱ� 
template<class T>
class ALGraph
{
public:
	ALGraph(T a[], int n, int e);// ���캯����������N������e���ߵ�ͼ
	~ALGraph() {}// ��������
	void DFSTraaverse(int v);// ������ȱ���ͼ
	void BFSTraverse(int v);// ������ȱ���ͼ
private:
	VertexNode adjlist[MaxSize];// ��Ŷ��������
	int vertexNum, arcNum;// ͼ�ж������ͱ���
};

template<class T>
ALGraph<T>::ALGraph(T a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i <vertexNum; i++)
	{
		adjlist[i].vertex = a[i];
		adjlist[i].firstedge = NULL;
	}
	for (int k = 0; k < arcNum; k++)
	{
		int i, j;
		std::cin >> i >> j;
		ArcNode* s = new ArcNode;
		s->adjvex = j;
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}
}

template<class T>
inline void ALGraph<T>::DFSTraaverse(int v)
{
	std::cout << adjlist[v].vertex;
	visited[v] = 1;
	ArcNode* p = adjlist[v].firstedge;
	while (p != NULL)
	{
		int j = p->adjvex;
		if (visited[j] == 0)
			DFSTraaverse(j);
		p = p->next;
	}
}

template<class T>
inline void ALGraph<T>::BFSTraverse(int v)
{
	int visited[MaxSize] = { 0 };// �����Ƿ񱻷��ʵı��
	queue<T> Q;
	Q.front = Q.rear = -1;    // ��ʼ������
	std::cout << adjlist[v].vertex;
	visited[v] = 1;
	Q.data[++Q.rear] = v;// �����ʶ������
	while (Q.front != Q.rear)
	{
		v = Q.data[++Q.front];    // ��ͷԪ�س���
		ArcNode* p = adjlist[v].firstedge;
		while (p != NULL)
		{
			int j = p->adjvex;
			if (visited[j] == 0)
			{
				std::cout << adjlist[j].vertex;
				visited[j] = 1;
				Q.data[++Q.rear] = j;
			}
			p = p->next;
		}
	}
}
