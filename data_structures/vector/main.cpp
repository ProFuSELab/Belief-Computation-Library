#include "dsvector.h"

using namespace std;

int main()
{
        int index;
        double element;
        DSVector ds_vector;
        ds_vector.debugOff();
        ds_vector.readSingletons();
        index = ds_vector.calFocalIndexAscending();
        element = ds_vector.accessFocalElement(index);
        ds_vector.genIncreasingMassValues();
        ds_vector.fillingBeliefVecAscending();
        ds_vector.calBelief();
        ds_vector.fillingBeliefInvVecAscending();
        ds_vector.calPlausibility();
        ds_vector.printSingletonVector();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.removeFocalEleSingleton();
        ds_vector.printSingletonVector();
        ds_vector.printFocalElements();
        ds_vector.removeFocalEleSingleton();
        ds_vector.addFocalEleSingleton();
        ds_vector.printSingletonVector();
        ds_vector.printFocalElements();
            
        return 0;
}
