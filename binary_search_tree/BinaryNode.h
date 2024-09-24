#pragma once
#include <stdio.h>

class BinaryNode
{
protected:
	int			data;
	BinaryNode	*left;
	BinaryNode	*right;
public:
	BinaryNode( int val=0, BinaryNode *l=NULL, BinaryNode *r=NULL)
			: data(val), left(l), right(r) { }
	~BinaryNode()	{ }

	void		setData ( int val )		{ data	= val; }
	void		setLeft (BinaryNode *l)	{ left	= l; }
	void		setRight(BinaryNode *r)	{ right	= r; }
	int			getData ()				{ return data; }	
	BinaryNode*	getLeft ()				{ return left; }	
	BinaryNode*	getRight()				{ return right; }	
	bool		isLeaf()	{ return left==NULL && right==NULL; }
	void inorder(){
		if(this != NULL){
			if(left != NULL) left -> inorder();
			printf( " [%2d]", data);
			if(right != NULL) right -> inorder();
		}
	}


	void preorder(){
		if(this != NULL){
			printf( " [%2d]", data);
			if(left != NULL) left -> preorder();
			if(right != NULL) right -> preorder();
		}
	}


	void postorder(){
		if(this != NULL){
			if(left != NULL) left -> postorder();
			if(right != NULL) right -> postorder();
			printf( " [%2d]", data);
		}
	}

	int getCount() {
		if( this == NULL ) return 0;
		return 1 + left -> getCount() + right -> getCount();
	}


	int getLeafCount() {
		if( this == NULL ) return 0;
		if(isLeaf() ) return 1;
		else return left -> getLeafCount() + right -> getLeafCount();
	}

	int getHeight()	{
		if( this == NULL ) return 0;
		int	hLeft  = left -> getHeight();
		int	hRight = right -> getHeight();
		return (hLeft>hRight) ? hLeft+1 : hRight+1;
	}


	BinaryNode* search(int key ) {
		if( this == NULL ) return NULL;

		if( key == data )
			return this;
		else if (key < data )
			return left -> search( key );
		else 
			return right ->  search( key );
	}



	void insert( BinaryNode* n ) {
		if( n->getData() == data ) 
			return;
		else if( n->getData() < data ) {
			if( left == NULL )
				left = n;
			else
				left -> insert(n );
		}
		else {
			if( right == NULL )
				right = n;
			else
				right -> insert(n);
		}
	}

};

