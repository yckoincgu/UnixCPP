#include <iostream>
#include <list>
#include <set>
/*   (*it)->nodeID   */
using namespace std;

class Vertice{
private:
public:
    std::list<Vertice*> neighbors;
    
    int nodeID;    
    Vertice(int nodeID):nodeID(nodeID){
      std::cout<< "A p is "<< nodeID << std::endl;
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
        //Graph::eLists
        std::cout<< "E q is "<< q->nodeID << std::endl;        
    };
};

template <typename T>
class Graph {

   public:
   	std::set<T> vSet;
	std::set<Edge<T>*> eSet;
  	void BFS(T startVertex);
  
};

int main() {
	
    Vertice v0(0), v1(1), v2(2);
    Edge<Vertice*> 
    e1(&v0, &v1),
    e2(&v0, &v2),
    e3(&v1, &v0),
    e4(&v1, &v2),
    e5(&v2, &v1),
    e6(&v2, &v0);
    Graph<Vertice*> g;
    g.vSet.insert(&v0);
    g.vSet.insert(&v1);
    g.vSet.insert(&v2);    
    g.eSet.insert(&e1);
    g.eSet.insert(&e2);
    g.eSet.insert(&e3);
    g.eSet.insert(&e4);
    g.eSet.insert(&e5);
    g.eSet.insert(&e6);
    
    
    v1.printList();
    v2.printList();
    v0.printList();

    //std::cout<< "3 p is "<< v1.nodeID << std::endl;
    
    //std::cout<< "3 q is "<< v2. << std::endl;


    int i;
    std::cin >> i;
 


  return 0;
}
