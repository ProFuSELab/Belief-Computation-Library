#include "dstree.h"

using namespace std;

int main()
{
        int index;
        double element;
        DSTree ds_tree;
        ds_tree.debugOff();
        ds_tree.readSingletons();
        ds_tree.genIncreasingMassValues();
        index = ds_tree.calFocalIndexAscending();
        element = ds_tree.accessFocalElement(index);
        ds_tree.fillingBeliefVecAscending();
        ds_tree.calBelief();
        ds_tree.fillingBeliefInvVecAscending();
        ds_tree.calPlausibility();
        ds_tree.printSingletonVector();
        ds_tree.printFocalElements();
        ds_tree.removeFocalEleSingleton();
        ds_tree.printFocalElements();
        ds_tree.removeFocalEleSingleton();
        ds_tree.printFocalElements();
	/*
        ds_tree.printSingletonVector();
        ds_tree.removeFocalEleSingleton();
        ds_tree.addFocalEleSingleton();
        ds_tree.printSingletonVector();
        ds_tree.printFocalElements();
*/            
        return 0;
}
