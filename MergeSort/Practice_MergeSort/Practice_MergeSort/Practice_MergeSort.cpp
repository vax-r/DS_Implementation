// Practice_MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "MergeSort.h"

using namespace std;



int main()
{
    srand((unsigned int)time(NULL));
    unsigned int a = 15;
    int* A = new int[a];
    for (unsigned int i = 0; i < a; i++) {
        A[i] = rand() % 150;
    }
    Show<int>(A, a);
    MergeSort<int>(A, a, CompareSmaller);
    Show<int>(A, a);
    MergeSort<int>(A, a, CompareBigger);
    Show<int>(A, a);

    return 0;
}



