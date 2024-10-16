#include "AdjMatGraph.h"
#include <cstdlib>
#include <ctime>

void randomGraph(AdjMatGraph *g, int numVtx, int numEdge);

int main()
{
	AdjMatGraph g;
	
	randomGraph(&g, 5, 7);

	printf("Graph creation completed\n");
	g.display();

	return 0;
}


void randomGraph(AdjMatGraph *g, int numVtx, int numEdge){
	if(numEdge < numVtx - 1 || numEdge > numVtx * (numVtx - 1) / 2) {
		   printf("Error: Exceeds the possible number of edges\n");
		return;
	}

	for( int i=0 ; i<numVtx ; i++ )
		g -> insertVertex( 'A'+i );

	 srand(static_cast<unsigned int>(time(0)));

	while(numEdge > 0){
		int a = rand() % numVtx;
		int b = rand() % numVtx;

		if(a != b && g -> getEdge(a, b) == 0){
			g -> insertEdge(a, b);
			numEdge--;
		}
	}
}