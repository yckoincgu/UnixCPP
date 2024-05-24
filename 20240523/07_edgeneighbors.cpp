#include <iostream>
#include <set>
using namespace std;

class Vertice {
public:
    bool visited = false;
    std::set<Vertice*> neighbors;
    int nodeID;
    Vertice(int nodeID) : nodeID(nodeID) {}

    void printList() {
        std::cout << "Node " << nodeID << " has neighbors ";
        for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
            std::cout << (*it)->nodeID << ", ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Edge {
public:
    T p, q;
    std::set<Edge*> neighbors;
    bool visited=false;
    Edge(T source_V, T destinate_V) : p(source_V), q(destinate_V) {
        p->neighbors.insert(q);
        q->neighbors.insert(p);
    }

    void printEdgeNeighbors() {
        std::cout << "(" << p->nodeID << ", " << q->nodeID << ") has neighbors: ";
        for (auto e = neighbors.begin(); e != neighbors.end(); ++e) {
            std::cout << "(" << (*e)->p->nodeID << ", " << (*e)->q->nodeID << ") ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Graph {
public:
    std::set<T> vSet;
    std::set<Edge<T>*> eSet;
    
    void buildEdgeNeighbors() {
        for (auto e1 = eSet.begin(); e1 != eSet.end(); ++e1) {
            std::cout<< "e1(" << (*e1)->p->nodeID<<"," <<(*e1)->q->nodeID<<") has neighbors: ";
            for (auto e2 = eSet.begin(); e2 != eSet.end(); ++e2) {
                if (*e1 != *e2  && (        // 
                    ((*e1)->p == (*e2)->p) ||
                    ((*e1)->p == (*e2)->q) ||
                    ((*e1)->q == (*e2)->p) ||
                    ((*e1)->q == (*e2)->q))) 
                {
                    (*e1)->neighbors.insert(*e2);
                    std::cout<< "e2(" << (*e2)->p->nodeID<<"," <<(*e2)->q->nodeID<<"), ";
                }
            }
            std::cout<<  std::endl;
        }
    }
};

int main() {
    Vertice v0(0), v1(1), v2(2), v3(3), v4(4);
    Edge<Vertice*> e1(&v0, &v1), e2(&v0, &v2), e3(&v1, &v3), e4(&v1, &v4), e5(&v2, &v4);

    Graph<Vertice*> g;
    g.vSet.insert(&v0);
    g.vSet.insert(&v1);
    g.vSet.insert(&v2);
    g.vSet.insert(&v3);
    g.vSet.insert(&v4);

    g.eSet.insert(&e1);
    g.eSet.insert(&e2);
    g.eSet.insert(&e3);
    g.eSet.insert(&e4);
    g.eSet.insert(&e5);
    g.buildEdgeNeighbors();

    int i;
    std::cin >> i;

    return 0;
}
