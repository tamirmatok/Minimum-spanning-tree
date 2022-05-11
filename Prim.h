#pragma once
#include "vector"
#include "Edge.h"
#include "graph.h"
#include "PriorityQueue.h"


 int Prim(Graph G) 
{
	 int u; 
	 int res = 0;
	 int numOfVertexes = G.get_n() + 1; // vertex 0 is a dummy
	 vector<int> min(numOfVertexes);
	 bool* InT = new bool[numOfVertexes]{ false };
	 PriorityQueue Q(numOfVertexes);
	 LinkedList<item>* adj_list;

	 min[0] = INT_MAX;
	 min[1] = 0;
	 for (int i = 2; i < numOfVertexes; i++)
		 min[i] = INT_MAX - 1;

	 Q.Build(min, numOfVertexes); 
	 while (!Q.IsEmpty())
	 {
		 u = Q.DeleteMin();
		 InT[u] = true;
		 adj_list = G.get_adj_list(u);
		 Node<item>* curr = adj_list->head->next;
		 while (curr != nullptr) 
		 {
			 if ((!InT[curr->data.vertex]) && (curr->data.weight < min[curr->data.vertex]))
			 {
				 if (min[curr->data.vertex] != INT_MAX - 1)
					 res += curr->data.weight - min[curr->data.vertex];
				 else
					 res += curr->data.weight;
				 min[curr->data.vertex] = curr->data.weight;
				 Q.DecreaseKey(curr->data.vertex, curr->data.weight);
			 }
			 curr = curr->next;
		 }
	 }
	 return res;
}