#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;


class DS_Vector
{
	private:
		int no_singletons, no_sin_focalele, no_sin_belief, no_sin_plausibility;
		vector<string> singleton;				// vector of singleton names
		vector<int> belief_ele_vec;				// integer value of singletons in a "belief"
		vector<int> plausibility_ele_vec;			// integer value of singletons in a "plausibility"
		vector<int> belief_inv_ele_vec;				// integer value of singletons in a "belief complement"
		vector<float> focal_elements; 				// 1048576 focal elements from 20 singletons
		vector<int> focal_index;
		double normalize_const;
		bool debug;
		clock_t begin, end;
		double time_spent;

	public:
		DS_Vector(void)
		{
			debug = false;
			focal_elements.assign(1048576, 0);
			focal_index.assign(1048576, 0);
		}

		DS_Vector(int singletons)
		{
			debug = false;
			focal_elements.assign(pow(2, singletons), 0);
			focal_index.assign(pow(2, singletons), 0);
		}

		void debugOn(void)
		{
			debug = true;
		}
	
		void debugOff(void)
		{
			debug = false;
		}

		void getSingletons(void)				// getting singleton names
		{
			string st;
			cin >> no_singletons;
			for (int i = 0; i < no_singletons; i++)
			{
				cin >> st;				// reading a singleton name from std input
				singleton.push_back(st);
			}
		}

		int calFocalIndexAnyOrder(void)				// calculating the focal element index
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

		int calFocalIndexAscending(void)			// calculating the focal element index, fast
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

		void fillingBeliefVecAnyOrder(void)			// filling belief vector, any order	
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

		void fillingBeliefVecAscending(void)			// filling belief vector, fast(ascending)
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

		void fillingPlausibilityVecAnyOrder(void)		// filling plausibility vector, any order	
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

		void fillingPlausibilityVecAscending(void)		// filling plausibility vector, fast(ascending)
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

		void fillingBeliefInvVecAnyOrder(void)			// filling belief_inv vector, any order	
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

		void fillingBeliefInvVecAscending(void)			// filling belief_inv vector, fast(ascending)
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

		void genRandomMassValues(void)
		{
			srand(time(NULL)); 				// initialize random seed
			focal_elements[0] = 0.0;			// assign value 0.0 to null element
			for (int i = 1; i < pow(2, no_singletons); i++)
			{
				focal_elements[i] = rand() % 10000;	// generate a random number between 0 and 9999
				normalize_const += focal_elements[i];	// finding normalizing constant
			}
			// no need to normalize everytime, we can normalize only when we use
			//	for (int i = 0; i < pow(2, no_singletons); i++)
		 	//		focal_elements[i] /= normalize_const;

			if (debug)
				for (int i = 0; i < pow(2, no_singletons); i++)
					cout << "mass(" << i << ") \t: " << focal_elements[i] / normalize_const << endl;
		}
		
		double accessFocalElement(int index)
		{
			double element;
			begin = clock();
			element = focal_elements[index];
			end = clock();
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			if (debug)
				cout << "Focal element " << index << "\t: " << element << endl;
			cout << "Time spent on accessing a focal element\t: " << time_spent << endl;
			return element;
		}
		
		double calBelief(void)
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
				belief += focal_elements[focal_index[i]];
			end = clock();
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Time spent on calculating belief \t: " << time_spent << endl;
			cout << "Belief of " << pow(2, no_sin_belief) - 1 << " focal elements \t\t: " << belief / normalize_const << endl;
			return belief / normalize_const;
		}

		double calPlausibility(void)
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
				belief_inv += focal_elements[focal_index[i]];
				plausibility = normalize_const - belief_inv;
			end = clock();
			time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << "Time spent on calculating plausibility \t: " << time_spent << endl;
			cout << "Plausibility of " << pow(2, no_singletons) - pow(2, no_singletons - no_sin_plausibility) - 1 << " focal ele \t: " << plausibility / normalize_const << endl;
			return plausibility / normalize_const;
		}
};

int main()
{
	int index;
	double element;
	DS_Vector ds_vector;
	ds_vector.debugOff();
	ds_vector.getSingletons();
	index = ds_vector.calFocalIndexAscending();
	element = ds_vector.accessFocalElement(index);
	ds_vector.genRandomMassValues();
	ds_vector.fillingBeliefVecAscending();
	ds_vector.calBelief();
	ds_vector.fillingBeliefInvVecAscending();
	ds_vector.calPlausibility();
	
	return 0;
}
