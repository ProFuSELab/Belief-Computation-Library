//**************************************************************************************************
//
// PROJECT	: Data Structures for Efficient Computation of the Dempster-Shafer Evidential
//		  Calculations and Visualization of Imperfect Data
// CLASS	: DSVector 
// PURPOSE	: Vector Implementation
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
// August 2015		Lalintha Polpitiya	Vector Implementation
// March 2016		Lalintha Polpitiya	Lookup table
//
//**************************************************************************************************

#include "dsvector.h"

using namespace std;

//**************************************************************************************************
// Default 20 Singletons
//**************************************************************************************************
DSVector::DSVector(void)
{
	no_singletons = 20;
	normalizing_const = 0.0;
	debug = false;
	focal_element.assign(1048576, 0);
	focal_index.assign(1048576, 0);
	int power_of_i = 1;
	for (int i = 0; i < no_singletons; i++)		// first singleton is theta 0
	{
		power.push_back(power_of_i);
		power_of_i *= 2;
	}
}

//**************************************************************************************************
// Have to pass the number of singletons
//**************************************************************************************************
DSVector::DSVector(int singletons)
{
	no_singletons = singletons;
	normalizing_const = 0.0;
	debug = false;
	focal_element.assign(pow(2, singletons), 0.0);
	focal_index.assign(pow(2, singletons), 0);
	int power_of_i = 1;
	for (int i = 0; i < no_singletons; i++)		// first singleton is theta 0
	{
		power.push_back(power_of_i);
		power_of_i *= 2;
	}
}

//**************************************************************************************************
// Debug On
//**************************************************************************************************
void DSVector::debugOn(void)
{
	debug = true;
}

//**************************************************************************************************
// Debug Off
//**************************************************************************************************
void DSVector::debugOff(void)
{
	debug = false;
}

//**************************************************************************************************
// Reading singleton names
//**************************************************************************************************
void DSVector::readSingletons(void)
{
	string st;

	cin >> no_singletons;
	for (int i = 0; i < no_singletons; i++)		// first singleton is theta 0
	{
		cin >> st;				// reading a singleton name from std input
		singleton.push_back(st);
	}
}

//**************************************************************************************************
// Calculating the focal element index, any order 
//**************************************************************************************************
int DSVector::calFocalIndexAnyOrder(void)
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
		cout << "Focal element index \t: " << focal_ele_index << endl;

	return focal_ele_index;
}	

//**************************************************************************************************
// Calculating the focal element index, fast 
//**************************************************************************************************
int DSVector::calFocalIndexAscending(void)
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
		cout << "Focal element index \t: " << focal_ele_index << endl;

	return focal_ele_index;
}	

//**************************************************************************************************
// Filling belief vector, any order 
//**************************************************************************************************
void DSVector::fillingBeliefVecAnyOrder(void)
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
}

//**************************************************************************************************
// Filling belief vector, fast(ascending) 
//**************************************************************************************************
void DSVector::fillingBeliefVecAscending(void)
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
}

//**************************************************************************************************
// Filling plausibility vector, any order 
//**************************************************************************************************
void DSVector::fillingPlausibilityVecAnyOrder(void)
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
}

//**************************************************************************************************
// Filling plausibility vector, fast(ascending) 
//**************************************************************************************************
void DSVector::fillingPlausibilityVecAscending(void)
{
	plausibility_ele_vec.clear();
	int cnt = 0;
	string st;
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
}

//**************************************************************************************************
// Filling belief compliment vector, any order, to calculate plausibility
//**************************************************************************************************
void DSVector::fillingBeliefInvVecAnyOrder(void)
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
}

//**************************************************************************************************
// Filling belief compliment vector, fast(ascending), to calculate plausibility
//**************************************************************************************************
void DSVector::fillingBeliefInvVecAscending(void)
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
}

//**************************************************************************************************
// Generate random mass values 
//**************************************************************************************************
void DSVector::genRandomMassValues(void)
{
	srand(time(NULL)); 				// initialize random seed
	focal_element[0] = 0.0;				// assign value 0.0 to null element

	for (int i = 1; i < pow(2, no_singletons); i++)
	{
		focal_element[i] = rand() % 10000;	// random number between 0 and 9999
		normalizing_const += focal_element[i];	// finding normalizing constant
	}

	// no need to normalize everytime, we can normalize only when we use
	//	for (int i = 0; i < pow(2, no_singletons); i++)
	//		focal_element[i] /= normalizing_const;

	if (debug)
		for (int i = 0; i < pow(2, no_singletons); i++)
			cout << "mass(" << i << ") \t: " 
				<< focal_element[i] / normalizing_const << endl;
}

//**************************************************************************************************
// Generate increasing mass values, specially for testing
//**************************************************************************************************
void DSVector::genIncreasingMassValues(void)
{
	srand(time(NULL)); 				// initialize random seed
	focal_element[0] = 0.0;				// assign value 0.0 to null element

	for (int i = 1; i < pow(2, no_singletons); i++)
	{
		focal_element[i] = i;
		normalizing_const += focal_element[i];	// finding normalizing constant
	}
	// no need to normalize everytime, we can normalize only when we use
	//	for (int i = 0; i < pow(2, no_singletons); i++)
	//		focal_element[i] /= normalizing_const;

	if (debug)
		for (int i = 0; i < pow(2, no_singletons); i++)
			cout << "mass(" << i << ") \t: " 
				<< focal_element[i] / normalizing_const << endl;
}

