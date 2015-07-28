#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

float focal_elements[1048576], normalize_const; 	// 1048576 focal elements from 20 singletons
int focal_index[1048576];
vector<string> singleton;

int main()
{
	int no_singletons, no_sin_focalele, no_sin_belief, no_sin_plausibility;
	int focal_ele_index = 0;
	clock_t begin, end;
	double time_spent;
	string st;
	vector<int> belief_ele_vec;

	ifstream fin("vector.in");

	fin >> no_singletons;
	for (int i = 0; i < no_singletons; i++)
	{
		fin >> st;
		singleton.push_back(st);
	}

	fin >> no_sin_focalele;				// calculating the index
	for (int i = 0; i< no_sin_focalele; i++)	
	{
		fin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				focal_ele_index += pow(2, j);	
	}

	fin >> no_sin_belief;				// calculating the index
	for (int i = 0; i< no_sin_belief; i++)	
	{
		fin >> st; 
		for (int j = 0; j < singleton.size(); j++)
			if (st == singleton[j])
				belief_ele_vec.push_back(pow(2, j));	
	}
	
	fin.close();

	srand(time(NULL)); 				// initialize random seed
	
	for (int i = 0; i < pow(2, no_singletons); i++)
		focal_elements[i] = rand() % 10000;	// generate random number between 0 and 9999

	for (int i = 0; i < pow(2, no_singletons); i++)	// finding normalizing constant
		normalize_const += focal_elements[i];
	
	for (int i = 0; i < pow(2, no_singletons); i++)	// normalizing 
		focal_elements[i] /= normalize_const;
	
	ofstream fout("vector.out");
		
	for (int i = 0; i < pow(2, no_singletons); i++)
		fout << focal_elements[i] << endl;


	fout << focal_ele_index << endl;
	int element;
	begin = clock();
	element = focal_elements[focal_ele_index];
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	fout << time_spent << endl;

	begin = clock();
	int focal_index_cnt = 0, focal_index_temp;
	for (int i = 0; i < no_sin_belief; i++)
	{ 
		focal_index[focal_index_cnt] = belief_ele_vec[i];
		focal_index_cnt++;
		focal_index_temp = focal_index_cnt - 1;
		for(int j = 0; j < focal_index_temp; j++)
		{
			focal_index[focal_index_cnt] = focal_index[j] + belief_ele_vec[i];	
			focal_index_cnt++;
		//	cout << focal_index_cnt << endl;
		}
	}
	cout << "test" << endl;
	double belief = 0;
	
	for (int i = 0; i < pow(2, no_sin_belief) - 1; i++)
		belief += focal_elements[focal_index[i]];
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	fout << time_spent << endl;

	fout << belief << endl;
			 	
	fout.close();
	
	return 0;
}
