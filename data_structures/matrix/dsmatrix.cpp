#include "dsmatrix.h"

using namespace std;

DSMatrix::DSMatrix(void) // default 20 singletons
{
	no_singletons = 20;
	normalizing_const = 0.0;
	debug = false;
	vector<float> row;
	row.assign(1024, 0.0);
	focal_element.assign(1024, row);

	pair<int, int> index (0, 0);
	focal_index.assign(1048576, index);
}

DSMatrix::DSMatrix(int singletons) // have to pass the number of singletons
{
	no_singletons = singletons;
	normalizing_const = 0.0;
	debug = false;
	vector<float> row;
	row.assign(pow(2, (singletons + 1) / 2), 0.0);
	focal_element.assign(pow(2, singletons / 2), row);

	pair<int, int> index(0, 0);
	focal_index.assign(pow(2, singletons), index);
}

void DSMatrix::debugOn(void)
{
	debug = true;
}

void DSMatrix::debugOff(void)
{
	debug = false;
}

void DSMatrix::readSingletons(void)			// getting singleton names
{
	string st;
	cin >> no_singletons;
	for (int i = 0; i < no_singletons; i++)		// first singleton is theta1
	{
		cin >> st;				// reading a singleton name from std input
		if ( (i + 1) % 2 == 1)
			odd_singleton.push_back(st);
		else
			even_singleton.push_back(st);	
	}
}

pair<int, int> DSMatrix::calFocalIndexAnyOrder(void)	// calculating the focal element index
{
	int focal_ele_index_odd = 0;
	int focal_ele_index_even = 0;
	string st;
	bool found = false;
	cin >> no_sin_focalele;				// number of singletons in a one focal element 
	for (int i = 0; i < no_sin_focalele; i++)	
	{
		found = false;
		cin >> st; 
		for (int j = 0; j < odd_singleton.size(); j++)	// first singleton is a odd, j == 0 is for theta1 !!
			if (st == odd_singleton[j])
			{
				focal_ele_index_odd += pow(2, j);	
				found = true;
				break;
			}
		if (found)
			continue;

		for (int j = 0; j < even_singleton.size(); j++)
			if (st == even_singleton[j])
			{
				focal_ele_index_even += pow(2, j);
				break;
			}
	}

	if (debug)
		cout << "Focal element index\t: " << focal_ele_index_even << ", " << focal_ele_index_odd << endl;
	return make_pair(focal_ele_index_even, focal_ele_index_odd);
}	

pair<int, int> DSMatrix::calFocalIndexAscending(void)	// calculating the focal element index, fast
{
	int focal_ele_index_odd = 0;
	int focal_ele_index_even = 0;
	int cnt = 0, cnt_max = 0;
	string st;
	cin >> no_sin_focalele;				// number of singletons in a one focal element 
	cnt_max = max(odd_singleton.size(), even_singleton.size());
	for (int i = 0; i< no_sin_focalele; i++)	
	{
		cin >> st; 
		for (int j = cnt; j < cnt_max; j++)
			if (j < odd_singleton.size() && odd_singleton[j] == st)
			{
				focal_ele_index_odd += pow(2, j);
				cnt = j;
				break;
			}
			else if (j < even_singleton.size() && even_singleton[j] == st)
			{
				focal_ele_index_even += pow(2, j);	
				cnt = ++j;
				break;
			}
	}
	if (debug)
		cout << "Focal element index\t: " << focal_ele_index_even << ", " << focal_ele_index_odd << endl;
	return make_pair(focal_ele_index_even, focal_ele_index_odd);
}	

void DSMatrix::fillingBeliefVecAnyOrder(void)		// filling belief vector, any order	
{
	belief_ele_vec.clear();
	string st;
	bool found = false;
	cin >> no_sin_belief;	
	for (int i = 0; i < no_sin_belief; i++)	
	{
		found = false;
		cin >> st; 
		for (int j = 0; j < odd_singleton.size(); j++)	// first singleton is a odd, j == 0 is for theta1 !!
			if (st == odd_singleton[j])
			{
				belief_ele_vec.push_back(make_pair(0, pow(2, j)));	
				found = true;
				break;
			}

		if (found)				// no need to iterate even_singleton, if already found the singleton in odd_singleton
			continue;

		for (int j = 0; j < even_singleton.size(); j++)
			if (st == even_singleton[j])
			{
				belief_ele_vec.push_back(make_pair(pow(2, j), 0));
				break;
			}
	}
}

