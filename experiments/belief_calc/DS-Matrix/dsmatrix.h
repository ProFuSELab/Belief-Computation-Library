#ifndef _dsmatrix_h_
#define _dsmatrix_h_

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
#include <utility>

class DSMatrix
{
	public:
		DSMatrix(void);
		DSMatrix(int singletons);
		void debugOn(void);
		void debugOff(void);
		void readSingletons(void);
		std::pair<int, int> calFocalIndexAnyOrder(void);
		std::pair<int, int> calFocalIndexAscending(void);
		void fillingBeliefVecAnyOrder(void);
		void fillingBeliefVecAscending(void);
		int fillingBeliefVecRandom(std::vector<int> & rowVec, std::vector<int> & colVec);
		void fillingPlausibilityVecAnyOrder(void);
		void fillingPlausibilityVecAscending(void);
		std::vector<std::string> oddEvenToAll(void);
		void fillingBeliefInvVecAnyOrder(void);
		void fillingBeliefInvVecAscending(void);
		void genRandomMassValues(void);
		void genIncreasingMassValues(void);
		double accessFocalElement(int row, int col);
		double accessFocalElementCoVecs(std::vector<int> & rowVec, std::vector<int> & colVec);
		double calBelief(void);
		double calPlausibility(void);
		void removeFocalEleSingleton(void);
		void addFocalEleSingleton(void);
		void printFocalElements(void);
		void printFocalElementsNormalized(void);
		void printSingletonVector(void);
		void printBeliefInvVec(void);

	private:
		int no_singletons, no_sin_focalele, no_sin_belief, no_sin_plausibility;
		std::vector<std::string> odd_singleton, even_singleton, all_singleton;
		std::vector<std::string>::iterator it_str;
		std::vector<std::pair<int, int> > belief_ele_vec;
		std::vector<std::pair<int, int> > plausibility_ele_vec;
		std::vector<std::pair<int, int> > belief_inv_ele_vec;
		std::vector<std::vector<float> > focal_element;
		std::vector<std::pair<int, int> > focal_index;
		std::vector<int> power;
		double normalizing_const;
		bool debug;
		clock_t begin, end;
		double time_spent;
};

#endif //_dsmatrix_h_
