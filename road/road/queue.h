// queue.h
#pragma once
#include <iostream>
const int queueSize = 100;
template<class T>
class queue
{
public:
	T data[queueSize];
	int front, rear;
}; 
