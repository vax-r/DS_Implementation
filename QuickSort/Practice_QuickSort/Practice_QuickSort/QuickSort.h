#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
bool CompareBigger(T a, T b) {
	return a > b;
}

template <class T>
bool CompareSmaller(T a, T b) {
	return a < b;
}

template <class T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int times = 0;

template <class T>
void QuickSort(T* Array, unsigned int Size, bool(*comparefunc)(T a, T b)) {
	times++;
	
	T pivot = Array[0];
	
	if (Size <= 1)
		return;
	else if (Size == 2 && comparefunc(Array[0], Array[1]))
		return;

	unsigned int i = 0, j = Size - 1;

	while (i < j) {
		
		while (!comparefunc(pivot, Array[i]) && i < Size) {
			i++;
		}
		while (comparefunc(pivot, Array[j]) && j > 0) {
			j--;
		}

		if (i <= j)
			Swap<T>(Array[i], Array[j]);
	}
	Swap<T>(Array[0], Array[j]);
	QuickSort<T>(Array, j, comparefunc);
	QuickSort<T>(Array + j + 1, Size - j - 1, comparefunc);

}

template <class T>
void Show(T* array, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}