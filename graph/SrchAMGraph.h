#pragma once
#include "AdjMatGraph.h"
#include "CircularQueue.h"

class SrchAMGraph : public AdjMatGraph
{
protected:
	bool	visited[MAX_VTXS];	

public:
	void resetVisited() {		
		for( int i=0 ; i<size ; i++ )
			visited[i] = false;
	}
	bool isLinked(int u, int v) { return getEdge(u,v) != 0; }

	// ���� �켱 Ž��
	void DFS( int v) {
		visited[v] = true;		
		printf("%c ", getVertex(v));	

		for( int w=0 ; w<size ; w++) 
 			if( isLinked(v,w) && visited[w]==false )
				DFS( w );
	}

	// �ʺ� �켱 Ž��
	void BFS( int v) {
		visited[v] = true;				
		printf("%c ", getVertex(v));	

		CircularQueue que;
		que.enqueue( v );				

 		while(!que.isEmpty()){
 			int v = que.dequeue();	
    		for(int w=0; w<size; w++)	{
 				if( isLinked(v,w) && visited[w]==false){ 
   					visited[w] = true;	
					printf("%c ", getVertex(w));
					que.enqueue(w);		
     		}
		}
	}
};


};