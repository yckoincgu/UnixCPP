#include <iostream>
#include <list>
#include <set>

using namespace std;

class Vertice {
public:
    bool visited = false;
    std::list<Vertice*> neighbors;
    int nodeID;

    Vertice(int nodeID) : nodeID(nodeID) {}

    void printList() {
        std::cout << "Node " << nodeID << " has neighbors ";
        for (Vertice* neighbor : neighbors) {
            std::cout << neighbor->nodeID << ", ";
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Edge {
public:
    T source, destination;

    Edge(T source, T destination) : source(source), destination(destination) {
        source->neighbors.push_back(destination);
        destination->neighbors.push_back(source);
    }
};

template <typename T>
class Graph {
public:
    std::set<T> vertices;
    std::set<Edge<T>*> edges;

    void bfs(T startVertex) {
        if (vertices.find(startVertex) != vertices.end()) {
            findNeighbors(startVertex);
        }
    }

private:
    bool isVisited(T vertex) {
        return vertex->visited;
    }

    void findNeighbors(T vertex) {
        if (isVisited(vertex)) return;

        vertex->visited = true;
        std::cout << "Visited vertex " << vertex->nodeID << std::endl;

        std::list<Vertice*> neighborsToVisit;
        for (Vertice* neighbor : vertex->neighbors) {
            if (!isVisited(neighbor)) {
                neighborsToVisit.push_back(neighbor);
            }
        }

        for (Vertice* neighbor : neighborsToVisit) {
            findNeighbors(neighbor);
        }
    }
};

int main() {
    Vertice v0(0), v1(1), v2(2), v3(3), v4(4);
    Edge<Vertice*> e1(&v0, &v1), e2(&v0, &v2), e3(&v1, &v3), e4(&v1, &v4), e5(&v2, &v4);

    Graph<Vertice*> graph;
    graph.vertices.insert(&v0);
    graph.vertices.insert(&v1);
    graph.vertices.insert(&v2);
    graph.vertices.insert(&v3);
    graph.vertices.insert(&v4);

    graph.edges.insert(&e1);
    graph.edges.insert(&e2);
    graph.edges.insert(&e3);
    graph.edges.insert(&e4);
    graph.edges.insert(&e5);

    graph.bfs(&v1);

    return 0;
}

