#include <iostream>
#include <list>
#include <set>
/*   (*it)->nodeID   */
using namespace std;


class Vertice{
private:
public:
    bool visited; 
    std::list<Vertice*> neighbors;    // <Vertice*> is used as <typename T> in teh whole program
    
    int nodeID;    
    Vertice(int nodeID):nodeID(nodeID){
      visited=false;
      std::cout<< "vertics is "<< nodeID << std::endl;
    };
    
    void printList(){
    	std::cout<<"Node "<< nodeID <<" has neighbors ";
    	for(std::list<Vertice*>::iterator 
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
    std::list<Edge> neighborEdges;
    
    Edge(T source_V, T destinate_V):p(source_V),  q(destinate_V)
    {
        visited=false;
        p->neighbors.push_back(q);
        q->neighbors.push_back(p);
        //std::cout<< "E q is "<< q->nodeID << std::endl;        
    };
	void setEdgeVisited(T source_V, T destinate_V){
		if(source_V==p && destinate_V==q) visited=true;
	}
	bool isEdgeVisited(T source_V, T destinate_V){
		bool flag=false;
		if(source_V==p && destinate_V==q)
			if (visited==true) flag=true;
		return flag;
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
	std::set<Edge<T>* > eSet; 
  	void euler(T startVertex){
  		
		if (vSet.find(startVertex) != vSet.end()){
      
			findEdges(startVertex);
    	};
	}
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
		int min=INT_MAX;
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
		T p,q;
		for(typename std::set<T>::iterator 
			it=vSet.begin(); 
			it!=vSet.end(); 
			++it)
				if((*it)== startVertice) printEdges(startVertice);
	}
	
	bool printEdges(T startVertex){
		if (isVerticeVisited(startVertex)) return true;
		else (*startVertex).visited=true;
		T nextVertex;
    	std::cout<<(*startVertex).nodeID <<" has unvisited neighbors  ";
		for(std::list<Vertice*>::iterator 
			it=(*startVertex).neighbors.begin(); 
			it!=(*startVertex).neighbors.end(); 
			++it){
				if (isVerticeVisited(*it)) continue;
				nextVertex=(*it);
				std::cout<<nextVertex->nodeID <<", ";
			} 
		std::cout<<endl;
		std::cout
			<<" vistited edge (" 
			<<startVertex->nodeID
			<<","<<nextVertex->nodeID
			<< ")"
			<<endl;	
			
		printEdges(nextVertex);
		return true;				
	}
  
};

int main() {
	
    Vertice v0(0), v1(1), v2(2), v3(3);
    
    Edge<Vertice*> 
    e1(&v0, &v1),
    e2(&v0, &v2),
    e3(&v1, &v2),
    e4(&v2, &v3);
    v0.printList();
    v1.printList();
    
    
    Graph<Vertice*> g;
    g.vSet.insert(&v0);
    g.vSet.insert(&v1);
    g.vSet.insert(&v2);
    g.vSet.insert(&v3);
    


    g.eSet.insert(&e1);
    g.eSet.insert(&e2);
    g.eSet.insert(&e3);
    g.eSet.insert(&e4);
	Vertice* x;
	if(g.isEulerPath()){
		x=g.getStartVertice();
    	std::cout<<"Double check the start vertice "<< x->nodeID <<endl;
    	g.printEulerPath(x);
	}
    


    int i;
    std::cin >> i;
 


  return 0;
}
