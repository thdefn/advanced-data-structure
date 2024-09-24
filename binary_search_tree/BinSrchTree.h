#pragma once
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public:
	BinSrchTree(void) { }
	~BinSrchTree(void){ }

	// changed
	BinaryNode* search( int key ) {
		BinaryNode* node = root -> search ( key );

		if( node != NULL )
			printf("search success: Node with key %d found = 0x%p\n", node -> getData(), node );
		else
			printf("search fail: Node with key %d not found\n", key );
		return node;
	}

	BinaryNode* search( BinaryNode *n, int key ) {
		if( n == NULL ) return NULL;

		if( key == n->getData() )
			return n;
		else if (key < n->getData() )
			return search( n->getLeft(), key );
		else 
			return search( n->getRight(), key );
	}


	// changed
	void insert( BinaryNode* n ) {
		if( n == NULL ) return;
		if( isEmpty() )
			root = n;
		else
			root -> insert(n);
	}


	void insert( BinaryNode* r, BinaryNode* n ) {
		if( n->getData() == r->getData() ) 
			return;
		else if( n->getData() < r->getData() ) {
			if( r->getLeft() == NULL )
				r->setLeft(n);
			else
				insert( r->getLeft(), n );
		}
		else {
			if( r->getRight() == NULL )
				r->setRight(n);
			else
				insert( r->getRight(), n );
		}
	}


	void remove (int data) {
		if( isEmpty() ) return;					

		BinaryNode *parent = NULL;		
		BinaryNode *node = root;		
		while( node != NULL && node->getData() != data ) {
			parent = node;
			node = (data < node->getData())
					? node->getLeft()
					: node->getRight();
		}

		if( node == NULL ) {
			printf(" Error: key is not in the tree!\n");
			return;
		}
		else remove ( parent, node );
	}
	void remove (BinaryNode *parent, BinaryNode *node) {

		// case 1
		if( node->isLeaf() ) {
			if( parent == NULL ) root = NULL;
			else {
				if( parent->getLeft() == node )
					parent->setLeft(NULL);
				else
					parent->setRight(NULL);
			}
		}
		// case 2
		else if( node->getLeft()== NULL|| node->getRight()==NULL ) {
			BinaryNode *child = (node->getLeft() != NULL )
								? node->getLeft()
								: node->getRight();
			if( node == root )
				root = child;
			else {
				if( parent->getLeft() == node )
					parent->setLeft(child); 
				else 
					parent->setRight(child); 
			}
		}
		// case 3
		else {
			BinaryNode* succp = node;
			BinaryNode* succ = node->getRight();
			while (succ->getLeft() != NULL) {
				succp = succ;
				succ = succ->getLeft();
			}

			if( succp->getLeft() == succ )
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());

			node = succ;
		}
		delete node;
	}
};

