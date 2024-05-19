#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
int startVertex = 0;
    
struct Graph {
    int vertices;
    int edges[MAX_VERTICES][MAX_VERTICES];
};

struct Graph createGraph(int vertices) {
    struct Graph graph;
    graph.vertices = vertices;
	int i,j ;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph.edges[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    graph->edges[u][v] = 1;
    graph->edges[v][u] = 1;
}

void removeEdge(struct Graph* graph, int startNode, int endNode) {
    graph->edges[startNode][endNode] = 0;
    graph->edges[endNode][startNode] = 0;
}

bool isBridge(struct Graph* graph, int startNode, int endNode) {
    int degree = 0;
	int j;
	bool checkResult=false;
	
    for (j = 0; j < graph->vertices; j++) {
        if (graph->edges[endNode][j] == 1) {
            degree++;
        }
    }
	switch(degree) {
		case 1:	checkResult = true; // Removing this edge would disconnect the graph
				break;
		default:
			if (degree % 2 == 0) checkResult = true;
	}
    return checkResult;
}

void eulerianCheck(struct Graph* graph, int startNode) {
	int j; 
    for (j = 0; j < graph->vertices; j++) {
        if (graph->edges[startNode][j]==1 && isBridge(graph, startNode, j)) {
        	if(j == startVertex) printf("%d --> %d: This is an eulerian circuit\n", startNode, j);
        	else printf("%d --> %d, ", startNode, j);
            removeEdge(graph, startNode, j);
            eulerianCheck(graph, j);
         }
    }
}

void eulerianCircuit(struct Graph* graph) {

	int i, j;
    for (i = 0; i < graph->vertices; i++) {
        int degree = 0;
        for (j = 0; j < graph->vertices; j++) {
            degree += graph->edges[i][j];
        }

        if (degree % 2 != 0) {
            startVertex = i;
            break;
        }
    }

    eulerianCheck(graph, startVertex);
    printf("\n");
}

int main() {
    struct Graph graph_1 = createGraph(4);

    addEdge(&graph_1, 0, 1);
    addEdge(&graph_1, 0, 2);
    addEdge(&graph_1, 1, 2);
    addEdge(&graph_1, 2, 3);

    printf("Eulerian Circuit: ");
    eulerianCircuit(&graph_1);
    
    struct Graph g1 = createGraph(5);
    addEdge(&g1, 1, 0);
    addEdge(&g1, 0, 2);
    addEdge(&g1, 2, 1);
    addEdge(&g1, 0, 3);
    addEdge(&g1, 3, 4);
   	printf("g1: \n");
    eulerianCircuit(&g1);

    return 0;
}