void DSMatrix::fillingBeliefVecAscending(void)		// filling belief vector, fast(ascending)
{
	belief_ele_vec.clear();
	int cnt = 0, cnt_max = 0;
	string st;
	cin >> no_sin_belief;	
	cnt_max = max(odd_singleton.size(), even_singleton.size());
	for (int i = 0; i < no_sin_belief; i++)	
	{
		cin >> st; 
		for (int j = cnt; j < cnt_max; j++)
			if (j < odd_singleton.size() && odd_singleton[j] == st)
			{
				belief_ele_vec.push_back(make_pair(0, pow(2, j)));	
				cnt = j;
				break;
			}
			else if (j < even_singleton.size() && even_singleton[j] == st)
			{
				belief_ele_vec.push_back(make_pair(pow(2, j), 0));
				cnt = ++j;
				break;
			}
	}
}

void DSMatrix::fillingPlausibilityVecAnyOrder(void)	// filling plausibility vector, any order	
{
	plausibility_ele_vec.clear();
	string st;
	bool found = false;
	cin >> no_sin_plausibility;	
	for (int i = 0; i< no_sin_plausibility; i++)
	{
		found = false;
		cin >> st; 
		for (int j = 0; j < odd_singleton.size(); j++)	// first singleton is a odd, j == 0 is for theta1 !!
			if (st == odd_singleton[j])
			{
				plausibility_ele_vec.push_back(make_pair(0, pow(2, j)));	
				found = true;
				break;
			}

		if (found)				// no need to iterate even_singleton, if already found the singleton in odd_singleton
			continue;

		for (int j = 0; j < even_singleton.size(); j++)
			if (st == even_singleton[j])
			{
				plausibility_ele_vec.push_back(make_pair(pow(2, j), 0));
				break;
			}
	}
}

void DSMatrix::fillingPlausibilityVecAscending(void)	// filling plausibility vector, fast(ascending)
{
	plausibility_ele_vec.clear();
	int cnt = 0, cnt_max = 0;
	string st;
	cin >> no_sin_plausibility;	
	cnt_max = max(odd_singleton.size(), even_singleton.size());
	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		for (int j = cnt; j < cnt_max; j++)
			if (j < odd_singleton.size() && odd_singleton[j] == st)
			{
				plausibility_ele_vec.push_back(make_pair(0, pow(2, j)));	
				cnt = j;
				break;
			}
			else if (j < even_singleton.size() && even_singleton[j] == st)
			{
				plausibility_ele_vec.push_back(make_pair(pow(2, j), 0));
				cnt = ++j;
				break;
			}
	}
}

vector<string> DSMatrix::oddEvenToAll(void)
{
	int minsize = min(odd_singleton.size(), even_singleton.size());
	int maxsize = max(odd_singleton.size(), even_singleton.size());
	all_singleton.clear();
	for (int i = 0; i < minsize; i++)
	{
		all_singleton.push_back(odd_singleton[i]);
		all_singleton.push_back(even_singleton[i]);
	}
	if (odd_singleton.size() > even_singleton.size())
		for (int i = minsize; i < maxsize; i++)
			all_singleton.push_back(odd_singleton[i]);
	else if (odd_singleton.size() < even_singleton.size())
		for (int i = minsize; i < maxsize; i++)
			all_singleton.push_back(even_singleton[i]);
	return all_singleton;
}

void DSMatrix::fillingBeliefInvVecAnyOrder(void)	// filling belief_inv vector, any order	
{							// to calculate plausibility
	belief_inv_ele_vec.clear();
	string st;
	cin >> no_sin_plausibility;	
	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		// have to finish this function
	}
}

