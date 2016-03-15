//**************************************************************************************************
//
// PROJECT	: Data Structures for Efficient Computation of the Dempster-Shafer Evidential
//		  Calculations and Visualization of Imperfect Data
// CLASS	: BTree 
// PURPOSE	: Binary Tree Implementation
//
//**************************************************************************************************
// 
// Copyright(C) 2015 ProFuSE Lab, College of Engineering, University of Miami
// All rights reserved. 
// 
// This is unpublished proprietary Source Code of ProFuSE Lab.
//
// This copy of the Source Code is intended for ProFuSE Lab's research use only and is intended for
// view by persons duly authorized by the ProFuSE Lab. No part of this file may reproduced or
// distributed in any form or by any means without the written approval of the ProFuSE Lab. 
//
//**************************************************************************************************
//
// REVISIONS
// 
// Date			Researcher		Descriptions
// -------------------	-------------------  	-------------------
// October 2015		Lalintha Polpitiya	Binary Tree Implementation
// March 2016		Lalintha Polpitiya	Experiments
//
//**************************************************************************************************

#include "btree.h"

using namespace std;

//**************************************************************************************************
// Default 20 Singletons
//**************************************************************************************************
BTree::BTree(void)
{
	root = NULL;
}

//**************************************************************************************************
// Destructor 
//**************************************************************************************************
BTree::~BTree(void)
{

}

//**************************************************************************************************
// Create tree 
//**************************************************************************************************
void BTree::createTree(int singleton)
{
	for (int i = 0; i < singleton; i++)
	{
		addSubTreeSingleton(i);
	}
}

void BTree::addSubTreeSingleton(int i)
{
	int level = 0;
	node *new_node;
	new_node = new node;
	new_node->mass = 0.0;
	new_node->left = root;
	new_node->right = NULL;
	root = new_node;
	level = i - 1;
	if (level >= 0)
	{
		new_node = new node;
		new_node->mass = 0.0;
		new_node->left = NULL;
		new_node->right = NULL;
		root->right = new_node;
		addSubTree(root->right, level - 1);
	}
}

//**************************************************************************************************
// Add sub tree 
//**************************************************************************************************
void BTree::addSubTree(node *leaf, int level)
{
	if (level >= 0)
	{
		node *new_node;
		new_node = new node;
		new_node->mass = 0.0;
		new_node->left = NULL;
		new_node->right = NULL;
		leaf->left = new_node;
		addSubTree(leaf->left, level - 1);

		new_node = new node;
		new_node->mass = 0.0;
		new_node->left = NULL;
		new_node->right = NULL;
		leaf->right = new_node;
		addSubTree(leaf->right, level - 1);
	}
}

//**************************************************************************************************
// Delete sub tree 
//**************************************************************************************************
double BTree::deleteSubTree(node *leaf)
{
	double normalize = 0.0;
	if (leaf->left)
		normalize += deleteSubTree(leaf->left);	
	if (leaf->right)
		normalize += deleteSubTree(leaf->right);	
	normalize += leaf->mass;
	if (leaf)
		delete leaf;
	return normalize;
}

//**************************************************************************************************
// Get root 
//**************************************************************************************************
node *BTree::getRoot()
{
	return root;	
}

//**************************************************************************************************
// Set root 
//**************************************************************************************************
void BTree::setRoot(node *newroot)
{
	root = newroot;
}
