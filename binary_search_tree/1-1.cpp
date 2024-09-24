#include "BinaryTree.h"
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
	tree.inorder();
	tree.preorder();
	tree.postorder();
	printf("\n count = %d\n", tree.getCount());
	printf(" height = %d\n", tree.getHeight());
	printf(" leaf count = %d\n", tree.getLeafCount());

	return 0;
}