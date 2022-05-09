#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "disjointset.h"
#include "vector"
#include "Edge.h"


//Assumption from forum discusion:
//1) We can send to Kruskal sort-edges from graph G,
//   and not to sort edges inside the algorithem.
//2) Kruskal can return only the weight of the minimum spanning tree.

int kruskal(vector<Edge> E, int n, int m) {
	int res = 0;
	DisJointSet s(n + 1);

	for(int i = 1; i <=n; i++) {
		s.MakeSet(i);
	}

	for (int i = 0; i < m; i++) {
		int rep_u = s.find(E[i].u);
		int rep_v = s.find(E[i].v);

		if (rep_u != rep_v) {
			s.Union(rep_u, rep_v);
			res += E[i].w;
		}
	}
	return res;
}


#endif