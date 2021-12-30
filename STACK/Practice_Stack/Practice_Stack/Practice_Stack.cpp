// Practice_Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

#include "C_MyStack.h"

int main()
{
	int size,val;
	C_MyStack<int> MyStack;
	cout << "請輸入堆疊大小:";
	cin >> size;
	MyStack.SetSize(size);
	bool end_Stack = false;

	char console;
	int pos;
	while (!end_Stack) {
		cin >> console;
		switch (console) {
			case 'a':
				cin >> val;
				MyStack.Push(val);
				break;
			case 'b':
				MyStack.Pop(val);
				break;
			case 'c':
				cin >> pos>>val;
				MyStack.Insert(pos, val);
				break;
			case 'd':
				cin >> pos;
				MyStack.Delete(pos, val);
				break;
			case 'q':
				end_Stack = true;
				break;
		}
	}



	return 0;
}


