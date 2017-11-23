#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <set>
#include "union_find.h"

using namespace std;

class Graph {

public:

	struct edge {
		int node1, node2, cost;
		edge(int node1, int node2, int cost) : 	node1(min(node1, node2)),
												node2(max(node1, node2)),
												cost(cost) {}
		bool operator<(edge other) const {
			return other.cost < this->cost;
		}
	};

private:

	priority_queue<edge> bids;
	set<edge> solution;
	UnionFind uf;

	int solution_cost;
	bool has_cycle;

public:

	Graph();

	void bid(int node1, int node2, double cost);
	void mandatory(int node1, int node2, double cost);

	double cost();
	int components();
	bool cycle();
	set<edge> solution_edges();
	vector<int> shortest_path(int node1, int node2);

};
