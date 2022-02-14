// BIT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#include "BIT.h"

int main()
{
    int size = 8;
    int* test = new int[size];
    for (int i = 0; i < size; i++)
        test[i] = i;

    BIT<int> t1(test, size);

    t1.ShowTree();
    
    int n = 5;
    t1.Update(3, n);
    t1.ShowTree();

    n = 3;
    cout << t1.Query(n);

    return 0;
}

