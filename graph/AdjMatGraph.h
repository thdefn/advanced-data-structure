#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX_VTXS	256

class AdjMatGraph
{
protected:
	int		size;						// ������ ����
	char	vertices[MAX_VTXS];			// ������ �̸�
	int		adj[MAX_VTXS][MAX_VTXS];	// ���� ���

public:
	AdjMatGraph( )				{ reset(); }
	~AdjMatGraph()				{  }

	char getVertex(int i)		{ return vertices[i]; }
	int	 getEdge(int i, int j)	{ return adj[i][j]; }
	void setEdge(int i, int j, int val)	{ adj[i][j] = val; }
	bool isEmpty()				{ return size==0; }
	bool isFull()				{ return size>=MAX_VTXS; }

	void reset() {
		size=0;
		for(int i=0 ; i<MAX_VTXS ; i++ )
		for(int j=0 ; j<MAX_VTXS ; j++ )
			setEdge(i,j,0);
	}

	void insertVertex( char name ) {
		if( !isFull() ) vertices[size++] = name;
		else printf("Error: �׷��� ������ ���� �ʰ�\n");
	}

	void insertEdge( int u, int v ) {
		setEdge(u,v,1);
		setEdge(v,u,1);
	}

	void display( FILE *fp = stdout) {
		fprintf(fp, "%d\n", size);				
		for( int i=0 ; i<size ; i++ ) {			
			fprintf(fp,"%c  ", getVertex(i));	
			for( int j=0 ; j<size ; j++ )		
				fprintf(fp, " %3d", getEdge(i,j));
			fprintf(fp,"\n");
		}
	}

	void load(const char *filename) {
		FILE *fp = fopen(filename, "r");
		if( fp != NULL ) {
			int n;
			fscanf(fp, "%d", &n);			
			for(int i=0 ; i<n ; i++ ) {
				char	str[80];
				int		val;
				fscanf(fp, "%s", str);		
				insertVertex( str[0] );		
				for(int j=0 ; j<n ; j++){
					fscanf(fp, "%d", &val);	
					if( val != 0 )			
						insertEdge (i,j);	
				}
			}
			fclose(fp);
		}
	}
	void store(const char *filename) {
		FILE *fp = fopen(filename, "w");
		if( fp != NULL ) {
			display( fp );
			fclose(fp);
		}
	}
};




