#include "dsmatrix.h"

using namespace std;

int main()
{
        pair<int, int> index;
        double experiment_time, total_time = 0;
	vector <int> row_param, col_param;
        DSMatrix ds_matrix;
        ds_matrix.debugOff();
        ds_matrix.readSingletons();
        ds_matrix.genIncreasingMassValues();

	for (int fod = 1; fod <= 20; fod++)
	{       
		for (int rounds = 0; rounds < 1000000; rounds++)
		{       
			for (int i = 0; i < fod; i++)
			{       
				if (rand() % 3 == 0)
				{
					if (i % 2 == 1)
						row_param.push_back(i / 2);
					else
						col_param.push_back(i / 2);
				}
			}
			ds_matrix.fillingBeliefVecRandom(row_param, col_param);
			experiment_time = ds_matrix.calBelief();
			row_param.clear();
			col_param.clear();
			total_time += experiment_time;
		}
		cout << "FoD size : " << fod << " Time spent : " << total_time << endl;
		total_time = 0;
	}


        return 0;
}
