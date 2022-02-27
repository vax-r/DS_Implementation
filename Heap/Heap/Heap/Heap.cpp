// Heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    unsigned int size = 10;
    int* a = new int[size];
    Heap_type t = Heap_type::Max;
    for (unsigned int i = 0; i < size; i++)
        a[i] = i;
    Heap<int> Max_h(a, size, t);
    Max_h.ShowHeap();
    
    //Max_h.Expand_Capacity();
    Max_h.InsertNode(10);
    Max_h.ShowHeap();
    //Max_h.HeapSort();



    int* b = new int[size];
    for (unsigned int i = 0; i < size; i++)
        b[i] = i;

    Heap_type t2 = Heap_type::Min;
    Heap<int> Min_h(b, size, t2);
    Min_h.ShowHeap();

    Min_h.InsertNode(11);
    Min_h.ShowHeap();


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
