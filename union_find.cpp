#include "union_find.h"

UnionFind::UnionFind() : component_count(0) {

}

void UnionFind::add(int loc) {
	if (sets.find(loc) == sets.end()) {
		sets[loc] = loc;
		component_count++;
	}
}

int UnionFind::find(int loc) {
	if (sets[loc] == loc) return loc;

	sets[loc] = find(sets[loc]);
	return sets[loc];
}

void UnionFind::combine(int loc1, int loc2) {
	int root1 = find(loc1), root2 = find(loc2);
	if (root1 != root2) {
		sets[root1] = root2;
		component_count--;
	}
}

int UnionFind::components() {
	return component_count;
}