

#include <iostream>
#include <time.h>
#include "InsertionFunctions.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));

    unsigned int size = 15;
    int * T = new int[size];
 
    for (unsigned int i = 0; i < size; i++) {
        T[i] = rand();
    }
    Show<int>(T, size);
    InsertionSort<int>(T, size, CompareLarge);
    Show<int>(T, size);
    InsertionSort<int>(T, size, CompareSmall);
    Show<int>(T, size);

    cout << endl << endl;

    
    double* T1 = new double[size];

    for (unsigned int i = 0; i < size; i++) {
        T1[i] =(double) rand()/RAND_MAX;
    }
    Show<double>(T1, size);
    InsertionSort<double>(T1, size, CompareLarge);
    Show<double>(T1, size);
    InsertionSort<double>(T1, size, CompareSmall);
    Show<double>(T1, size);

    delete[]T;
    delete[]T1;

    
    return 0;
}


