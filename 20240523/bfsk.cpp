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

class V{
private:
    
   
public:
    std::list<V> neighbors;
    int nodeID;    
    V(int node){};
};

template <typename T>
class E{
public:
    T p,q;
    E(T source_V, T destinate_V):p<T>(source_V), q<T>(destinate_V){
        p.nodeID=1; q.nodeID=2;
        p.neighbors.push_back(q);
    };
    

};

int main() {

    V v1(1), v2(2), v3(3);
    E<V*> e1(&v1, &v2);
    //e1.p.neighbors

    std::cout<< " p is "<< v1.nodeID << std::endl;
    std::cout<< " q is "<< v2.nodeID << std::endl;


    int i;
    std::cin >> i;
 


  return 0;
}