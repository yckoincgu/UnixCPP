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
    std::list<Vertice> neighbors;
    int nodeID;    
    Vertice(int nodeID):nodeID(nodeID){
      std::cout<< "A p is "<< nodeID << std::endl;

    };
};

template <typename T>
class E{
public:
    T p,q;
    E(T source_V, T destinate_V):p(source_V), q(destinate_V)
    {

        std::cout<< "E p is "<< p.nodeID << std::endl;
        std::cout<< "E p is "<< q.nodeID << std::endl;
        //q.nodeID=2;
        p.neighbors.push_back(q);
    };
    

};

int main() {

    Vertice v1(1), v2(2), v3(3);
    //std::cout<< "1 p is "<< v1.nodeID << std::endl;
    //std::cout<< "1 q is "<< v2.nodeID << std::endl;

    E<Vertice> e1(v1, v2);
    //e1.p.neighbors

    std::cout<< "3 p is "<< v1.nodeID << std::endl;
    std::cout<< "3 q is "<< v2.nodeID << std::endl;


    int i;
    std::cin >> i;
 


  return 0;
}
