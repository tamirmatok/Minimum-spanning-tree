#ifndef DISJOINTSET_H
#define DISJOINTSET_H
#include <iostream>


class Element {
public:
	int parent;
	int size;

	Element(): size(0), parent(-1) {}
};

class DisJointSet {
	Element* A;
	int n;
public:
	DisJointSet(int _n) : n(_n) {
		A = new Element[n];
		MakeSet();
	}
	void MakeSet()
	{
		for (int i = 0; i < n; i++) {
			A[i].parent = i;
			A[i].size = 1;
		}
	}

	int find(int x)
	{
		if (A[x].parent != x)
			A[x].parent = find(A[x].parent);
		return A[x].parent;
	}
	void Union(int x, int y) {
		int repx = find(x);
		int repy = find(y);
		
		if (repx != repy) {
			if (A[repx].size > A[repy].size) {
				A[repy].parent = repx;
				A[repx].size += A[repy].size;
			}
			else {
				A[repx].parent = repy;
				A[repy].size += A[repx].size;
			}
		}

	}
};



#endif // !DISJOINTSET_H
