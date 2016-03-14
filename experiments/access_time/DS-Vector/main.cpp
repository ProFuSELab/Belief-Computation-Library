#include "dsvector.h"

using namespace std;

int main()
{
        int index;
        double experiment_time, total_time = 0;
        DSVector ds_vector;
        ds_vector.debugOff();
        ds_vector.readSingletons();
        ds_vector.genIncreasingMassValues();
        index = ds_vector.calFocalIndexAscending();
	vector <int> param;
	srand(time(NULL));
	for (int fod = 1; fod <= 20; fod++)
	{
		for (int rounds = 0; rounds < 1000000; rounds++)
		{
			for (int i = 0; i < fod; i++)
			{
				if (rand() % 3 != 0)
					param.push_back(i);
			}
			experiment_time = ds_vector.accessFocalElementIndexVec(param);
			param.clear();
			total_time += experiment_time; 
		}
		cout << "FoD size : " << fod << " Time spent : " << total_time << endl;
		total_time = 0;
	}
        return 0;
}
