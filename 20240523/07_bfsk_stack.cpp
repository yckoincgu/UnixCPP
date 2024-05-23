#include <iostream>
#include <list>
#include <set>
#include <stack>

/*   (*it)->nodeID   */
using namespace std;

class Vertice{
private:
public:
    bool visited=false; 
    std::list<Vertice*> neighbors;
    
    int nodeID;    
    Vertice(int nodeID):nodeID(nodeID){
      //std::cout<< "A p is "<< nodeID << std::endl;
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
    Edge(T source_V, T destinate_V):p(source_V), q(destinate_V)
    {
        p->neighbors.push_back(q);
        q->neighbors.push_back(p);
        //std::cout<< "E q is "<< q->nodeID << std::endl;        
    };
};

template <typename T>
class Graph {
  public:
  std::set<T> vSet;
  std::set<Edge<T>*> eSet;
  void bfs(T startVertex){
		  if (vSet.find(startVertex) != vSet.end()) findNeighbors(startVertex);
	}
  
	bool isVisited(T startVertex){
    bool flag=false;
		if((*startVertex).visited) flag=true;
		return flag; 
	}

  bool unvisitedVerticesExist(T startVertice){
    bool flag=false;
    
    for(std::list<Vertice*>::iterator it=(*startVertice).neighbors.begin(); it!=(*startVertice).neighbors.end(); ++it)
      if (!isVisited(*it)) flag=true;;

    return flag;
  }

	bool findNeighbors(T startVertice){
		
		T visitedVertice;
		std::stack<T> neighborToVisit;
    
    neighborToVisit.push(startVertice);  

    while(!neighborToVisit.empty()){
      visitedVertice=neighborToVisit.top();
      neighborToVisit.pop();     

      if (!isVisited(visitedVertice)) std::cout<< "visited vertice "<< (*visitedVertice).nodeID<<endl;
      else if(!unvisitedVerticesExist(visitedVertice)) continue;
      (*visitedVertice).visited=true;
      
      for(std::list<Vertice*>::iterator it=(*visitedVertice).neighbors.begin(); it!=(*visitedVertice).neighbors.end(); ++it){
        if (isVisited(*it)) continue;
        else std::cout<< "visited vertice "<< (*it)->nodeID<<endl;
        neighborToVisit.push(*it);
        (*it)->visited=true;

      } 
    }  
	  return true;					
	}
  
  
};

int main() {
	
    Vertice v0(0), v1(1), v2(2), v3(3), v4(4);
    Edge<Vertice*> 
    e1(&v0, &v1),
    e2(&v0, &v2),
    e3(&v2, &v3),
    e4(&v1, &v4),
    e5(&v2, &v4);
    
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
    g.bfs(&v1);
  
    int i;
    std::cin >> i;
 


  return 0;
}
