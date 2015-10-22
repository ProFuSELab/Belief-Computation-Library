#ifndef _btree_h_
#define _btree_h_

#include <iostream>
#include <cmath>

struct node
{
	float mass;
	node *left;
	node *right;
};

class BTree
{
	public:
		BTree(void);
		~BTree(void);
	
		node *getRoot();
		void setRoot(node *newroot);
		void createTree(int singleton);
		void addSubTreeSingleton(int i);
		void addSubTree(node *leaf, int level);
		double deleteSubTree(node *leaf);
	
	private:
		node *root;

};

#endif //_btree_h_
