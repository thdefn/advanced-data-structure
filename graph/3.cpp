#include "ConnectedComponentGraph.h"
#include <cstdlib>
#include <ctime>
#include <vector>

void randomConnectedGraph(ConnectedComponentGraph *g, int numVtx, int numEdge);
int findBridge(ConnectedComponentGraph *g);

int main()
{
	ConnectedComponentGraph g;
	
     for(int i = 0; i < 5; i++)
        g.insertVertex('A' + i);

    g.insertEdge(0, 1);
    g.insertEdge(1, 2);
    g.insertEdge(2, 0);
    g.insertEdge(1, 3);
    g.insertEdge(3, 4);
	printf("%d \n", findBridge(&g));

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


int findBridge(ConnectedComponentGraph *g){
    return g -> findBridge();
}