//**************************************************************************************************
// Access a focal element 
//**************************************************************************************************
double DSVector::accessFocalElement(int index)
{
	double element;

	begin = clock();
	element = focal_element[index];
	end = clock();
	time_spent = 1000000 * (double)(end - begin) / CLOCKS_PER_SEC;

	if (debug)
		cout << "Focal element " << index << "\t: " << element << endl;

	cout << "Time spent on accessing a focal element\t: " << time_spent << endl;
	return element;
}

//**************************************************************************************************
// Access a focal element with singleton index vector, for experiments, returns time 
//**************************************************************************************************
double DSVector::accessFocalElementIndexVec(vector<int> & indexVec)
{
	double element;
	int index = 0;
	begin = clock();
	for (vector<int>::iterator it = indexVec.begin(); it != indexVec.end(); ++it) 
	{
		index += power[*it];
	}

	element = focal_element[index];
	end = clock();
	time_spent = 1000000 * (double)(end - begin) / CLOCKS_PER_SEC;

	if (debug)
		cout << "Focal element " << index << "\t: " << element << endl;
//	cout << "Time spent on accessing a focal element\t: " << time_spent << endl;
	return time_spent;
}

//**************************************************************************************************
// Calculating belief 
//**************************************************************************************************
double DSVector::calBelief(void)
{
	double belief = 0.0;
	int focal_index_cnt = 0, focal_index_temp;

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
		belief += focal_element[focal_index[i]];
	end = clock();

	time_spent = 1000000 * (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating belief \t: " << time_spent << endl;
	cout << "Belief of " << pow(2, no_sin_belief) - 1 << " focal elements \t\t: " 
		<< belief / normalizing_const << endl;

	return belief / normalizing_const;
}

//**************************************************************************************************
// Calculating plausibility 
//**************************************************************************************************
double DSVector::calPlausibility(void)
{
	double plausibility = 0.0, belief_inv = 0.0;
	int focal_index_cnt = 0, focal_index_temp;

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
		belief_inv += focal_element[focal_index[i]];
		plausibility = normalizing_const - belief_inv;
	end = clock();

	time_spent = 1000000 * (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating plausibility \t: " << time_spent << endl;
	cout << "Plausibility of " << (int)pow(2, no_singletons) - (int)pow(2, no_singletons - 
		no_sin_plausibility) - 1 << " focal ele \t: " 
		<< plausibility / normalizing_const << endl;

	return plausibility / normalizing_const;
}

//**************************************************************************************************
// Remove focal elements of a singleton 
//**************************************************************************************************
void DSVector::removeFocalEleSingleton(void)
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

	while (pow(2, singleton_number) * 2 * start <= pow(2, no_singletons))
	{
		for (int i = pow(2, singleton_number) * (2 * start - 1); i < 
			pow(2, singleton_number) * 2 * start; i++) 
		{
			normalizing_const -= focal_element[i];
		}
		if (start > 1)
			copy(focal_element.begin() + (int)pow(2, singleton_number) * 2 * 
				(start - 1), focal_element.begin() + (int)pow(2, singleton_number) *
				2 * (start - 1) + (int)pow(2, singleton_number),
				focal_element.begin() +	(int)pow(2, singleton_number) * (start - 1));
		start++;
	}

	singleton.erase(singleton.begin() + singleton_number);
	no_singletons--;
	focal_element.resize(pow(2, no_singletons));
}

//**************************************************************************************************
// Add focal elements of a singleton 
//**************************************************************************************************
void DSVector::addFocalEleSingleton(void)
{
	string st;

	cin >> st;
	singleton.push_back(st);
	no_singletons++;
	focal_element.resize(pow(2, no_singletons), 0); 
}

//**************************************************************************************************
// Print focal elements, without normalizing 
//**************************************************************************************************
void DSVector::printFocalElements(void)
{
	for (int i = 0; i < pow(2, no_singletons); i++)
		cout << focal_element[i] << endl;
		 
}

//**************************************************************************************************
// Print focal elements normalized 
//**************************************************************************************************
void DSVector::printFocalElementsNormalized(void)
{
	for (int i = 0; i < pow(2, no_singletons); i++)
		cout << (int)focal_element[i] / normalizing_const << endl;
		 
}

//**************************************************************************************************
// Print singleton vector 
//**************************************************************************************************
void DSVector::printSingletonVector(void)
{
	for (it_str = singleton.begin(); it_str != singleton.end(); it_str++)
		cout << *it_str << " ";
	cout << endl;
}

//**************************************************************************************************
// Print singleton vector 
//**************************************************************************************************
void DSVector::printBliefInvVec(void)
{
	cout << "Belief inverse vector \t: " << endl;
	for (int i = 0; i < belief_inv_ele_vec.size(); i++)
	{
		cout << belief_inv_ele_vec[i] << endl;
	}	
}
