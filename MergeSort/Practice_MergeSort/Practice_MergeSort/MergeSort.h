#pragma once


#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template <class T>
void Merge(T* arrayA, unsigned int SizeA, T* arrayB, unsigned int SizeB, bool(*comparefunc)(T a, T b)) {
	unsigned int i, j, x = 0;
	unsigned int Total_Size = SizeA + SizeB;
	T* Result = new T[Total_Size];
	i = 0;
	j = 0;

	for (x = 0; x < Total_Size; x++) {
		

		if (comparefunc(i<SizeA?arrayA[i]:arrayB[j],j<SizeB?arrayB[j]:arrayA[i])) {
			Result[x] = i < SizeA ? arrayA[i] : arrayB[j];
			i < SizeA ? i++ : j++;
			
		}
		else {
			Result[x] = j < SizeB ? arrayB[j] : arrayA[i];
			j < SizeB ? j++ : i++;
		}
	}
	memcpy(arrayA, Result, sizeof(T) * Total_Size);
	delete[]Result;

}

template <class T>
void MergeSort(T* Array, unsigned int Size, bool(*comparefunc)(T a, T b)) {

	if (Size == 1)
		return;
	MergeSort<T>(Array, Size / 2, comparefunc);
	MergeSort<T>(Array + Size / 2, Size - Size / 2, comparefunc);
	Merge<T>(Array, Size / 2, Array + Size / 2, Size - Size / 2, comparefunc);
}

template <class T>
bool CompareBigger(T a, T b) {
	return a > b;
}

template <class T>
bool CompareSmaller(T a, T b) {
	return a < b;
}

template <class T>
void Show(T* array, unsigned int size) {
	for (unsigned int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl << endl;
}