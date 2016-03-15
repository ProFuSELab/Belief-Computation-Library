#include "dstree.h"

using namespace std;

int main()
{
        int index;
        double experiment_time, total_time = 0;
        DSTree ds_tree;
        ds_tree.debugOff();
	
	vector <int> param;
	srand(time(NULL));
	for (int fod = 1; fod <= 20; fod++)
	{
		ds_tree.addSingleton();
		ds_tree.genIncreasingMassValues();
		for (int rounds = 0; rounds < 10000; rounds++)
		{
			for (int i = 0; i < fod; i++)
			{
				if (rand() % 3 != 0)
				param.push_back(i);
			}
			experiment_time = ds_tree.accessFocalElementIndexVec(param);
			param.clear();
			total_time += experiment_time;
		}
		cout << "FoD size : " << fod << " Time spent : " << total_time << endl;
		total_time = 0;
	}

        return 0;
}
