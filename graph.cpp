#include "graph.h"
#include <cmath>

Graph::Graph() : solution_cost(0), has_cycle(false) {

}

void Graph::bid(int node1, int node2, double cost) {
	bids.push(edge(node1, node2, cost));

	uf.add(node1);
	uf.add(node2);
}


void Graph::addEdge(edge& e) {
	adjList[e.node1].insert(pair<int, int>(e.node2, e.cost));
	adjList[e.node2].insert(pair<int, int>(e.node1, e.cost));

	solution.insert(e);
	this->solution_cost += e.cost;

	uf.add(e.node1);
	uf.add(e.node2);

	if (!has_cycle) {
		has_cycle = uf.find(e.node1) == uf.find(e.node2);
	}

	uf.combine(e.node1, e.node2);
}

void Graph::mandatory(int node1, int node2, double cost) {
	edge e(node1, node2, cost);
	addEdge(e);
}

double Graph::cost() {
	runKruskals();

	return this->solution_cost;
}

int Graph::components() {
	runKruskals();

	return uf.components();
}


bool Graph::cycle() {
	return has_cycle;
}

void Graph::runKruskals() {
	while (!bids.empty()) {
		edge e = bids.top();
		bids.pop();

		if (uf.find(e.node1) != uf.find(e.node2)) {
			addEdge(e);
		}
	}
}


set<Graph::edge>* Graph::solution_edges() {
	runKruskals();

	return &(this->solution);
}


struct state {
	int node, dist;
	vector<int> path;

	state(int n, int d) : node(n), dist(d) {}

	bool operator<(state other) const {
		return dist > other.dist;
	}
};

vector<int> Graph::shortest_path(int node1, int node2) {
	runKruskals();

	if (node1 == node2) {
		vector<int> list;
		list.push_back(node1);
		return list;
	}


	priority_queue<state> states;

	state first(node1, 0);
	first.path.push_back(node1);

	unordered_map<int, int> visited;
	visited[node1] = 0;

	states.push(first);

	while (!states.empty()) {
		state s = states.top();
		states.pop();
		//cout << "visiting " << s.node << " wit dist " << s.dist << endl;

		if (s.node == node2) {
			return s.path;
		}

		set<pair<int, int> > adj = adjList[s.node];
		for (auto it = adj.begin(); it != adj.end(); it++) {
			int n = (*it).first;
			int c = (*it).second;
			state newState(n, s.dist + c);
			newState.path = s.path;
			newState.path.push_back(n);

			auto it_dist = visited.find(newState.node);
			if (it_dist == visited.end() || newState.dist < it_dist->second) {
				//cout << "pushing " << newState.node << " wit dist " << newState.dist << endl;
				states.push(newState);
				visited[newState.node] = newState.dist;
			}
		}
	}

	vector<int> l;
	return l;
}
