#include "union_find.h"

void UnionFind::add(int loc) {
	sets[loc] = loc;
}

int UnionFind::find(int loc) {
	if (sets[loc] == loc) return loc;

	sets[loc] = find(sets[loc]);
	return sets[loc];
}

void UnionFind::combine(int loc1, int loc2) {
	sets[find(loc1)] = find(loc2);
}