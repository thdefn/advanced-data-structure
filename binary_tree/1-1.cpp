#include "ExtendedBinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	
	BinaryTree tree;
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *k = new BinaryNode('K', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', f, k);

	BinaryNode *d = new BinaryNode('D', NULL, NULL );
	BinaryNode *c = new BinaryNode('C', NULL, NULL );
	BinaryNode *b = new BinaryNode('B', c, d );

	BinaryNode *a = new BinaryNode('A', b, e );

	tree.setRoot(a);
	if(tree.isFull()){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}

	return 0;
}