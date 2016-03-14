#ifndef _dslist_h_
#define _dslist_h_

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <utility>	// pair

class DSList
{
	public:
		DSList(void);
		DSList(int singletons);
		void debugOn(void);
		void debugOff(void);
		void readSingletons(void);
		int calFocalIndexAnyOrder(void);
		int calFocalIndexAscending(void);
		void fillingBeliefVecAnyOrder(void);
		void fillingBeliefVecAscending(void);
		int fillingBeliefVecRandom(std::vector<int> & indexVec);
		void fillingPlausibilityVecAnyOrder(void);
		void fillingPlausibilityVecAscending(void);
		void fillingBeliefInvVecAnyOrder(void);
		void fillingBeliefInvVecAscending(void);
		void genRandomMassValues(void);
		void genIncreasingMassValues(void);
		void genRandomList(int fod_size);
		double accessFocalElement(int index);
		double accessFocalElementIndexVec(std::vector<int> & indexVec);
		double calBelief(void);
		double calPlausibility(void);
		void removeFocalEleSingleton(void);
		void addFocalEleSingleton(void);
		void printFocalElements(void);
		void printFocalElementsNormalized(void);
		void printSingletonVector(void);
		void printBliefInvVec(void);

	private:
		int no_singletons, no_sin_focalele, no_sin_belief, no_sin_plausibility;
		std::vector<std::string> singleton;    	// vector of singleton names
		std::vector<std::string>::iterator it_str;
		std::vector<int> belief_ele_vec;   	// singletons in a "belief"
		std::vector<int> plausibility_ele_vec;	// singletons in a "plausibility"
		std::vector<int> belief_inv_ele_vec;   	// singletons in a "belief complement"
		std::list<std::pair <int,float> > focal_element;
		std::vector<int> power;
		double normalizing_const;
		bool debug;
		clock_t begin, end;
		double time_spent;
};

#endif //_dslist_h_
