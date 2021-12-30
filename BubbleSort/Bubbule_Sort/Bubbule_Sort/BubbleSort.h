#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
void BubbleSort(T* array, int Size, bool(*comparefunc)(T a, T b),void(*swap)(T &a,T &b)) {
	bool change = false;

	for (int i = 0; i < Size-1; i++) {
		for (int j = 0; j < Size - 1 - i; j++) {
			if (comparefunc(array[j], array[j + 1]) == true) {
				swap(array[j], array[j + 1]);
				change = true;
			}
		}
		if (change == false)
			break;
	}
}

template<class T>
void Swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<class T>
bool CompareLarge(T a, T b) {
	if (a > b)
		return true;
	else
		return false;
}

template<class T>
bool CompareSmall(T a, T b) {
	if (a < b)
		return true;
	else
		return false;
}

template<class T>
void Show(T* Array,int size) {
	for (int i = 0; i < size; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}