#include <iostream>
#include <list>
#include <set>
#include <queue>

using namespace std;

class Vertice {
public:
    bool visited = false;
    list<Vertice*> neighbors;
    int nodeID;

    Vertice(int nodeID) : nodeID(nodeID) {}

    void printList() {
        cout << "Node " << nodeID << " has neighbors ";
        for (list<Vertice*>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
            cout << (*it)->nodeID << ", ";
        }
        cout << endl;
    }
};

class Edge {
public:
    Vertice* p;
    Vertice* q;

    Edge(Vertice* source_V, Vertice* destinate_V) : p(source_V), q(destinate_V) {
        p->neighbors.push_back(q);
        q->neighbors.push_back(p);
    }
};

class Graph {
public:
    set<Vertice*> vSet;
    set<Edge*> eSet;

    void bfs(Vertice* startVertex) {
        if (vSet.find(startVertex) == vSet.end()) return;
        Vertice* neighbor;
        queue<Vertice*> q;
        startVertex->visited = true;
        q.push(startVertex);

        while (!q.empty()) {
            Vertice* current = q.front();
            q.pop();
            cout << "Visited vertex " << current->nodeID << endl;

            for (list<Vertice*>::iterator neighbor= current->neighbors.begin(); 
						  neighbor!=current->neighbors.end(); ++neighbor) {
                if (!(*neighbor)->visited) {
                    (*neighbor)->visited = true;
                    q.push((*neighbor));
                }
            }
        }
    }
};

int main() {
    Vertice v0(0), v1(1), v2(2), v3(3), v4(4), v5(5);
    Edge e1(&v0, &v1), e2(&v0, &v2), e3(&v1, &v3), e4(&v1, &v4), e5(&v2, &v4), e6(&v3, &v5);

    Graph g;
    g.vSet.insert(&v0);
    g.vSet.insert(&v1);
    g.vSet.insert(&v2);
    g.vSet.insert(&v3);
    g.vSet.insert(&v4);
    g.vSet.insert(&v5);

    g.eSet.insert(&e1);
    g.eSet.insert(&e2);
    g.eSet.insert(&e3);
    g.eSet.insert(&e4);
    g.eSet.insert(&e5);
    g.eSet.insert(&e6);

    g.bfs(&v1);

    return 0;
}
