#include "BinSrchTree.h"

int main()
{
	BinSrchTree tree;

	tree.insert( new BinaryNode(35) );
	tree.insert( new BinaryNode(18) );
	tree.insert( new BinaryNode(7 ) );
	tree.insert( new BinaryNode(26) );
	tree.insert( new BinaryNode(12) );
	tree.insert( new BinaryNode(3 ) );
	tree.insert( new BinaryNode(68) );
	tree.insert( new BinaryNode(22) );
	tree.insert( new BinaryNode(30) );
	tree.insert( new BinaryNode(99) );

	tree.inorder();
	printf("\n");

	tree.search(26);
	tree.search(25);

	return 0;
}
