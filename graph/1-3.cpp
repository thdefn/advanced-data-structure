#include "ConnectedComponentGraph.h"
#include <cstdlib>
#include <ctime>

void randomConnectedGraph(ConnectedComponentGraph *g, int numVtx, int numEdge);

int main()
{
	ConnectedComponentGraph g;
	
	randomConnectedGraph(&g, 5, 7);
	printf("연결 성분 테스트 그래프\n");
	g.display();

	g.resetVisited();
	g.findConnectedComponent( );


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

    for (int i = 0; i < numVtx - 1; i++) {
        g->insertEdge(i, i + 1);
		numEdge--;
    }

    while (numEdge > 0) {
        int a = rand() % numVtx;
        int b = rand() % numVtx;

        if (a != b && g->getEdge(a, b) == 0) {
            g->insertEdge(a, b);
			numEdge--;
        }
    }
}