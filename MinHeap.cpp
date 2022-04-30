#include "MinHeap.h"

// Private funcs
int MinHeap::Left(int node) {
	return (2 * node + 1);
}
int MinHeap::Right(int node) {
	return (2 * node + 2);
}
int MinHeap::Parent(int node) {
	return (node - 1) / 2;
}

//methods
Node MinHeap::deleteMax(MinHeap& twinHeap)
{
	if (heapSize < 1)
	{
		cout << "Error : Empty Heap \n";
		exit(1);
	}
	Node max = data[0];
	heapSize--;
	data[0] = data[heapSize];
	data[0].index = 0;
	twinHeap.getDataArr()[data[0].twinIndex].twinIndex = 0;
	fixHeap(0, twinHeap);
	return max;
}

void MinHeap::swap(Node src, Node dst)
{
	data[src.index] = dst;
	data[src.index].index = src.index;
	data[dst.index] = src;
	data[dst.index].index = dst.index;
}

bool MinHeap::compare(int x, int y)
{
	if (isMax)
		return x > y; // means its MinHeap
	else
		return x < y; // means minHeap
}

int MinHeap::insert(MinHeap& twinHeap, Node& _node)
{
	if (heapSize == MAX_SIZE)
	{
		cout << "Error : Heap Full \n";
		exit(1);
	}
	int i = heapSize;
	_node.index = heapSize;
	Node node = _node;
	heapSize++;

	while (i > 0 && compare(node.prio, data[Parent(i)].prio))
	{
		twinHeap.getDataArr()[data[Parent(i)].twinIndex].twinIndex = i;
		data[i] = data[Parent(i)];
		data[i].index = i;
		i = Parent(i);
	}
	node.index = i;
	_node = node;
	data[i] = node;
	return i;
}

int MinHeap::insertFrom(Node node)
{
	if (heapSize == MAX_SIZE)
	{
		cout << "wrong input";
		exit(1);// 12 24 33
	}
	int i = node.index;
	Node newNode;
	newNode = data[i] = data[heapSize - 1];
	data[i].index = i;

	heapSize--;

	while (i > 0 && compare(node.prio, data[Parent(i)].prio))
	{
		//twinHeap.getDataArr()[data[Parent(i)].twinIndex].twinIndex = i;
		data[i] = data[Parent(i)];
		data[i].index = i;
		i = Parent(i);
	}
	newNode.index = i;
	data[i] = newNode;
	return i;
}

void MinHeap::fixHeap(int nodePos, MinHeap& twinHeap)
{
	int max = nodePos;
	int left = Left(nodePos);
	int right = Right(nodePos);

	if (left < heapSize && compare(data[left].prio, data[nodePos].prio))
		max = left;
	if (right < heapSize && compare(data[right].prio, data[nodePos].prio))
		max = right;

	if (max != nodePos)
	{
		twinHeap.getDataArr()[data[nodePos].twinIndex].twinIndex = data[max].index;
		twinHeap.getDataArr()[data[max].twinIndex].twinIndex = data[nodePos].index;
		swap(data[nodePos], data[max]);
		fixHeap(max, twinHeap);
	}
}
