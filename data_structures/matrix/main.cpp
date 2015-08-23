#include "dsmatrix.h"

using namespace std;

int main()
{
        pair<int, int> index;
        double element;
        DSMatrix ds_matrix;
        ds_matrix.debugOff();
        ds_matrix.readSingletons();
        index = ds_matrix.calFocalIndexAscending();
        element = ds_matrix.accessFocalElement(index.first, index.second);
        ds_matrix.genIncreasingMassValues();
        ds_matrix.fillingBeliefVecAscending();
        ds_matrix.calBelief();
        ds_matrix.fillingBeliefInvVecAscending();
	ds_matrix.printBeliefInvVec();
        ds_matrix.calPlausibility();
        ds_matrix.printSingletonVector();
	ds_matrix.printFocalElements();
	ds_matrix.removeFocalEleSingleton();
	ds_matrix.printFocalElements();
	ds_matrix.removeFocalEleSingleton();
	ds_matrix.printFocalElements();
	ds_matrix.removeFocalEleSingleton();
	ds_matrix.printFocalElements();
	ds_matrix.removeFocalEleSingleton();
	ds_matrix.printFocalElements();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
	ds_matrix.printFocalElements();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.printSingletonVector();
        ds_matrix.printFocalElements();
        ds_matrix.removeFocalEleSingleton();
        ds_matrix.addFocalEleSingleton();
        ds_matrix.printSingletonVector();
        ds_matrix.printFocalElements();
        return 0;
}
