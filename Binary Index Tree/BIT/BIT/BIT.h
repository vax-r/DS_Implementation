#pragma once
#include <iostream>

using namespace std;

template <class T>
class BIT {
private:
	T* data;//initial data
	T* BITree;//binary index tree
	int tree_size;//size of the tree
public:
	BIT(T* init_data,int size);
	~BIT();
	int Lowbit(int i);
	void BuildTree();
	void Update(int index, T& value);
	T& Query(int index);
	void ShowTree();

};

template <class T>
inline BIT<T>::BIT(T* init_data,int size) {
	data = init_data;
	tree_size = size;
	BITree = new T[tree_size];
	this->BuildTree();
}

template <class T>
inline BIT<T>::~BIT() {
	delete[] data;
	delete[] BITree;
}

template <class T>
inline int BIT<T>::Lowbit(int i) {
	return i & (-i);
}

template <class T>
inline void BIT<T>::BuildTree() {
	for (int i = 0; i < tree_size; i++) {
		BITree[i] = 0;
		for (int j = 0; j < Lowbit(i+1); j++) {
			BITree[i] += this->data[i - j];
		}
	}
}

template <class T>
inline void BIT<T>::ShowTree() {
	for (int i = 0; i < tree_size; i++) {
		cout << BITree[i] << " ";
	}
	cout << endl;
}


template <class T>
inline void BIT<T>::Update(int index, T& value) {
	T change = value - this->data[index];
	this->data[index] = value;
	for (int i = index; i < tree_size; i += Lowbit(i+1)) {
		this->BITree[i] += change;
	}
}

template <class T>
inline T& BIT<T>::Query(int index) {
	T out = 0;

	for (int i = index; i > 0; i -= Lowbit(i+1)) {
		out += this->BITree[i];
	}

	return out;
}