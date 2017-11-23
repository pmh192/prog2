#include "graph.h"
#include <cmath>

Graph::Graph() : solution_cost(0), has_cycle(false) {

}

void Graph::bid(int node1, int node2, double cost) {
	bids.push(edge(node1, node2, cost));

	uf.add(node1);
	uf.add(node2);
}


void Graph::mandatory(int node1, int node2, double cost) {
	solution.insert(edge(node1, node2, cost));
	this->solution_cost += cost;

	uf.add(node1);
	uf.add(node2);
	uf.combine(node1, node2);
}

double Graph::cost() {
	return this->solution_cost;
}

int Graph::components() {
	return uf.components();
}


bool Graph::cycle() {
	return has_cycle;
}


set<Graph::edge> Graph::solution_edges() {
	return this->solution;
}


vector<int> Graph::shortest_path(int node1, int node2) {
	vector<int> list;
	return list;
}
