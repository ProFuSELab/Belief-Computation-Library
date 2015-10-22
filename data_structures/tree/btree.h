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
	
		void createTree(int singleton);
		node *search(int key);
		void deleteSubTree(int key);
		void addSubTree(node *leaf, int level);
		double deleteSubTree(node *leaf);
		node *getRoot();
		void setRoot(node *newroot);
	
	private:
		node *root;

};

#endif //_btree_h_
