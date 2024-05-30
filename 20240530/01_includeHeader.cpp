#include "Matrix.h"
#include <iostream>
#include <vector>
#include <set>
#include<queue>
#include <climits>
int superInt=INT_MAX/10;

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
        for (std::set<Vertice*>::iterator it = neighbors.begin(); it != neighbors.end(); ++it) {
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
    std::set<T> elements;
    int distance;
    bool visited=false;

    Edge(T source_V, T destinate_V) : p(source_V), q(destinate_V) {}
    Edge(){}


};

template <typename T>
class Graph {
public:
    std::set<T> vSet;
    std::set<Edge<T>*> eSet;
    Vertice* node;
    Edge<Vertice*>** edges;
    int rowCount, columnCount;


    




    



    void grapgInitilization(){
        int mat[9][9] = {
            { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
            { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
            { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
            { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
            { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
            { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
            { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
            { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
            { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
	    };

/*
               0  1  2  3  4  5  6  7  8
          0  { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
          1  { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
          2  { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
          3  { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
          4  { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
          5  { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
          6  { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
          7  { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
          8  { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 

*/        
        
        rowCount=9, 
		columnCount=9;
        Matrix<int> A(rowCount, columnCount);





        for (int i = 0; i < rowCount; i++)             
            for (int j = 0; j < columnCount; j++) 
                A.matrix[i][j]=mat[i][j];

        A.printMatrix();      
    }
};

int main() {


    
    Graph<Vertice*> g;     
    g.grapgInitilization();
    
    


    //std::cout<< "rowCount " << rowCount << std::endl;
    //std::cout<< "columnCount " << columnCount << std::endl;


    

    int i;
    std::cin >> i;

    return 0;
}
