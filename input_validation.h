#ifndef  INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#include "graph.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
using std::string;
using std::fstream;



void invalid_input() {
	cout << "Invalid Input" << endl;
	exit(1);
}


Graph& get_input(string file_name, int* edge_to_delete) {
	int n, m;
	int edge[3];
	Graph g;
	fstream myFile(file_name);
	if (!myFile.is_open()) {
		cout << "File does not exist" << endl;
		exit(1);
	}
	myFile >> n; myFile >> m;
	if (n <= 0 || m < 0)
		invalid_input();
	else {
		g.make_empty_graph(n);
		g.set_m(m);
		for (int i = 0; i <= m; i++) {
			if (i != m) {
				for (int j = 0; j < 3; j++) {
					myFile >> edge[j];
					if (j != 2)
						if (edge[j] < 1 || edge[j] > n)
							invalid_input();
				}
				g.add_edge(edge[0], edge[1], edge[2]);
			}
			else {
				for (int j = 0; j < 2; j++) {
					myFile >> edge_to_delete[j];
					if (edge_to_delete[j] < 1 || edge_to_delete[j] > n)
						invalid_input();
				}
			}
		}
	}
	return g;
}

void visit(Graph& g, vector<string>& colors, int vertex) {
	colors[vertex] = "G";
	LinkedList<item>* adj_list = g.get_adj_list(vertex);
	Node<item>* curr = adj_list->head->next;

	while (curr != nullptr) {
		if (colors[curr->data.vertex] == "W") {
			visit(g, colors, curr->data.vertex);
		}
		curr = curr->next;
	}
	colors[vertex] = "B";

}

bool is_connected(Graph& g) {
	bool res = true;
	vector<string> colors(g.get_n() + 1);
	for (int i = 1; i <= g.get_n(); i++) {
		colors[i] = "W";
	}
	visit(g,colors,1);

	for (int i = 1; i <= g.get_n(); i++) {
		if (colors[i] != "B") {
			res = false;
			break;
		}
	}
	return res;
}


#endif // ! INPUT_VALIDATION_H

