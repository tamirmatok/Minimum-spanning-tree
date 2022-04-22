#ifndef GRAPH
#define GRAPH
#include "linked_list.h"


class item {
public:
	int vertex;
	int weight;
	item(int v, int w) : vertex(v), weight(w) {}
	item() {}
};

class Graph {
	LinkedList<item>* adj_list_arr;
	int n;
public:
	Graph(int _n=0) : n(_n) { make_empty_graph(n); }
	void make_empty_graph(int _n);
	bool is_adjacent(int u, int v);
	LinkedList<item>* get_adj_list(int u);
	void add_edge(int u, int v, int c);
	void remove_edge(int u, int v);
};

#endif