void DSMatrix::fillingBeliefInvVecAscending(void)	// filling belief_inv vector, fast(ascending)
{							// to calculate plausibility
	belief_inv_ele_vec.clear();
	int minsize = min(odd_singleton.size(), even_singleton.size());
	int maxsize = max(odd_singleton.size(), even_singleton.size());
	int cnt = 0;
	bool half = false, found = false;
	string st;
	cin >> no_sin_plausibility;	


	for (int i = 0; i < no_sin_plausibility; i++)	
	{
		cin >> st; 
		found = false;

		for (int i = cnt; i < minsize; i++)
		{
			if (!half)
			{
				if (st != odd_singleton[i])
				{
					if (debug)
						cout << "odd : " << cnt << endl;
					belief_inv_ele_vec.push_back(make_pair(0, pow(2, i)));	
				}
				else if (st == odd_singleton[i])
				{
					half = true;
					found = true;
					break;
				}
			}
			
			if (st != even_singleton[i])
			{
				if (debug)
					cout << "even : " << cnt << endl;
				belief_inv_ele_vec.push_back(make_pair(pow(2, i), 0));
			}
			else
			{
				half = false;
				found = true;
				cnt++;
				break;
			}
			half = false;
			cnt++;
		}
		
		if (found)
			continue;

		if (cnt >= minsize)
		{
			if (odd_singleton.size() > even_singleton.size())
				for (int i = cnt; i < maxsize; i++)
				{
					if (st != odd_singleton[i])
					{
						cout << "odd : " << cnt << endl;
						belief_inv_ele_vec.push_back(make_pair(0, pow(2, i)));
					}
					else
					{
						cnt = i + 1;
						break;
					}
				}
			else if (odd_singleton.size() < even_singleton.size())
				for (int i = cnt; i < maxsize; i++)
				{
					if (st != even_singleton[i])
					{
						cout << "even : " << cnt << endl;
						belief_inv_ele_vec.push_back(make_pair(pow(2, i), 0));
					}
					else
					{
						cnt = i + 1;
						break;
					}
				}
		}
	}
	while (cnt < maxsize)
	{
		if (cnt < odd_singleton.size() && !half)	
		{
			cout << "odd : " << cnt << endl;
			belief_inv_ele_vec.push_back(make_pair(0, pow(2, cnt)));	
		}
		if (cnt < even_singleton.size())
		{
			cout << "even : " << cnt << endl;
			belief_inv_ele_vec.push_back(make_pair(pow(2, cnt), 0));
		}
		half = false;
		++cnt;
	}
}

void DSMatrix::genRandomMassValues(void)
{
	srand(time(NULL)); 				// initialize random seed
	for (int row = 0; row < pow(2, no_singletons / 2); row++)
		for (int col = 0; col < pow(2, (no_singletons + 1) / 2); col++)
		{
			if (row == 0 && col == 0)
				focal_element[0][0] = 0.0;			// assign value 0.0 to null element
			else
				focal_element[row][col] = rand() % 10000;	// generate a random number between 0 and 9999
			normalizing_const += focal_element[row][col];	// finding normalizing constant
		}
	// no need to normalize everytime, we can normalize only when we use
	//	for (int i = 0; i < pow(2, no_singletons); i++)
	//		focal_element[i] /= normalizing_const;

	if (debug)
		for (int row = 0; row < pow(2, no_singletons / 2); row++)
			for (int col = 0; col < pow(2, (no_singletons + 1) / 2); col++)
				cout << "mass( " << row << " : " << col << " ) \t: " << focal_element[row][col] / normalizing_const << endl;
}

void DSMatrix::genIncreasingMassValues(void)		// specially for testing
{
	srand(time(NULL)); 				// initialize random seed
	for (int row = 0; row < pow(2, no_singletons / 2); row++)
		for (int col = 0; col < pow(2, (no_singletons + 1) / 2); col++)
		{
			if (row == 0 && col == 0) 
				focal_element[0][0] = 0.0;				// assign value 0.0 to null element
			focal_element[row][col] = col + row * pow(2, (no_singletons + 1) / 2);			// generate a random number between 0 and 9999
			normalizing_const += focal_element[row][col];	// finding normalizing constant
		}
	// no need to normalize everytime, we can normalize only when we use
	//	for (int i = 0; i < pow(2, no_singletons); i++)
	//		focal_element[i] /= normalizing_const;
	if (debug)
		for (int row = 0; row < pow(2, no_singletons / 2); row++)
			for (int col = 0; col < pow(2, (no_singletons + 1) / 2); col++)
				cout << "mass( " << row << " : " << col << " ) \t: " << focal_element[row][col] / normalizing_const << endl;
}

