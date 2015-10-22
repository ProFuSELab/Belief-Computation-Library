//**************************************************************************************************
//
// PROJECT	: Data Structures for Efficient Computation of the Dempster-Shafer Evidential
//		  Calculations and Visualization of Imperfect Data
// CLASS	: DSTree 
// PURPOSE	: Tree Implementation
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
// September 2015	Lalintha Polpitiya	Tree Implementation
//
//**************************************************************************************************

#include "dstree.h"

using namespace std;

//**************************************************************************************************
// Default 20 Singletons
//**************************************************************************************************
DSTree::DSTree(void)
{
	no_singletons = 5;
	normalizing_const = 0.0;
	debug = false;
	b_tree.createTree(5);
	focal_index.assign(1048576, 0);
}

//**************************************************************************************************
// Have to pass the number of singletons
//**************************************************************************************************
DSTree::DSTree(int singletons)
{
	no_singletons = singletons;
	normalizing_const = 0.0;
	debug = false;
	b_tree.createTree(singletons);
	focal_index.assign(pow(2, singletons), 0);
}

//**************************************************************************************************
// Debug On
//**************************************************************************************************
void DSTree::debugOn(void)
{
	debug = true;
}

//**************************************************************************************************
// Debug Off
//**************************************************************************************************
void DSTree::debugOff(void)
{
	debug = false;
}

//**************************************************************************************************
// Reading singleton names
//**************************************************************************************************
void DSTree::readSingletons(void)
{
	string st;

	cin >> no_singletons;
	for (int i = 0; i < no_singletons; i++)		// first singleton is theta1
	{
		cin >> st;				// reading a singleton name from std input
		singleton.push_back(st);
	}
}

//**************************************************************************************************
// Calculating the focal element index, any order 
//**************************************************************************************************
int DSTree::calFocalIndexAnyOrder(void)
{
	int focal_ele_index = 0;
	string st;

	cin >> no_sin_focalele;			// number of singletons in a one focal element 
	for (int i = 0; i < no_sin_focalele; i++)	
	{
		cin >> st; 

		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				focal_ele_index += pow(2, j);	
	}

	if (debug)
	{
		cout << "Focal element index \t: " << focal_ele_index << endl;
		cout << "Done! Calculating focal index any order" << endl;
	}

	return focal_ele_index;
}	

//**************************************************************************************************
// Calculating the focal element index, fast 
//**************************************************************************************************
int DSTree::calFocalIndexAscending(void)
{
	int focal_ele_index = 0;
	int cnt = 0;
	string st;

	cin >> no_sin_focalele;			// number of singletons in a one focal element 
	for (int i = 0; i < no_sin_focalele; i++)	
	{
		cin >> st; 
		while (st != singleton[cnt])
		{
			++cnt;
		}
		focal_ele_index += pow(2, cnt);	
		cnt++;
	}

	if (debug)
	{
		cout << "Focal element index \t: " << focal_ele_index << endl;
		cout << "Done! Calculating focal index ascending" << endl;
	}

	return focal_ele_index;
}	

//**************************************************************************************************
// Filling belief vector, any order 
//**************************************************************************************************
void DSTree::fillingBeliefVecAnyOrder(void)
{
	string st;

	belief_ele_vec.clear();
	cin >> no_sin_belief;	

	for (int i = 0; i < no_sin_belief; i++)	
	{
		cin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				belief_ele_vec.push_back(pow(2, j));	
	}

	if (debug)
		cout << "Done! Filling belief vector any order" << endl;
}

//**************************************************************************************************
// Filling belief vector, fast(ascending) 
//**************************************************************************************************
void DSTree::fillingBeliefVecAscending(void)
{
	int cnt = 0;
	string st;

	belief_ele_vec.clear();
	cin >> no_sin_belief;	

	for (int i = 0; i < no_sin_belief; i++)	
	{
		cin >> st; 
		while (st != singleton[cnt])
		{
			++cnt;
		}
		belief_ele_vec.push_back(pow(2, cnt));	
		cnt++;
	}

	if (debug)
		cout << "Done! Filling belief vector ascending" << endl;
}

