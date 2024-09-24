#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"

class BinaryTree
{
protected:
	BinaryNode*	root;
public:

	BinaryTree(): root(NULL) { }
	~BinaryTree()	{ }

	void setRoot(BinaryNode* node)	{ root = node; }
	BinaryNode* getRoot()			{ return root; }
	bool isEmpty()	{ return root==NULL; }

	int	getCount()	{ return isEmpty() ? 0 : root -> getCount(); }
	int	getLeafCount(){ return isEmpty() ? 0 : root -> getLeafCount(); }
	int	getHeight()	{ return isEmpty() ? 0 : root -> getHeight(); }
	void inorder()	{ printf("\n   inorder: "); root -> inorder(); }
	void preorder()	{ printf("\n  preorder: "); root -> preorder(); }
	void postorder(){ printf("\n postorder: ");  root -> postorder(); }
	void levelorder( ) {
		printf("\nlevelorder: ");
		if( !isEmpty() ) {
			CircularQueue q;
			q.enqueue( root );
			while ( !q.isEmpty() ) {
				BinaryNode* n = q.dequeue();
				if( n != NULL ) {
					printf(" [%2d]", n->getData());
					q.enqueue(n->getLeft ());
					q.enqueue(n->getRight());
				}
			}
		}
		printf("\n");
	}

	int getCount(BinaryNode *node) {
		if( node == NULL ) return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount(BinaryNode *node) {
		if( node == NULL ) return 0;
		if( node->isLeaf() ) return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getHeight(BinaryNode *node)	{
		if( node == NULL ) return 0;
		int	hLeft  = getHeight(node->getLeft());
		int	hRight = getHeight(node->getRight());
		return (hLeft>hRight) ? hLeft+1 : hRight+1;
	}
	int	calcSize()	{ return calcSize(root); }
	int calcSize(BinaryNode *node)	{
		if( node == NULL ) return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}

	int evaluate() { return evaluate(root); }
	// ???? ??? ???
	int evaluate(BinaryNode *node) {
		if( node == NULL ) return 0;
	    if( node->isLeaf() ) return node->getData();
	    else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch(node->getData()){
				case '+': return op1+op2;
				case '-': return op1-op2;
				case '*': return op1*op2;
				case '/': return op1/op2;
			}
			return 0;
	    }
	}


private:
	// ????? ???
	void inorder(BinaryNode *node) {
		if( node != NULL ) {
			if( node->getLeft() != NULL ) inorder(node->getLeft());
			printf( " [%2d]", node->getData());
			if( node->getRight()!= NULL ) inorder(node->getRight());
		}
	}
	void preorder(BinaryNode *node) {
		if( node != NULL ) {
			printf( " [%2d]", node->getData());
			if( node->getLeft() != NULL ) preorder(node->getLeft());
			if( node->getRight()!= NULL ) preorder(node->getRight());
		}
	}
	void postorder(BinaryNode *node) {
		if( node != NULL ) {
			if( node->getLeft() != NULL ) postorder(node->getLeft());
			if( node->getRight()!= NULL ) postorder(node->getRight());
			printf( " [%2d]", node->getData());
		}
	}
};

