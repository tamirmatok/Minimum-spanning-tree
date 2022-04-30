#pragma once
#include <iostream>
#include "Node.h"


class MinHeap
{
	static const int MAX_SIZE = 100;
	Node data[MAX_SIZE];
	int heapSize = 0;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);

public:
	void setHeapSize(int newSize) { heapSize = newSize; }

	Node Root() { return *data; }
	Node* getDataArr() { return data; }
	int getHeapSize() { return heapSize; }

	//methods
	Node deleteMax(BaseHeap& twinHeap);
	int insert(BaseHeap& twinHeap, Node& node); // return final node index in data
	bool compare(int x, int y);
	void fixHeap(int nodePos, BaseHeap& twinHeap);
	int insertFrom(Node node);
}
