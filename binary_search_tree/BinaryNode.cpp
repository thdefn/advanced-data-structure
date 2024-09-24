// BinaryNode.cpp
#include "BinaryNode.h"
#include <iostream>  // for printf()

void BinaryNode::inorder(){
		if(this != NULL){
			if(left != NULL) left -> inorder();
			printf( " [%2d]", data);
			if(right != NULL) right -> inorder();
		}
	}


	void BinaryNode::preorder(){
		if(this != NULL){
			printf( " [%2d]", data);
			if(left != NULL) left -> preorder();
			if(right != NULL) right -> preorder();
		}
	}


	void BinaryNode::postorder(){
		if(this != NULL){
			if(left != NULL) left -> postorder();
			if(right != NULL) right -> postorder();
			printf( " [%2d]", data);
		}
	}

	int BinaryNode::getCount() {
		if( this == NULL ) return 0;
		return 1 + left -> getCount() + right -> getCount();
	}


	int BinaryNode::getLeafCount() {
		if( this == NULL ) return 0;
		if(isLeaf() ) return 1;
		else return left -> getLeafCount() + right -> getLeafCount();
	}

	int BinaryNode::getHeight()	{
		if( this == NULL ) return 0;
		int	hLeft  = left -> getHeight();
		int	hRight = right -> getHeight();
		return (hLeft>hRight) ? hLeft+1 : hRight+1;
	}


	BinaryNode* BinaryNode::search(int key ) {
		if( this == NULL ) return NULL;

		if( key == data )
			return this;
		else if (key < data )
			return left -> search( key );
		else 
			return right ->  search( key );
	}



	void BinaryNode::insert( BinaryNode* n ) {
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
