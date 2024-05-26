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

    Edge(T source_V, T destinate_V) : p(source_V), q(destinate_V) {
        //p->neighbors.insert(q);
        //q->neighbors.insert(p);
        //elements.insert(p);
        //elements.insert(q);
    }
    Edge(){}

    void printEdgeNeighbors() {
        std::cout << "(" << p->nodeID << ", " << q->nodeID << ") has neighbors: ";
        for (typename std::set<Edge<T>*>::iterator e = neighbors.begin(); e != neighbors.end(); ++e) {
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
    Vertice* node=nullptr;
    Edge<Vertice*>** edges=nullptr;
    int rowCount, columnCount;

    std::set<T> makeEdgeSignature(T startVertice, T endVertice){
        std::set<T> edgeSignature;
        edgeSignature.insert(startVertice); 
        edgeSignature.insert(endVertice); 
        return edgeSignature;

    };
    
    int getEdgeDistance(T startVertice, T endVertice){
        int edgeDistance=superInt;       // a value beyond scope
        bool flag=false;
        //std::cout << "getEdgeDistance edges[" << startVertice->nodeID << "," << endVertice->nodeID <<"] " << std::endl;
        //if(endVertice->shortestDistanceFromStart == superInt) return superInt;
        //std::cout << "getEdgeDistance" << std::endl;
        for (int i = 0; i < rowCount; i++) {
            //std::cout << "edges row i = " << i << std::endl;
            for (int j = 0; j < columnCount; j++) { // avoid duplicate edges and self-loops
                //std::cout << "edges column j = " << j << std::endl;
                if(edges[i][j].p == startVertice && edges[i][j].q == endVertice){
                    //if(edges[i][j].distance == superInt) {bounfFlag=true; break;}
                    edgeDistance=edges[i][j].distance;
                    flag=true;
                    //std::cout << "edges[" << i << "," << j << "] distance = " <<edgeDistance<< std::endl;
                    break;
                }
            }
            if(flag==true) break;
        }
            //std::cout << "edges row i = " << i << std::endl;
        return edgeDistance;
    }

    bool findShortestPath(T startVertice, T endVertice){
       

        if (vSet.find(startVertice) == vSet.end()) return false;
        
        //bool flag=false;
        
        queue<Vertice*> q;
        startVertice->shortestDistanceFromStart = 0;    // ****  initial setting  ***** 
        q.push(startVertice);
        int nextDistance;

        while (!q.empty()) {
            Vertice* current = q.front();
            q.pop();
            
            cout << "current->nodeID   " << current->nodeID << std::endl;		
            cout << "current->neighbors.size()   " << current->neighbors.size() << std::endl;
            if(current->neighbors.size() == 0)	continue;
            for (set<Vertice*>::iterator neighbor= current->neighbors.begin(); 
				neighbor!=current->neighbors.end(); neighbor++) {
                if((*neighbor) == startVertice) continue;   
                //cout << " before (*neighbor)->shortestDistanceFromStart " << (*neighbor)->shortestDistanceFromStart<< std::endl;	
                //if((*neighbor)->shortestDistanceFromStart == superInt) continue;   
                //cout << "findShortestPath for loop  before nextDistance " << std::endl;	
                
                nextDistance=getEdgeDistance(startVertice,(*neighbor));

                if(nextDistance == superInt) continue;  // no edge

                //cout << "neighbor->nodeID   " << (*neighbor)->nodeID <<"   nextDistance = "<< nextDistance<<  std::endl;
                if((*neighbor)->shortestDistanceFromStart < 0 || (current->shortestDistanceFromStart+nextDistance < (*neighbor)->shortestDistanceFromStart)) {
                    (*neighbor)->shortestDistanceFromStart=	current->shortestDistanceFromStart+nextDistance;  
                    q.push((*neighbor)); 
                }
                    
                //else (*neighbor)->shortestDistanceFromStart= current->shortestDistanceFromStart+nextDistance;
                cout << " its neighbor " << (*neighbor)->nodeID << " shortest= "<< (*neighbor)->shortestDistanceFromStart <<std::endl;	
                //cout << " current->shortestDistanceFromStart+nextDistance " << current->shortestDistanceFromStart  <<std::endl;
                //cout << " nextDistance " << nextDistance  <<std::endl;
                cout << " (*neighbor)->shortestDistanceFromStart " << (*neighbor)->shortestDistanceFromStart  <<std::endl;

                
                 //{
                 //   (*neighbor)->visited = true;
                 //   q.push((*neighbor));
                //}
            }
        }

        
        return true;
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
        for (typename std::set<Edge<T>*>::iterator e1 = eSet.begin(); e1 != eSet.end(); ++e1) {
            std::cout<< "e1(" << (*e1)->p->nodeID<<"," <<(*e1)->q->nodeID<<") has neighbors: ";
            for (typename std::set<Edge<T>*>::iterator e2 = eSet.begin(); e2 != eSet.end(); ++e2) {
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


    void grapgInitilization(){
        typename std::vector<std::vector<int> > mat = {
            {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
            {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
            {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
            {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	    };
        
        rowCount=mat.size(), columnCount=mat[0].size();
        Matrix<int> A(rowCount, columnCount);


        A.printMatrix();

        int nodeNumber=rowCount>columnCount?rowCount:columnCount;
        node=new Vertice[nodeNumber];
        for(int i=0; i< nodeNumber; i++)
            node[i].nodeID=i;

        std::cout<< "nodeNumber= " << nodeNumber << std::endl;
        for(int i=0; i< nodeNumber; i++){
            node[i].nodeID=i;
            node[i].shortestDistanceFromStart=-1;    // a value beyond scope
            vSet.insert(&node[i]);
        }
        edges=new Edge<Vertice*>*[rowCount];
        for(int i=0; i<rowCount; i++)
            edges[i]=new Edge<Vertice*>[columnCount];

        for (int i = 0; i < rowCount; i++) {
            //std::cout << "edges row i = " << i << std::endl;
            for (int j = 0; j < columnCount; j++) { // avoid duplicate edges and self-loops
                //std::cout << "edges column j = " << j << std::endl;
                if ( (mat[i][j]) != 0 && i != j) edges[i][j].distance=mat[i][j];    
                else edges[i][j].distance=superInt;
                edges[i][j].p=&node[i];
                edges[i][j].q=&node[j];
                if((mat[i][j]) != 0) edges[i][j].p->neighbors.insert(&node[j]);
                //edges[i][j].q->neighbors.insert(&node[i]);

                    //std::cout << "edges[" << i << "," << j << "] = " <<mat[i][j]<< std::endl;
                
            }
            //std::cout << "edges row i = " << i << std::endl;
        }   

    

        //std::cout<< "row size " << edges.size() << std::endl;
        //std::cout<< "column size " << edges[0].size() << std::endl;
    
    };

    void printArray(){
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < columnCount; j++) { // avoid duplicate edges and self-loops
                std::cout << edges[i][j].distance<<", "; 
            }
            std::cout << std::endl;
        }        
    }

};

int main() {


    
    Graph<Vertice*> g;     
    g.grapgInitilization();
    g.printArray();
    


    //std::cout<< "rowCount " << rowCount << std::endl;
    //std::cout<< "columnCount " << columnCount << std::endl;


    

    //g.buildEdgeNeighbors();
    g.findShortestPath(&g.node[0], &g.node[4]);

    std::cout << "0 -> 4   shortest distance" << g.node[4].shortestDistanceFromStart <<  std::endl;

    

    
        
        

     //v0(0), v1(1), v2(2), v3(3), v4(4);
    //Edge<Vertice*> e1(&v0, &v1), e2(&v0, &v2), e3(&v1, &v3), e4(&v1, &v4), e5(&v2, &v4);


    int i;
    std::cin >> i;

    return 0;
}
