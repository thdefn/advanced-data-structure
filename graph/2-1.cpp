#include "ConnectedComponentGraph.h"
#include <cstdlib>
#include <ctime>
#include <vector>

void randomConnectedGraph(ConnectedComponentGraph *g, int numVtx, int numEdge);

int main()
{
	ConnectedComponentGraph g;
	
	randomConnectedGraph(&g, 5, 7);
    g.resetVisited();
	g.DFS(0);


	return 0;
}

void randomConnectedGraph(ConnectedComponentGraph *g, int numVtx, int numEdge) {
    if(numEdge < numVtx - 1 || numEdge > numVtx * (numVtx - 1) / 2) {
        printf("Error: Possible edge count exceeded\n");
        return;
    }

    for(int i = 0; i < numVtx; i++)
        g->insertVertex('A' + i);

    srand(static_cast<unsigned int>(time(0)));
    std::vector<std::pair<int, int> > edges;

    for (int i = 0; i < numVtx - 1; i++) {
        g->insertEdge(i, i + 1);
        edges.emplace_back(i, i + 1);
    }

    while (edges.size() < numEdge) {
        int a = rand() % numVtx;
        int b = rand() % numVtx;

        if (a != b && g->getEdge(a, b) == 0) {
            g->insertEdge(a, b);
            edges.emplace_back(a, b);
        }
    }
}