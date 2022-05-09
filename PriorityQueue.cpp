#include "PriorityQueue.h"

void PriorityQueue::Build(vector<int> min, int i_Size)
{
	m_Heap.BuildMinHeap(min, i_Size);
}

void PriorityQueue::DecreaseKey(int place, int newKey)
{
	m_Heap.DecreaseKey(place, newKey);
}

bool PriorityQueue::IsEmpty()
{
	return m_Heap.GetHeapSize() == 0;
}

int PriorityQueue::DeleteMin()
{
	return m_Heap.DeleteMin().data;
}