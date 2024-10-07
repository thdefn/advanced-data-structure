#include "AdjMatGraph.h"

int main()
{
	AdjMatGraph g;
	
	for( int i=0 ; i<10 ; i++ )
		g.insertVertex( 'A'+i );

	g.insertEdge(0, 2);
	g.insertEdge(0, 5);
	g.insertEdge(1, 4);
	g.insertEdge(1, 6);
	g.insertEdge(2, 7);
	g.insertEdge(3, 8);
	g.insertEdge(3, 9);
	g.insertEdge(4, 8);
	g.insertEdge(5, 6);
	g.insertEdge(7, 9);


	printf("인접 행렬로 표현한 그래프\n");
	g.display();

	return 0;
}