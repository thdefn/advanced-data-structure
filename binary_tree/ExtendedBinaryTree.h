#pragma once
#include "BinaryNode.h"
#include <cmath>
#include "CircularQueue.h"

class BinaryTree
{
	BinaryNode*	root;
public:

	BinaryTree(): root(NULL) { }
	~BinaryTree()	{ }

	void setRoot(BinaryNode* node)	{ root = node; }
	BinaryNode* getRoot()			{ return root; }
	bool isEmpty()	{ return root==NULL; }

	int	getCount()	{ return isEmpty() ? 0 : getCount(root); }
	int	getLeafCount(){ return isEmpty() ? 0 : getLeafCount(root); }
	int	getHeight()	{ return isEmpty() ? 0 : getHeight(root); }
	bool isFull() {
		// 1. get Height
		int height = getHeight();
		int nodeCount = getCount();
		// 2. Count of Full Binary Tree Nodes
		int fullBinaryTreeNodeCount = pow(2, height) - 1;
		// 3. check if the tree is full binary tree
		return (fullBinaryTreeNodeCount == nodeCount);
	}

	int level(BinaryNode *node){
		 return getLevelIfFound(node, root, 1);
	}

	int getLevelIfFound(BinaryNode *node, BinaryNode *cur, int level){
		if(cur == NULL) return 0;
		if(node == cur) return level;
		int levelLeft = getLevelIfFound(node, cur -> getLeft(), level + 1);
		int levelRight = getLevelIfFound(node, cur -> getRight(), level + 1);
		return(levelLeft > levelRight)? levelLeft : levelRight;
	}

	bool isBalanced(){
		return isEmpty() ? true : isBalanced(root);
	}
	bool isBalanced(BinaryNode *node){
		// 1. return turn if null
		if( node == NULL ) return true;
		int leftHeight = getHeight(node->getLeft());
		int rightHeight = getHeight(node->getRight());
		// 2. check if the tree is balanced
		if(abs(leftHeight - rightHeight) > 1)
			return false;
		// 3. check the children if the tree is balanced
		return isBalanced(node -> getLeft()) && isBalanced(node -> getRight());
	}


	int pathLength(){
		return isEmpty() ? 0 : pathLength(root, 0);
	}

	int pathLength(BinaryNode *node, int depth){
		if(node == NULL) return 0;
		return depth + pathLength(node -> getLeft(), depth + 1) + pathLength(node -> getRight(), depth + 1);
	}

	void reverse(){
		reverse(root);
	}

	void reverse(BinaryNode *node){
		if(node == NULL) return;
		BinaryNode *left = node->getLeft();
		BinaryNode *right = node->getRight();
		node->setLeft(right);
		node->setRight(left);
		reverse(node->getLeft());
		reverse(node->getRight());
	}


	bool isValid(){
		return isValid(root, this);
	}

	bool isValid(BinaryNode* node, BinaryTree* tree) {
    if (node == NULL) {
        return true;
    }

	BinaryTree* left = new BinaryTree();
	left -> setRoot(node -> getLeft());

	BinaryTree* right = new BinaryTree();
	right -> setRoot(node -> getRight());
    if (!left -> isDisjointFrom(right)) {
        return false;
    }
    return isValid(node->getLeft(), tree) && isValid(node->getRight(), tree);
	}




	bool isDisjointFrom(BinaryTree* that){
		return isDisjointFrom(that, root);
	}

	bool isDisjointFrom(BinaryTree* that, BinaryNode* node){
		if(node == NULL || that == NULL){
			return true;
		 } 
		 
		 if(isIn(that, node)){
			return false;
		 }

		 return isDisjointFrom(that, node -> getLeft()) && isDisjointFrom(that, node -> getRight());
	}

	bool isIn(BinaryTree* that, BinaryNode* node){
		CircularQueue q;
		q.enqueue( that ->  getRoot() );
		while ( !q.isEmpty() ) {
			BinaryNode* n = q.dequeue();
			if( n == NULL ) {
				continue;
			} else if(n == node){
				return true;
			} else {
				q.enqueue(n->getLeft());
				q.enqueue(n->getRight());
			}
		}
		return false;
	}




	void levelorder( ) {
		printf("\nlevelorder: ");
		if( !isEmpty() ) {
			CircularQueue q;
			q.enqueue( root );
			while ( !q.isEmpty() ) {
				BinaryNode* n = q.dequeue();
				if( n != NULL ) {
					printf(" [%c] ", n->getData());
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

};

