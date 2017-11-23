#include <iostream>
#include <string>
#include <utility>
#include "graph.h"

using namespace std;

int main() {
	string command;
	Graph g;
	int n1, n2;
	double price;

	while (cin >> command) {
		if (command == "BID") {
			cin >> n1 >> n2 >> price;
			g.bid(n1, n2, price);
		}
		else if (command == "MANDATORY") {
			cin >> n1 >> n2 >> price;
			g.mandatory(n1, n2, price);
		}
		else if (command == "COST?") {
			cout << g.cost() << endl;
		}
		else if (command == "COMPONENTS?") {
			cout << g.components() << endl;
		}
		else if (command == "CYCLE?") {
			if (g.cycle()) { cout << "YES" << endl; }
			else		   { cout << "NO"  << endl; }
		}
		else if (command == "LIST?") {
			set<Graph::edge> list = g.solution_edges();
			for (const auto& p : list) {
				cout << "(" << p.node1 << "," << p.node2 << ")" << endl;
			}
		}
		else if (command == "SHORTEST_PATH?") {
			cin >> n1 >> n2;
			vector<int> list = g.shortest_path(n1, n2);
			for (const int& i : list) {
				cout << i << " ";
			}
			cout << endl;
		}
		else if (command == "END") {
			break;
		}
		else {
			cout << "unrecongized command: '" << command << "'" << endl;
			break;
		}

	}
	return 0;
}
