#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
void InsertionSort(T* Array,unsigned int size, bool(*comparefunc)(T a, T b)) {

	unsigned int i, j, bound;
	for (i = 1; i < size; i++) {
		bound = i;
		for (j = 0; j < bound; j++) {
			if (comparefunc(Array[bound], Array[j]) == true) {
				T temp = Array[bound];
				for (unsigned int k = bound; k > j; k--) {
					Array[k] = Array[k - 1];
				}
				Array[j] = temp;
			}
		}
	}

}

template <class T>
bool CompareLarge(T a, T b) {
	if (a > b)
		return true;
	else
		return false;
}

template <class T>
bool CompareSmall(T a, T b) {
	if (a < b)
		return true;
	else
		return false;
}

template <class T>
void Show(T* Array,unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		cout << Array[i] << " ";
	}
	cout << endl;
}

