// Practice_LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "C_MyLinkedList.h"


using namespace std;


int main()
{
    C_MyLinkedList<double> List1;
    double val;
    srand(time(NULL));

    cout << "疊翴计\n";
    for (int i = 0; i < 10; i++) {
        val = (double)rand() / 100;
        List1.AddBack(val);
    }
    List1.Show();

    cout << "ㄢ疊翴计玡\n";
    for (int i = 0; i < 2; i++) {
        val = (double)rand() / 100;
        List1.AddFront(val);
    }
    List1.Show();

    cout << "疊翴计竚5\n";
    val = (double)rand() / 100;
    List1.Insert(5, val);
    List1.Show();

    cout << "埃疊翴计竚7\n";
    List1.Remove(7);
    List1.Show();

    cout << "盢listは锣\n";
    List1.Inverse();
    List1.Show();


    return 0;
}