//**************************************************************************************************
// Filling plausibility vector, any order 
//**************************************************************************************************
void DSTree::fillingPlausibilityVecAnyOrder(void)
{
	string st;

	plausibility_ele_vec.clear();
	cin >> no_sin_plausibility;	

	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				plausibility_ele_vec.push_back(pow(2, j));	
	}

	if (debug)
		cout << "Done! Filling plausibility vector any order" << endl;
}

//**************************************************************************************************
// Filling plausibility vector, fast(ascending) 
//**************************************************************************************************
void DSTree::fillingPlausibilityVecAscending(void)
{
	int cnt = 0;
	string st;

	plausibility_ele_vec.clear();
	cin >> no_sin_plausibility;	

	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		while (st != singleton[cnt])
		{
			++cnt;
		}
		plausibility_ele_vec.push_back(pow(2, cnt));	
		cnt++;
	}

	if (debug)
		cout << "Done! Filling plausibility vector ascending" << endl;
}

//**************************************************************************************************
// Filling belief compliment vector, any order, to calculate plausibility
//**************************************************************************************************
void DSTree::fillingBeliefInvVecAnyOrder(void)
{
	string st;

	belief_inv_ele_vec.clear();
	cin >> no_sin_plausibility;	

	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
			{
				// have to finish this function
			}
	}

	if (debug)
		cout << "Done! Filling belief inverse vector any order" << endl;
}

//**************************************************************************************************
// Filling belief compliment vector, fast(ascending), to calculate plausibility
//**************************************************************************************************
void DSTree::fillingBeliefInvVecAscending(void)
{
	int cnt = 0;
	string st;

	belief_inv_ele_vec.clear();
	cin >> no_sin_plausibility;	

	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		while (st != singleton[cnt])
		{
			belief_inv_ele_vec.push_back(pow(2, cnt));	
			++cnt;
		}
		cnt++;
	}

	while (cnt < no_singletons)
	{
		belief_inv_ele_vec.push_back(pow(2, cnt));	
		++cnt;
	}

	if (debug)
		cout << "Done! Filling belief inverse vector ascending" << endl;
}

//**************************************************************************************************
// Generate random mass values 
//**************************************************************************************************
void DSTree::genRandomMassValues(void)
{
	srand(time(NULL)); 				// initialize random seed
	normalizing_const = 0.0;

	randomMassOnLeaves(b_tree.getRoot());

	// no need to normalize everytime, we can normalize only when we use

	/* have to write this part
	if (debug)
		for (int i = 0; i < pow(2, no_singletons); i++)
			cout << "mass(" << i << ") \t: " 
				<< focal_element[i] / normalizing_const << endl;
	*/

	if (debug)
		printFocalElements();
}

//**************************************************************************************************
// Tree with random mass values
//**************************************************************************************************
void DSTree::randomMassOnLeaves(node *leaf)
{
	if (leaf != NULL)
	{
		leaf->mass = rand() % 10000;	// random number between 0 and 9999
		normalizing_const += leaf->mass;
		randomMassOnLeaves(leaf->left);
		randomMassOnLeaves(leaf->right);
	}
}

//**************************************************************************************************
// Generate increasing mass values, specially for testing
//**************************************************************************************************
void DSTree::genIncreasingMassValues(void)
{
	srand(time(NULL)); 				// initialize random seed
	int leafval = 1;
	normalizing_const = 0.0;

	increasingMassOnLeaves(b_tree.getRoot(), leafval);

	// no need to normalize everytime, we can normalize only when we use

	/* have to write this part
	if (debug)
		for (int i = 0; i < pow(2, no_singletons); i++)
			cout << "mass(" << i << ") \t: " 
				<< focal_element[i] / normalizing_const << endl;
	*/

	if (debug)
		printFocalElements();
}

