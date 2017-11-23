#include <iostream>
#include "graph.h"
#include "union_find.h"
#include <cassert>
#include <vector>
#include <unordered_map>

using namespace std;

void assertEqual(int a, int b) {
	if (a != b) {
		cout << "Expected " << a << " to equal " << b << endl;
		assert(false);
	}
}

void assertEqual(vector<int>& ints) {
	if (ints.empty()) return;
	int val = ints[0];
	for (int i = 1; i < ints.size(); i++) {
		if (val != ints[i]) {
			cout << "ints[" << i << "] doesn't equal " << val << endl;
			assert(false);
		}
	}
}

void assertNotEqual(vector<int>& ints) {
	if (ints.empty()) return;
	int val = ints[0];
	for (int i = 1; i < ints.size(); i++) {
		if (val != ints[i]) return;
	}
	cout << "All values in ints are " << val << endl;
	assert(false);
}

void assertDistinct(vector<int>& ints) {
	unordered_map<int, bool> map;
	for (int& x : ints) {
		if (map[x]) {
			cout << "Found " << x << " twice " << endl;
			assert(false);
		}
		map[x] = true;
	}
}


void test0() {
	UnionFind uf;
	for (int i = 0; i < 10; i++) {
		uf.add(i);
	}

	uf.combine(1, 2);
	assertEqual(uf.find(1), uf.find(2));

	for (int i = 1; i < 7; i++) {
		uf.combine(i, i+1);
		uf.add(i);
	}

	vector<int> ints;
	for (int i = 1; i < 8; i++) {
		ints.push_back(uf.find(i));
		uf.add(i);
	}

	assertEqual(ints);

	ints.push_back(uf.find(8));
	assertNotEqual(ints);
}

void test1() {
	UnionFind uf;

	uf.add(0);
	uf.add(-5);
	uf.add(9);

	vector<int> init {uf.find(0), uf.find(-5), uf.find(9)};
	assertDistinct(init);

	uf.combine(0, -5);
	for (int i = 0; i < 10; i++) {
		uf.add(-5);
		vector<int> v1 {uf.find(0), uf.find(-5), uf.find(9)};
		assertNotEqual(v1);
		assertEqual(v1[0], v1[1]);
	}

	uf.combine(9, 0);
	for (int i = 0; i < 10; i++) {
		vector<int> v1 {uf.find(0), uf.find(-5), uf.find(9)};
		assertEqual(v1);
	}
}

void test2() {
	Graph graph;
	graph.bid(1, 2, 5);
}

int main() {
	cout << "Test 0 -----------------------" << endl;
	test0();
	cout << "Test 1 -----------------------" << endl;
	test1();
	cout << "Test 2 -----------------------" << endl;
	test2();
}
