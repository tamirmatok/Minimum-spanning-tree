#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES
#include <iostream>
using namespace std;

class item {
public:
	int vertex;
	int weight;
};

template<class T>
class LinkedList {
public:

	class Node {
		T data;
		Node* next;
	public:
		Node(T& item, Node* ptr = nullptr) { data = item; next = ptr; }
	};

	Node* head, tail;

	LinkedList() : head(nullptr) {}
	void make_empty() { head = tail = nullptr; }
	bool is_empty() { return head == nullptr; }
	void insert_to_end(Node* node) {
		if (is_empty())
			head = tail = node;
		else
			tail->next = node;
	}
	void delete_after(Node* node) {

	}
	~LinkedList() {
		Node* next, curr = head;
		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}

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
