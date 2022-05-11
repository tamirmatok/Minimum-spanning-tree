#include <iostream>
#include <vector>
#include "graph.h"
#include "input_validation.h"
#include "quick_sort.h"
#include "Edge.h"
#include "kruskal.h"
#include "Prim.h"

using namespace std;
using std::string;
using std::fstream;

int main(int argc, char ** argv) 
{
	ofstream outputFile(argv[2]);
	Edge edge_to_delete;
	Graph g = get_input(argv[1], &edge_to_delete, outputFile);

	if (is_connected(g)) 
	{
		vector<Edge> edge_vec = create_edge_vec(g);
		quickSort<Edge>(edge_vec, 0, g.get_m() - 1);
		int kruskal1 = kruskal(edge_vec, g.get_n(), g.get_m());
		int prim = Prim(g);
		cout << "kruskul<" << kruskal1 << ">" << endl;
		cout << "Prim<" << prim << ">" << endl;
		outputFile << "kruskul<" << kruskal1 << ">" << endl;
		outputFile << "Prim<" << prim << ">" << endl;


		if (edge_to_delete.u < 1 || edge_to_delete.u > g.get_n() ||
			edge_to_delete.v < 1 || edge_to_delete.v > g.get_n()) 
			invalid_input(outputFile);

		g.remove_edge(edge_to_delete.v, edge_to_delete.u);
		g.remove_edge(edge_to_delete.u, edge_to_delete.v);

		if (!is_connected(g)) {
			cout << "kruskul<" << "NO MST" << ">" << endl;
			outputFile << "kruskul<" << "NO MST" << ">" << endl;
		}
		else { //* edge_to_delete is not a bridge
			for (int i = 0; i < edge_vec.size(); i++) {
				if (edge_vec[i].u == edge_to_delete.u && edge_vec[i].v == edge_to_delete.v) {
					edge_vec.erase(edge_vec.begin() + i);
				}
			}
			for (int i = 0; i < edge_vec.size(); i++) {
				if (edge_vec[i].u == edge_to_delete.v && edge_vec[i].v == edge_to_delete.u) {
					edge_vec.erase(edge_vec.begin() + i);
				}
			}
			int kruskal2 = kruskal(edge_vec, g.get_n(), g.get_m());
			cout << "kruskul<" << kruskal2 << ">" << endl;
			outputFile << "kruskul<" << kruskal2 << ">" << endl;
		}
	}
	else {
		cout << "kruskul<" << "NO MST" << ">" << endl;
		cout << "Prim<" <<"NO MST" << ">" << endl;
		cout << "kruskul<" << "NO MST" << ">" << endl;
		outputFile << "kruskul<" << "NO MST" << ">" << endl;
		outputFile << "Prim<" << "NO MST" << ">" << endl;
		outputFile << "kruskul<" << "NO MST" << ">" << endl;

	}
}