double DSMatrix::accessFocalElement(int row, int col)
{
	double element;
	begin = clock();
	element = focal_element[row][col];
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	if (debug)
		cout << "Focal element (" << row << ", " << col << ")\t: " << element << endl;
	cout << "Time spent on accessing a focal element\t: " << time_spent << endl;
	return element;
}

double DSMatrix::calBelief(void)
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
			focal_index[focal_index_cnt].first = focal_index[j].first + belief_ele_vec[i].first;	
			focal_index[focal_index_cnt].second = focal_index[j].second + belief_ele_vec[i].second;	
			focal_index_cnt++;
		}
	}

	for (int i = 0; i < pow(2, no_sin_belief) - 1; i++)
		belief += focal_element[focal_index[i].first][focal_index[i].second];
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating belief \t: " << time_spent << endl;
	cout << "Belief of " << pow(2, no_sin_belief) - 1 << " focal elements \t\t: " << belief / normalizing_const << endl;
	return belief / normalizing_const;
}

double DSMatrix::calPlausibility(void)
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
			focal_index[focal_index_cnt].first = focal_index[j].first + belief_inv_ele_vec[i].first;	
			focal_index[focal_index_cnt].second = focal_index[j].second + belief_inv_ele_vec[i].second;	
			focal_index_cnt++;
		}
	}

	for (int i = 0; i < pow(2, no_singletons - no_sin_plausibility) - 1; i++)
		belief_inv += focal_element[focal_index[i].first][focal_index[i].second];
		plausibility = normalizing_const - belief_inv;
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Time spent on calculating plausibility \t: " << time_spent << endl;
	cout << "Plausibility of " << (int)pow(2, no_singletons) - (int)pow(2, no_singletons - no_sin_plausibility) - 1 << " focal ele \t: " << plausibility / normalizing_const << endl;
	return plausibility / normalizing_const;
}

void DSMatrix::removeFocalEleSingleton(void)
{
	string st;
	int singleton_number;
	int start = 1;
	bool odd = false, even = false;
	cin >> st;
	for (int i = 0; i < odd_singleton.size(); i++)
		if (st == odd_singleton[i])
		{
			odd = true;
			singleton_number = i;
			break;
		}
	if (!odd)
		for (int i = 0; i < even_singleton.size(); i++)
			if (st == even_singleton[i])
			{
				even = true;
				singleton_number = i;
				break;
			}

	if (!odd && !even)
	{
		cout << endl << "Wrong input !!, please enter a correct singleton" << endl;
		return;
	}

	if (odd) 	// odd singletons
	{
		while (pow(2, singleton_number) * 2 * start <= pow(2, odd_singleton.size()))
		{
			for (int j = 0; j < pow(2, even_singleton.size()); j++)
			{
				for (int i = pow(2, singleton_number) * (2 * start - 1); i < pow(2, singleton_number) 
					* 2 * start; i++) 
				{
					normalizing_const -= focal_element[j][i];
				}
				if (start > 1)
					copy(focal_element[j].begin() + (int)pow(2, singleton_number) * 2 * (start - 1), 
						focal_element[j].begin() + (int)pow(2, singleton_number) * 2 * (start - 1) 
						+ (int)pow(2, singleton_number), 
						focal_element[j].begin() + (int)pow(2, singleton_number) * (start - 1));
			}
			start++;
		}
		odd_singleton.erase(odd_singleton.begin() + singleton_number);
		no_singletons--;
		/* Only if it is needed to resize
		for (int j = 0; j < pow(2, even_singleton.size()); j++)
			focal_element[j].resize(pow(2, odd_singleton.size()));
		focal_element.resize(pow(2, even_singleton.size()));
		*/
		cout << endl << "Removed an odd singleton (\"" << st << "\")" << endl;
	}
	if (even) 	// even singletons
	{
		while (pow(2, singleton_number) * 2 * start <= pow(2, even_singleton.size()))
		{
			for (int j = 0; j < pow(2, odd_singleton.size()); j++)
			{
				for (int i = pow(2, singleton_number) * (2 * start - 1); i < pow(2, singleton_number) 
					* 2 * start; i++) 
				{
					normalizing_const -= focal_element[i][j];
				}
				if (start > 1)
				{
					int cnt_loop = 0;
					for (int i = (int)pow(2, singleton_number) * 2 * (start - 1); i < (int)pow(2, singleton_number) * 2 * (start - 1) + (int)pow(2, singleton_number); i++)
					{
						focal_element[cnt_loop + (int)pow(2, singleton_number) * (start - 1)][j] = focal_element[i][j];	
						cnt_loop++;
					}
				}
			}
			start++;
		}
		even_singleton.erase(even_singleton.begin() + singleton_number);
		no_singletons--;
		/* Only if it is needed to resize
		for (int j = 0; j < pow(2, even_singleton.size()); j++)
			focal_element[j].resize(pow(2, odd_singleton.size()));
		focal_element.resize(pow(2, even_singleton.size()));
		*/
		cout << endl << "Removed an even singleton (\"" << st << "\")" << endl;
	}
	cout << "Odd singletons      \t : " << odd_singleton.size() << endl;
	cout << "Even singletons     \t : " << even_singleton.size() << endl;
	cout << "New Matrix size     \t : " << pow(2, even_singleton.size()) << " * " << pow(2, odd_singleton.size()) << endl;
	cout << "Total allocation    \t : " << focal_element.size() << " * " << focal_element[0].size() << endl;
	cout << "Normalizing constant\t : " << normalizing_const << endl;
}

