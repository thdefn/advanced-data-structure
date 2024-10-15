#include "AdjMatGraph.h"
#include <cstdlib>
#include <ctime>

void randomGraph(AdjMatGraph *g, int numVtx, int numEdge);

int main()
{
	AdjMatGraph g;
	
	randomGraph(&g, 5, 7);

	printf("인접 행렬로 표현한 그래프\n");
	g.display();

	return 0;
}


void randomGraph(AdjMatGraph *g, int numVtx, int numEdge){
	if(numEdge < numVtx - 1 || numEdge > numVtx * (numVtx - 1) / 2) {
		printf("가능한 간선 개수 error\n");
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