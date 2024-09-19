#include "ExtendedBinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	
	BinaryTree tree;
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', NULL, f);

	BinaryNode *d = new BinaryNode('D', NULL, NULL );
	BinaryNode *c = new BinaryNode('C', NULL, NULL );
	BinaryNode *b = new BinaryNode('B', c, d );

	BinaryNode *a = new BinaryNode('A', b, e );

	tree.setRoot(a);

	BinaryTree* subtree = new BinaryTree(); // 명시적 초기화
	BinaryNode *k = new BinaryNode('K', NULL, NULL);
	subtree->setRoot(k);

	if(tree.isDisjointFrom(subtree)){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}

	return 0;
}