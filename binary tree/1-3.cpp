#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	
	BinaryTree tree;
	BinaryNode *f = new BinaryNode('F', NULL, NULL);
	BinaryNode *e = new BinaryNode('E', NULL, NULL);

	BinaryNode *d = new BinaryNode('D', NULL, f );
	BinaryNode *c = new BinaryNode('C', NULL, NULL );
	BinaryNode *b = new BinaryNode('B', c, d );

	BinaryNode *a = new BinaryNode('A', b, e );

	tree.setRoot(a);
	if(tree.isBalanced()){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}

	return 0;
}