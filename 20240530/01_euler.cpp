#include <iostream>
#include <list>
#include <set>
#include<limits.h>
/*   (*it)->nodeID   */
using namespace std;


class Vertice{
private:
public:
    bool visited; 
    std::set<Vertice*> neighbors;    // <Vertice*> is used as <typename T> in teh whole program
    
    int nodeID;    
    Vertice(int nodeID):nodeID(nodeID){
      visited=false;
      std::cout<< "vertics is "<< nodeID << std::endl;
    };
    
    void printList(){
    	std::cout<<"Node "<< nodeID <<" has neighbors ";
    	for(std::set<Vertice*>::iterator 
		    it=neighbors.begin(); it!=neighbors.end(); it++){
				std::cout<<(*it)->nodeID<<", ";
			}
		std::cout<<std::endl;	
	}
};

template <typename T>
class Edge{
public:
    T p,q;
    bool visited; 
    std::set<T> undirectedEdge;
    
    Edge(T source_V, T destinate_V):p(source_V),  q(destinate_V)
    {
        visited=false;
        p->neighbors.insert(q);
        q->neighbors.insert(p);
		undirectedEdge.insert(p); undirectedEdge.insert(q);
        //std::cout<< "E q is "<< q->nodeID << std::endl;        
    };

};



template <typename T>
class Graph {
	public:
    std::set<T> vSet;
    /*	std::set<Edge<T>* > eSet; 
    	Use space between closing angle brackets in std::set<Edge<T> > 
		for older compiler compatibility.
	*/ 
	std::set<set<T> > eSet; 

	bool isVerticeVisited(T startVertex){
		bool flag;
		if(startVertex->visited) flag=true;
		return flag; 
	}
	bool isEulerPath(){
		bool flag=false;
		int oddVerticeNumber=0;
		for(typename std::set<T>::iterator 
			it=vSet.begin(); 
			it!=vSet.end(); 
			++it)
				if((*it)->neighbors.size() % 2 != 0) oddVerticeNumber++;
			 
		std::cout<<"oddVerticeNumber is " << oddVerticeNumber<< endl;	
		if(oddVerticeNumber % 2 == 0) {
			flag=true;
			std::cout<<"This graph is an euler path" <<endl;
		}
		
		return flag;
			
	}	
	T getStartVertice(){
		T x;
		unsigned long long min=UINT_MAX;
		for(typename std::set<T>::iterator 
			it=vSet.begin(); 
			it!=vSet.end(); 
			++it)
				if((*it)->neighbors.size() % 2 != 0 && min > (*it)->neighbors.size()) {
					min=(*it)->neighbors.size();
					x=(*it);
				}
		std::cout<<"The start vertice is "<< x->nodeID <<endl;
		return x;
	}
	void printEulerPath(T startVertice){
		T nextVertex;
		std::set<T> targetEdge; 
		for(typename std::set<T>::iterator 
			it=vSet.begin(); 
			it!=vSet.end(); 
			++it)
				if((*it)== startVertice) {
					//std::cout<<(*startVertice).nodeID <<" has unvisited neighbors  ";
					for(std::set<Vertice*>::iterator 
						it=(*startVertice).neighbors.begin(); 
						it!=(*startVertice).neighbors.end(); 
						++it){
							targetEdge.clear();
							targetEdge.insert(startVertice); targetEdge.insert(*it);
							if (eSet.find(targetEdge) != eSet.end())
							//if (isVerticeVisited(*it)) continue;
							nextVertex=(*it);
							//std::cout<<nextVertex->nodeID <<", ";
						} 
					//std::cout<<endl;

					//printEdges(startVertice, nextVertex);
					targetEdge.clear();
					targetEdge.insert(startVertice); targetEdge.insert(nextVertex);
					if (eSet.find(targetEdge) != eSet.end()) {
						printEdges(startVertice, nextVertex);
						eSet.erase(targetEdge);
						if(!eSet.empty()) printEulerPath(nextVertex);
					}
				}
	}
	
	void printEdges(T startVertice, T endVertice){
		std::cout
			<<" vistited edge (" 
			<<startVertice->nodeID
			<<","<<endVertice->nodeID
			<< ")"
			<<endl;	
	}
  
};

int main() {
	
    Vertice v0(0), v1(1), v2(2), v3(3);
    
    Edge<Vertice*> 
    e1(&v0, &v1), e11(&v1, &v0),
    e2(&v0, &v2), e12(&v2, &v0),
    e3(&v1, &v2), e13(&v2, &v1),
    e4(&v2, &v3), e14(&v3, &v2);
    //v0.printList();
    //v1.printList();
    
    
    Graph<Vertice*> g;
    g.vSet.insert(&v0);
    g.vSet.insert(&v1);
    g.vSet.insert(&v2);
    g.vSet.insert(&v3);
    


    g.eSet.insert(e1.undirectedEdge); g.eSet.insert(e11.undirectedEdge);
    g.eSet.insert(e2.undirectedEdge); g.eSet.insert(e12.undirectedEdge);
    g.eSet.insert(e3.undirectedEdge); g.eSet.insert(e13.undirectedEdge);
    g.eSet.insert(e4.undirectedEdge); g.eSet.insert(e14.undirectedEdge);



	Vertice* x;
	if(g.isEulerPath()){
		x=g.getStartVertice();
    	//std::cout<<"Double check the start vertice "<< x->nodeID <<endl;
    	g.printEulerPath(x);}
	else std::cout<<"This is not a euler path"<<endl;
    


    int i;
    std::cin >> i;
 


  return 0;
}