//**************************************************************************************************
// Tree with random mass values
//**************************************************************************************************
void DSTree::increasingMassOnLeaves(node *leaf, int leafval)
{
	if (leaf != NULL)
	{
		leaf->mass = leafval;
		normalizing_const += leaf->mass;
		increasingMassOnLeaves(leaf->left, leafval * 2);
		increasingMassOnLeaves(leaf->right, leafval * 2 + 1);
	}
}

//**************************************************************************************************
// Access a focal element 
//**************************************************************************************************
double DSTree::accessFocalElement(int index)
{
	double element;
	int level = no_singletons - 1;

	begin = clock();
	node *leaf;
	leaf = b_tree.getRoot();
	while (index % (int)pow(2, level) > 0)
	{
		if (index / (int)pow(2, level) == 0)
			leaf = leaf->left;
		else if (index / (int)pow(2, level) == 1)
		{
			index -= (int)pow(2, level);
			leaf = leaf->right;
		}
		else
		{
			assert(false);
		}
		level = level - 1;
	}
	element = leaf->mass;
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	if (debug)
		cout << "Focal element " << index << "\t: " << element / normalizing_const << endl;

	cout << "Time spent on accessing a focal element\t: " << time_spent << endl;
	return element;
}

//**************************************************************************************************
// Calculating belief 
//**************************************************************************************************
double DSTree::calBelief(void)
{
	double belief = 0.0;
	int focal_index_cnt = 0, focal_index_temp, level;

	begin = clock();
	for (int i = 0; i < no_sin_belief; i++)		// finding required indexes
	{ 
		focal_index[focal_index_cnt] = belief_ele_vec[i];
		focal_index_cnt++;
		focal_index_temp = focal_index_cnt - 1;
		for(int j = 0; j < focal_index_temp; j++)
		{
			focal_index[focal_index_cnt] = focal_index[j] + belief_ele_vec[i];	
			focal_index_cnt++;
		}
	}

	for (int i = 0; i < pow(2, no_sin_belief) - 1; i++)
	{
		level = no_singletons - 1;
		node *leaf;
		leaf = b_tree.getRoot();
		while (focal_index[i] % (int)pow(2, level) != 0)
		{
			if (focal_index[i] / (int)pow(2, level) == 0)
				leaf = leaf->left;
			else if (focal_index[i] / (int)pow(2, level) == 1)
			{
				focal_index[i] -= (int)pow(2, level);
				if (focal_index[i] == 0)
					break;
				leaf = leaf->right;
			}
			level = level - 1;
		}
		belief += leaf->mass; 
	}
	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating belief \t: " << time_spent << endl;
	cout << "Belief of " << pow(2, no_sin_belief) - 1 << " focal elements \t\t: " 
		<< belief / normalizing_const << endl;

	return belief / normalizing_const;
}

//**************************************************************************************************
// Calculating plausibility 
//**************************************************************************************************
double DSTree::calPlausibility(void)
{
	double plausibility = 0.0, belief_inv = 0.0;
	int focal_index_cnt = 0, focal_index_temp, level;

	begin = clock();
	for (int i = 0; i < no_singletons - no_sin_plausibility; i++)	// finding required indexes
	{ 
		focal_index[focal_index_cnt] = belief_inv_ele_vec[i];
		focal_index_cnt++;
		focal_index_temp = focal_index_cnt - 1;
		for(int j = 0; j < focal_index_temp; j++)
		{
			focal_index[focal_index_cnt] = focal_index[j] + belief_inv_ele_vec[i];	
			focal_index_cnt++;
		}
	}

	for (int i = 0; i < pow(2, no_singletons - no_sin_plausibility) - 1; i++)
	{
		level = no_singletons - 1;
		node *leaf;
		leaf = b_tree.getRoot();
		while (focal_index[i] % (int)pow(2, level) != 0)
		{
			if (focal_index[i] / (int)pow(2, level) == 0)
				leaf = leaf->left;
			else if (focal_index[i] / (int)pow(2, level) == 1)
			{
				focal_index[i] -= (int)pow(2, level);
				if (focal_index[i] == 0)
					break;
				leaf = leaf->right;
			}
			level = level - 1;
		}
		belief_inv += leaf->mass; 
	}
	plausibility = normalizing_const - belief_inv;
	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating plausibility \t: " << time_spent << endl;
	cout << "Plausibility of " << (int)pow(2, no_singletons) - (int)pow(2, no_singletons - 
		no_sin_plausibility) << " focal ele \t: " 
		<< plausibility / normalizing_const << endl;

	return plausibility / normalizing_const;
}

