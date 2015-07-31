#include "dsvector.h"

using namespace std;

DSVector::DSVector(void)
{
	debug = false;
	focal_element.assign(1048576, 0);
	focal_index.assign(1048576, 0);
}

DSVector::DSVector(int singletons)
{
	debug = false;
	focal_element.assign(pow(2, singletons), 0);
	focal_index.assign(pow(2, singletons), 0);
}

void DSVector::debugOn(void)
{
	debug = true;
}

void DSVector::debugOff(void)
{
	debug = false;
}

void DSVector::getSingletons(void)				// getting singleton names
{
	string st;
	cin >> no_singletons;
	for (int i = 0; i < no_singletons; i++)
	{
		cin >> st;				// reading a singleton name from std input
		singleton.push_back(st);
	}
}

int DSVector::calFocalIndexAnyOrder(void)				// calculating the focal element index
{
	int focal_ele_index = 0;
	string st;
	cin >> no_sin_focalele;				// number of singletons in a one focal element 
	for (int i = 0; i< no_sin_focalele; i++)	
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

int DSVector::calFocalIndexAscending(void)			// calculating the focal element index, fast
{
	int focal_ele_index = 0;
	int cnt = 0;
	string st;
	cin >> no_sin_focalele;				// number of singletons in a one focal element 
	for (int i = 0; i< no_sin_focalele; i++)	
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

void DSVector::fillingBeliefVecAnyOrder(void)			// filling belief vector, any order	
{
	belief_ele_vec.clear();
	string st;
	cin >> no_sin_belief;	
	for (int i = 0; i< no_sin_belief; i++)	
	{
		cin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				belief_ele_vec.push_back(pow(2, j));	
	}
}

void DSVector::fillingBeliefVecAscending(void)			// filling belief vector, fast(ascending)
{
	belief_ele_vec.clear();
	int cnt = 0;
	string st;
	cin >> no_sin_belief;	
	for (int i = 0; i< no_sin_belief; i++)	
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

void DSVector::fillingPlausibilityVecAnyOrder(void)		// filling plausibility vector, any order	
{
	plausibility_ele_vec.clear();
	string st;
	cin >> no_sin_plausibility;	
	for (int i = 0; i< no_sin_plausibility; i++)	
	{
		cin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				plausibility_ele_vec.push_back(pow(2, j));	
	}
}

void DSVector::fillingPlausibilityVecAscending(void)		// filling plausibility vector, fast(ascending)
{
	plausibility_ele_vec.clear();
	int cnt = 0;
	string st;
	cin >> no_sin_plausibility;	
	for (int i = 0; i< no_sin_plausibility; i++)	
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

void DSVector::fillingBeliefInvVecAnyOrder(void)			// filling belief_inv vector, any order	
{							// to calculate plausibility
	belief_inv_ele_vec.clear();
	string st;
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

void DSVector::fillingBeliefInvVecAscending(void)			// filling belief_inv vector, fast(ascending)
{							// to calculate plausibility
	belief_inv_ele_vec.clear();
	int cnt = 0;
	string st;
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

void DSVector::genRandomMassValues(void)
{
	srand(time(NULL)); 				// initialize random seed
	focal_element[0] = 0.0;			// assign value 0.0 to null element
	for (int i = 1; i < pow(2, no_singletons); i++)
	{
		focal_element[i] = rand() % 10000;	// generate a random number between 0 and 9999
		normalize_const += focal_element[i];	// finding normalizing constant
	}
	// no need to normalize everytime, we can normalize only when we use
	//	for (int i = 0; i < pow(2, no_singletons); i++)
	//		focal_element[i] /= normalize_const;

	if (debug)
		for (int i = 0; i < pow(2, no_singletons); i++)
			cout << "mass(" << i << ") \t: " << focal_element[i] / normalize_const << endl;
}

void DSVector::genIncreasingMassValues(void)			// specially for testing
{
	srand(time(NULL)); 				// initialize random seed
	focal_element[0] = 0.0;			// assign value 0.0 to null element
	for (int i = 1; i < pow(2, no_singletons); i++)
	{
		focal_element[i] = i;			// generate a random number between 0 and 9999
		normalize_const += focal_element[i];	// finding normalizing constant
	}
	// no need to normalize everytime, we can normalize only when we use
	//	for (int i = 0; i < pow(2, no_singletons); i++)
	//		focal_element[i] /= normalize_const;

	if (debug)
		for (int i = 0; i < pow(2, no_singletons); i++)
			cout << "mass(" << i << ") \t: " << focal_element[i] / normalize_const << endl;
}

double DSVector::accessFocalElement(int index)
{
	double element;
	begin = clock();
	element = focal_element[index];
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	if (debug)
		cout << "Focal element " << index << "\t: " << element << endl;
	cout << "Time spent on accessing a focal element\t: " << time_spent << endl;
	return element;
}

double DSVector::calBelief(void)
{
	double belief = 0.0;
	begin = clock();
	int focal_index_cnt = 0, focal_index_temp;
	for (int i = 0; i < no_sin_belief; i++)		// finding all the indexes
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
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating belief \t: " << time_spent << endl;
	cout << "Belief of " << pow(2, no_sin_belief) - 1 << " focal elements \t\t: " << belief / normalize_const << endl;
	return belief / normalize_const;
}

double DSVector::calPlausibility(void)
{
	double plausibility = 0.0, belief_inv = 0.0;
	begin = clock();
	int focal_index_cnt = 0, focal_index_temp;
	for (int i = 0; i < no_singletons - no_sin_plausibility; i++)	// finding all the indexes
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
		plausibility = normalize_const - belief_inv;
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating plausibility \t: " << time_spent << endl;
	cout << "Plausibility of " << (int)pow(2, no_singletons) - (int)pow(2, no_singletons - no_sin_plausibility) - 1 << " focal ele \t: " << plausibility / normalize_const << endl;
	return plausibility / normalize_const;
}

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
		singleton.erase(singleton.begin() + singleton_number);
	while (pow(2, singleton_number) * 2 * start <= pow(2, no_singletons))
	{
		for (int i = pow(2, singleton_number) * (2 * start - 1); i < pow(2, singleton_number) * 2 * start; i++) 
		{
			normalize_const -= focal_element[i];
		}
		if (start > 1)
			copy(focal_element.begin() + (int)pow(2, singleton_number) * 2 * (start - 1), 
				focal_element.begin() + (int)pow(2, singleton_number) * 2 * (start - 1) + 
				(int)pow(2, singleton_number), focal_element.begin() +	
				(int)pow(2, singleton_number) * (start - 1));
		start++;
	}
	no_singletons--;
	focal_element.resize(pow(2, no_singletons));
 
}

void DSVector::addFocalEleSingleton(void)
{
	string st;
	cin >> st;
	singleton.push_back(st);
	no_singletons++;
	focal_element.resize(pow(2, no_singletons), 0); 
}

void DSVector::printFocalElements(void)				//print focal elements without normalizing
{
	for (int i = 0; i < pow(2, no_singletons); i++)
		cout << focal_element[i] << endl;
		 
}

void DSVector::printFocalElementsNormalized(void)			//print focal elements
{
	for (int i = 0; i < pow(2, no_singletons); i++)
		cout << (int)focal_element[i] / normalize_const << endl;
		 
}

void DSVector::printSingletonVector(void)				//print singleton vector
{
	for (it_str = singleton.begin(); it_str != singleton.end(); it_str++)
		cout << *it_str << " ";
	cout << endl;
}
