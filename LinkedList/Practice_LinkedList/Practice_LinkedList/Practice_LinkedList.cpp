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

    cout << "��J�Q�ӯB�I��\n";
    for (int i = 0; i < 10; i++) {
        val = (double)rand() / 100;
        List1.AddBack(val);
    }
    List1.Show();

    cout << "���ӯB�I�Ʀb�e��\n";
    for (int i = 0; i < 2; i++) {
        val = (double)rand() / 100;
        List1.AddFront(val);
    }
    List1.Show();

    cout << "��@�ӯB�I�Ʀb��m5\n";
    val = (double)rand() / 100;
    List1.Insert(5, val);
    List1.Show();

    cout << "�R���@�ӯB�I�Ʀb��m7\n";
    List1.Remove(7);
    List1.Show();

    cout << "�Nlist����\n";
    List1.Inverse();
    List1.Show();


    return 0;
}

