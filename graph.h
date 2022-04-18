#ifndef GRAPH
#define GRAPH
#include "linked_list.h"


class item {
public:
	int vertex;
	int weight;
};

class Graph {

	LinkedList<item>* adj_list_arr;
	int n;
public:
	Graph() { adj_list_arr = nullptr; }
	Graph(int _n) : n(_n) { make_empty_graph(n); }
	void make_empty_graph(int _n) { _n = n; adj_list_arr = new LinkedList<item>[n]; }
	bool is_adjacent(int u, int v) {
		if (u >= 0 && u < n) {

		}
	}

};

#endif

