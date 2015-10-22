#ifndef _dstree_h_
#define _dstree_h_

#include "btree.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <cassert>

class DSTree
{
	public:
		DSTree(void);
		DSTree(int singletons);
		void debugOn(void);
		void debugOff(void);
		void readSingletons(void);
		int calFocalIndexAnyOrder(void);
		int calFocalIndexAscending(void);
		void fillingBeliefVecAnyOrder(void);
		void fillingBeliefVecAscending(void);
		void fillingPlausibilityVecAnyOrder(void);
		void fillingPlausibilityVecAscending(void);
		void fillingBeliefInvVecAnyOrder(void);
		void fillingBeliefInvVecAscending(void);
		void genRandomMassValues(void);
		void randomMassOnLeaves(node * leaf);
		void genIncreasingMassValues(void);
		void increasingMassOnLeaves(node * leaf, int leafval);
		double accessFocalElement(int index);
		double calBelief(void);
		double calPlausibility(void);
		void removeFocalEleSingleton(void);
		void removeSubTrees(node *leaf, int step, node *parent, bool atroot, bool parentleft);
		void addFocalEleSingleton(void);
		void printFocalElements(void);
		void traverseTree(node *leaf);
		void printFocalElementsNormalized(void);
		void traverseTreeNormalized(node *leaf);
		void printSingletonVector(void);
		void printBliefInvVec(void);

	private:
		int no_singletons, no_sin_focalele, no_sin_belief, no_sin_plausibility;
		std::vector<std::string> singleton;    	// vector of singleton names
		std::vector<std::string>::iterator it_str;
		std::vector<int> belief_ele_vec;   	// singletons in a "belief"
		std::vector<int> plausibility_ele_vec;	// singletons in a "plausibility"
		std::vector<int> belief_inv_ele_vec;   	// singletons in a "belief complement"
		std::vector<int> focal_index;
		double normalizing_const;
		bool debug;
		clock_t begin, end;
		double time_spent;
		BTree b_tree;
};

#endif //_dstree_h_
