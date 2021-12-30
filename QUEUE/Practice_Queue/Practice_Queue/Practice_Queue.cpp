// Practice_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "C_MyQueue.h"

using namespace std;


int main()
{
    srand(time(NULL));
    C_MyQueue<double> C1;
    int size;
    double val;
    cin >> size;
    C1.SetSize(size);
    for (int i = 0; i < size; i++) {
        val = (double)rand() / RAND_MAX;
        C1.Push(val);
    }
    C1.ShowQueue();
    cout << "/////////////////" << endl;
    for (int i = 0; i < size; i++) {
        C1.Pop(val);
        cout << val << endl;
    }
    

    return 0;
}


