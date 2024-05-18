#include <iostream>
#include <list>

using namespace std;


class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

class Vertice{
private:
public:
    std::list<int> neighbors;
    int nodeID;    
    Vertice(int nodeID):nodeID(nodeID){
      std::cout<< "A p is "<< nodeID << std::endl;
    };
    
    void printList(){
    	std::cout<<"Node "<< nodeID <<" has neighbors ";
    	for(std::list<int>::iterator 
		    it=neighbors.begin(); it!=neighbors.end(); it++){
		    	std::cout<<*it<<", ";
			}
		std::cout<<std::endl;	
	}
};

template <typename T>
class E{
public:
    T p,q;
    E(T source_V, T destinate_V):p(source_V), q(destinate_V)
    {
        //q->nodeID=10;
        p->neighbors.push_back(q->nodeID);
        
        std::cout<< "E q is "<< q->nodeID << std::endl;        
    };
    

};

int main() {

    Vertice v1(1), v2(2), v3(3);
    

    E<Vertice*> e1(&v1, &v2);
    v1.printList();

    std::cout<< "3 p is "<< v1.nodeID << std::endl;
    
    //std::cout<< "3 q is "<< v2. << std::endl;


    int i;
    std::cin >> i;
 


  return 0;
}
