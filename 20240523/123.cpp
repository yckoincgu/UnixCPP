#include <iostream>
#include <list>

using namespace std;

class Vertice {
public:
    std::list<Vertice> neighbors;
    int nodeID;

    // Constructor
    Vertice(int node) : nodeID(node) {
        std::cout << "A Vertice is created with nodeID: " << nodeID << std::endl;
    };
};

template <typename T>
class E {
public:
    T p, q;

    // Constructor
    E(T source_V, T destinate_V) : p(*source_V), q(*destinate_V) {
        // Add destinate_V as a neighbor to source_V
        p.neighbors.push_back(q);
        std::cout << "An edge is created from node " << p.nodeID << " to node " << q.nodeID << std::endl;
    };
};

int main() {
    // Create Vertice objects
    Vertice v1(1), v2(2);

    // Create an edge between v1 and v2
    E<Vertice*> e1(&v1, &v2);

    // Print the node IDs
    std::cout << "Node IDs: " << v1.nodeID << " and " << v2.nodeID << std::endl;

    return 0;
}
