// Bubbule_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BubbleSort.h"

using namespace std;

int main()
{
    srand(time(NULL));
    int* A = new int[10];
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 50;
    }
    Show<int>(A, 10);
    BubbleSort<int>(A, 10, CompareLarge<int>,Swap<int>);
    Show<int>(A, 10);
    BubbleSort<int>(A, 10, CompareSmall<int>,Swap<int>);
    Show<int>(A, 10);


    return 0;
}


