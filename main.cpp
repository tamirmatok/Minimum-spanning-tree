#include <iostream>
#include "graph.h"
#include "input_validation.h"
#include "quick_sort.h"
#include "Edge.h"
#include "kruskal.h"
#include <vector>
using namespace std;
using std::string;
using std::fstream;


int main(int argc, char** argv) {

	int edge_to_delete[2];
	Graph g = get_input(argv[1], edge_to_delete);
	if (is_connected(g)) {

		vector<Edge> edge_vec = create_edge_vec(g);
		quickSort<Edge>(edge_vec, 0, g.get_m() - 1);
		int kruskal1 = kruskal(edge_vec, g.get_n(), g.get_m());
		cout << "kruskul<" << kruskal1 << ">" << endl;
		g.remove_edge(edge_to_delete[0], edge_to_delete[1]);
		if (!is_connected(g)) {
			invalid_input();
		}
		else { //* edge_to_delete is not a bridge
			for (int i = 0; i < edge_vec.size(); i++) {
				if (edge_vec[i].u == edge_to_delete[0] && edge_vec[i].v == edge_to_delete[1]) {
					edge_vec.erase(edge_vec.begin() + i);
					break;
				}
			}
			int kruskal2 = kruskal(edge_vec, g.get_n(), g.get_m());
			cout << "kruskul2<" << kruskal2 << ">" << endl;
		}
	}
}
