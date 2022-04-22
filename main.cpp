#include "graph.h"
#include <string>
#include <fstream>
#include <iostream>
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
		for (int i = 0; i <= m; i++) {
			if (i != m) {
				for (int j = 0; j < 3; j++){
					myFile >> edge[j];
					if (j != 2)
						if (edge[j] < 1 || edge[j] > n)
							invalid_input();
				}
				g.add_edge(edge[0], edge[1], edge[2]);
			}
			else{
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


int main(int argc, char** argv) {
	int edge_to_delete[2];
	Graph g = get_input(argv[1], edge_to_delete);
}
