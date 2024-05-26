#include "Matrix.h"
#include <iostream>
#include <vector>
#include <set>
#include<queue>
#include <climits>


using namespace std;

class Vertice {
public:
    bool visited = false;
    std::set<Vertice*> neighbors;
    int nodeID;
    int shortestDistanceFromStart;

    Vertice(int nodeID) : nodeID(nodeID) {}
    Vertice() {}
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
    std::set<T> signature;
    int distance;
    bool visited=false;

    Edge(T source_V, T destinate_V) : p(source_V), q(destinate_V) {
        p->neighbors.insert(q);
        q->neighbors.insert(p);
        signature.insert(p);
        signature.insert(q);
    }
    Edge(){}

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
    
    int getEdgeDistance(T startVertice, T endVertice){
        int edgeDistance=INT_MAX / 2;       // a value beyond scope
        std::set<T> searchEdge;
        searchEdge.insert(startVertice); 
        searchEdge.insert(endVertice); 
        for(typename std::set<Edge<T>*>::iterator targetEdge=eSet.begin(); targetEdge != eSet.end(); ++targetEdge)
            if( (*targetEdge)->signature == searchEdge) edgeDistance=(*targetEdge)->distance;

        return edgeDistance;

    }
    T findShortestPath(T startVertice, T endVertice){
        std::cout<< "findShortestPath ..." << std::endl;

        if (vSet.find(startVertice) == vSet.end()) return NULL;
        //bool flag=false;
        
        queue<Vertice*> q;
        startVertice->shortestDistanceFromStart = 0;    // ****  initial setting  ***** 
        q.push(startVertice);
        int nextDistance;

        while (!q.empty()) {
            Vertice* current = q.front();
            q.pop();
            
            cout << "Visited vertex " << current->nodeID << endl;			
            for (set<Vertice*>::iterator neighbor= current->neighbors.begin(); 
				neighbor!=current->neighbors.end(); ++neighbor) {
                if((*neighbor) == startVertice) continue;   

                nextDistance=getEdgeDistance(startVertice,(*neighbor));
                if(current->shortestDistanceFromStart+nextDistance > (*neighbor)->shortestDistanceFromStart) continue;    
                else (*neighbor)->shortestDistanceFromStart= current->shortestDistanceFromStart+nextDistance;
                q.push((*neighbor));
                 //{
                 //   (*neighbor)->visited = true;
                 //   q.push((*neighbor));
                //}
            }
        }

        
        return endVertice;
    }
    void bfs(Vertice* startVertice) {
        if (vSet.find(startVertice) == vSet.end()) return;
        
        queue<Vertice*> q;
        startVertice->visited = true;
        q.push(startVertice);

        while (!q.empty()) {
            Vertice* current = q.front();
            q.pop();
            
            cout << "Visited vertex " << current->nodeID << endl;			
            for (set<Vertice*>::iterator neighbor= current->neighbors.begin(); 
				 neighbor!=current->neighbors.end(); ++neighbor) {
                if (!(*neighbor)->visited) {
                    (*neighbor)->visited = true;
                    q.push((*neighbor));
                }
            }
        }
    }
    
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

    std::vector<std::vector<int>> mat = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    int rowCount, columnCount;
    rowCount=mat.size(), columnCount=mat[0].size();
    Matrix<int> A(rowCount, columnCount);
    A.printMatrix();
    
    Graph<Vertice*> g;     

    Vertice node[rowCount];
    for(int i=0; i< rowCount; i++){
        node[i].nodeID=i;
        node[i].shortestDistanceFromStart=INT_MAX/2;    // a value beyond scope
        g.vSet.insert(&node[i]);
    }

      
    vector<vector<Edge<Vertice*>*>> edges(rowCount, vector<Edge<Vertice*>*>(columnCount, nullptr));
    
    for (int i = 0; i < rowCount; i++) {
        for (int j = i + 1; j < columnCount; j++) { // avoid duplicate edges and self-loops
            edges[i][j] = new Edge<Vertice*>(&node[i], &node[j]);
            if(mat[i][j] != 0) edges[i][j]=NULL;
            else edges[i][j]->distance=mat[i][j];
            g.eSet.insert(edges[i][j]);

        }
    }

    std::cout<< "g.eSet.insert(edges[i][j]);" << std::endl;

    g.buildEdgeNeighbors();
    g.findShortestPath(&node[0], &node[4]);
    std::cout<< "shortest path"<< node[4].shortestDistanceFromStart<< std::endl;

     //v0(0), v1(1), v2(2), v3(3), v4(4);
    //Edge<Vertice*> e1(&v0, &v1), e2(&v0, &v2), e3(&v1, &v3), e4(&v1, &v4), e5(&v2, &v4);


    int i;
    std::cin >> i;

    return 0;
}
