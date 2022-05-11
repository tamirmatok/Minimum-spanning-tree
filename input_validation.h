#ifndef  INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#include "graph.h"
#include "Edge.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Edge.h"
using namespace std;
using std::string;
using std::fstream;



void invalid_input(std::ofstream& myFile) {
	myFile << "Invalid Input" << endl;
	cout << "Invalid Input" << endl;
	myFile.close();
	exit(1);
}

// input n costs 1 int
// input m costs 1 int
// input edge costs 3 * m int
// input edge to remove costs 2 int

// validFileLength = 1 + 1 + 3 * m + 2;

Graph& get_input(string file_name, Edge* edge_to_delete, std::ofstream& outputFile)
{
	int n, m, dummy;
	Edge edge;
	Graph G;
	fstream myFile(file_name);

	if (!myFile.is_open()) {
		cout << "File does not exist" << endl;
		exit(1);
	}
	myFile >> n; 
	myFile >> m;

	if (myFile.fail() || n <= 0 || m < 0 )
		invalid_input(outputFile);
	else
	{
		int validFileLength = 3 * m + 2;
		int countValidEdges = 0;
		G.make_empty_graph(n);
		G.set_m(2 * m);
		for (int i = 0; i < m; i++)
		{
			myFile >> edge.u;
			myFile >> edge.v;
			myFile >> edge.w;

			if (myFile.fail() || edge.u < 1 || edge.u > n || edge.v < 1 || edge.v > n)
				invalid_input(outputFile);

			G.add_edge(edge.u, edge.v, edge.w);
			G.add_edge(edge.v, edge.u, edge.w);
			countValidEdges += 3;
		}
		myFile >> edge_to_delete->u;
		myFile >> edge_to_delete->v;
		countValidEdges += 2;

		if (myFile.fail() || countValidEdges != validFileLength)
			invalid_input(outputFile);

		myFile >> dummy;
		if (!myFile.eof())
			invalid_input(outputFile);
	}
	return G;
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

int* get_int_arr_from_line(string str, int num_of_integers_inline)
{
	string tmpIntToRead = "";
	int i = 0;
	int* res = new int(num_of_integers_inline);

	for (int j = 0; j < num_of_integers_inline; j++)
	{
		while (isdigit(str[i]))
		{
			tmpIntToRead += str[i];
			i++;
		}
		if (str[i] != ' ' && str[i] != '\n')
			invalid_input(outputFile);
		res[j] = stoi(tmpIntToRead);
		tmpIntToRead = "";
	}

	return res;
}

#endif // ! INPUT_VALIDATION_H