//**************************************************************************************************
// Remove focal elements of a singleton 
//**************************************************************************************************
void DSTree::removeFocalEleSingleton(void)
{
	string st;
	int singleton_number;
	int start = 1;

	cin >> st;
	for (int i = 0; i < no_singletons; i++)
		if (st == singleton[i])
		{
			singleton_number = i;
			break;
		}

	removeSubTrees(b_tree.getRoot(), no_singletons - singleton_number - 1, NULL, true, true);
	
	singleton.erase(singleton.begin() + singleton_number);
	no_singletons--;
}

//**************************************************************************************************
// Remove sub trees 
//**************************************************************************************************
void DSTree::removeSubTrees(node *leaf, int step, node *parent, bool atroot, bool parentleft)
{
	if (step == 0)
	{
		if (atroot)
			b_tree.setRoot(leaf->left);
		else
		{
			if (parentleft)	
			{
				parent->left = leaf->left;
			}
			else
			{
				parent->right = leaf->left;
			}
		}
		normalizing_const -= b_tree.deleteSubTree(leaf->right);
		normalizing_const -= leaf->mass;
		delete leaf;
	}
	else
	{
		removeSubTrees(leaf->left, step - 1, leaf, false, true);
		removeSubTrees(leaf->right, step - 1, leaf, false, false);
	}
}

//**************************************************************************************************
// Add focal elements of a singleton 
//**************************************************************************************************
void DSTree::addFocalEleSingleton(void)
{
	string st;

	cin >> st;
	singleton.push_back(st);
	no_singletons++;
	b_tree.addSubTreeSingleton(no_singletons - 1);
}

//**************************************************************************************************
// Print focal elements, without normalizing 
//**************************************************************************************************
void DSTree::printFocalElements(void)
{
	traverseTree(b_tree.getRoot());
}

//**************************************************************************************************
// Print a focal element, without normalizing 
//**************************************************************************************************
void DSTree::traverseTree(node *leaf)
{
	if (leaf != NULL)
	{
		cout << leaf->mass << endl;
		traverseTree(leaf->left);
		traverseTree(leaf->right);
	}
}

//**************************************************************************************************
// Print focal elements normalized 
//**************************************************************************************************
void DSTree::printFocalElementsNormalized(void)
{
	traverseTreeNormalized(b_tree.getRoot());
}

//**************************************************************************************************
// Print a focal element, normalized 
//**************************************************************************************************
void DSTree::traverseTreeNormalized(node *leaf)
{
	if (leaf != NULL)
	{
		cout << leaf->mass / normalizing_const << endl;
		traverseTreeNormalized(leaf->left);
		traverseTreeNormalized(leaf->right);
	}
}

//**************************************************************************************************
// Print singleton vector 
//**************************************************************************************************
void DSTree::printSingletonVector(void)
{
	for (it_str = singleton.begin(); it_str != singleton.end(); it_str++)
		cout << *it_str << " ";
	cout << endl;
}

//**************************************************************************************************
// Print singleton vector 
//**************************************************************************************************
void DSTree::printBliefInvVec(void)
{
	cout << "Belief inverse vector \t: " << endl;
	for (int i = 0; i < belief_inv_ele_vec.size(); i++)
	{
		cout << belief_inv_ele_vec[i] << endl;
	}	
}