void DSMatrix::addFocalEleSingleton(void)
{
	string st;
	cin >> st;
	if (odd_singleton.size() <= even_singleton.size())
		odd_singleton.push_back(st);
	else
		even_singleton.push_back(st);
	no_singletons++;

	if (focal_element[0].size() < pow(2, odd_singleton.size()))
		for (int i = 0; i < focal_element.size(); i++)
			focal_element[i].resize((int)pow(2, odd_singleton.size()), 0);

	if (focal_element.size() < pow(2, even_singleton.size()))
	{
		vector<float> row;
		row.assign(focal_element[0].size(), 0.0);
		focal_element.resize((int)pow(2, even_singleton.size()), row);
	}
}

void DSMatrix::printFocalElements(void)				//print focal elements without normalizing
{
	for (int j = 0; j < pow(2, even_singleton.size()); j++)
	{
		for (int i = 0; i < pow(2, odd_singleton.size()); i++)
			cout << focal_element[j][i] << "\t";
		cout << endl;
	}
}

void DSMatrix::printFocalElementsNormalized(void)		//print focal elements
{
	for (int j = 0; j < pow(2, even_singleton.size()); j++)
	{
		for (int i = 0; i < pow(2, odd_singleton.size()); i++)
			cout << focal_element[j][i] / normalizing_const << "\t";
		cout << endl;
	}
}

void DSMatrix::printSingletonVector(void)			//print singleton vector
{
	cout << endl << "Odd singletons  \t : ";
	for (it_str = odd_singleton.begin(); it_str != odd_singleton.end(); it_str++)
		cout << *it_str << " ";
	if (odd_singleton.size() == 0)
		cout << "NONE";
	cout << endl;

	cout << "Even singletons \t : ";
	for (it_str = even_singleton.begin(); it_str != even_singleton.end(); it_str++)
		cout << *it_str << " ";
	if (even_singleton.size() == 0)
		cout << "NONE" << endl;
	cout << endl;
}

void DSMatrix::printBeliefInvVec(void)
{
	cout << "Belief inverse vector \t: " << endl;
	for (int i = 0; i < belief_inv_ele_vec.size(); i++)
	{
		cout << belief_inv_ele_vec[i].first << " : " << belief_inv_ele_vec[i].second << endl;
	}
}
