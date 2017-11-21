#include <vector>
#include <utility>

using namespace std;

class Graph {

private:
    
    int a;

public:

    void bid(int node1, int node2, double cost);
    void mandatory(int node1, int node2, double cost);

    double cost();
    int components();
    bool cycle();
    vector<pair<int, int> > solution_edges();
    vector<int> shortest_path(int node1, int node2);
    
};
