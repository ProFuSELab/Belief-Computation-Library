#include "dslist.h"

using namespace std;

int main()
{
	double experiment_time, total_time = 0;
	vector <int> param;
	DSList ds_list;
	ds_list.debugOff();
	ds_list.readSingletons();

	for (int fod = 1; fod <= 20; fod++)
	{       
		ds_list.genRandomList(fod);
		for (int rounds = 0; rounds < 100000; rounds++)
		{       
			for (int i = 0; i < fod; i++)
			{       
				if (rand() % 3 == 0)
				param.push_back(i);
			}
			ds_list.fillingBeliefVecRandom(param);
			experiment_time = ds_list.calBelief();

			param.clear();
			total_time += experiment_time;
		}
		cout << "FoD size : " << fod << " Time spent : " << total_time << endl;
		total_time = 0;
	}
	
	return 0;
}



