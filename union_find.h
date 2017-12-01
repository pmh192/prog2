#ifndef UNION_FIND
#define UNION_FIND

#include<unordered_map>

using namespace std;

class UnionFind {
private:
	unordered_map<int, int> sets;
	int component_count;
public:
	UnionFind();
	void add(int loc);
	int find(int loc);
	void combine(int loc1, int loc2);
	int components();
};

#endif