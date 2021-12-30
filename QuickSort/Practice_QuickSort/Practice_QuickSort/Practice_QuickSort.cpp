// Practice_QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <time.h>
#include <iostream>
#include "QuickSort.h"

int main()
{   
    srand((unsigned int)time(NULL));
    unsigned int SizeA = 15;
    int* A = new int[SizeA];
    
    for (unsigned int i = 0; i < SizeA; i++) {
        A[i] = rand() % 200;
    }
    Show<int>(A, SizeA);
    QuickSort<int>(A, SizeA, CompareSmaller);
    Show<int>(A, SizeA);
    QuickSort<int>(A, SizeA, CompareBigger);
    Show<int>(A, SizeA);


    return 0;
}


