#pragma once
#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph
{
	int		label[MAX_VTXS];	// 정점의 색상
public:
	void labelDFS( int v, int color) {
		visited[v] = true;				
		label[v] = color;				
		//printf("%c ", getVertex(v));	

		for( int w=0 ; w<size ; w++) 
 			if( isLinked(v,w) && visited[w]==false )
				labelDFS( w, color );
	}


	void findConnectedComponent( ) {
		int count = 0;					
		for(int i=0; i<size ; i++)
			if( visited[i]==false){    
		   		labelDFS(i, ++count);
			}

		printf("\n그래프 연결성분 개수 = = %d\n", count);
		for( int i=0 ; i<size ; i++ )
			printf( "%c=%d ", getVertex(i), label[i] );
		printf( "\n" );
	}

	bool isConnectedGraph() {
    	resetVisited();
   		int count = 0;					
    	for (int i = 0; i < size; i++) {
        	if (!visited[i]) {    
            	labelDFS(i, ++count);
        	}
   		 }

    	return count == 1;
	}

	int findBridge() {
    	int count = 0;
    	for (int i = 0; i < size; i++) {
        	for (int j = i + 1; j < size; j++) {
            	if (!getEdge(i, j)) continue; // 엣지가 없으면 건너뛰기

            	// 엣지 제거
            	setEdge(i, j, 0);
            	setEdge(j, i, 0);

            	// 연결성 확인
            	if (!isConnectedGraph()) {
                count++; // 브리지로 확인된 경우
            }

            // 엣지 복원
            setEdge(i, j, 1);
            setEdge(j, i, 1);
        }
    }
    return count; // 총 브리지 수 반환
}
};

