#pragma once
#include<iostream>
using namespace std;

template <class T>
struct data_row {
	int row;
	int col;
	T value;
};

template <class T>
class SparseMatrix {
private:
	int row_num;
	int col_num;
	int terms;
	int capacity;
	int Max_capacity;
	data_row<T>* elements;

public:
	SparseMatrix();
	SparseMatrix(int& row_num, int& col_num);
	~SparseMatrix();
	void ShowAll(data_row<T>* list = nullptr);
	void Insert(int& row,int& col,T& value);
	void ExpandSize();
	//void Delete(int& row,int& col);
	//SparseMatrix Add(SparseMatrix* b);
	//SparseMatrix Multiply(SparseMatrix* b);
	data_row<T>* Transpose();

};

template <class T>
inline SparseMatrix<T>::SparseMatrix() {
	row_num = 0;
	col_num = 0;
	terms = 0;
	capacity = 10;
	Max_capacity = 10;
	this->elements = new data_row<T>[capacity];
}

template <class T>
inline SparseMatrix<T>::SparseMatrix(int& row_num, int& col_num) {
	this->row_num = row_num;
	this->col_num = col_num;
	this->Max_capacity = row_num * col_num;
	this->capacity = 10;
	this->terms = 0;
	this->elements = new data_row<T>[capacity];
}

template <class T>
inline SparseMatrix<T>::~SparseMatrix() {
	delete[] this->elements;
}

template <class T>
inline void SparseMatrix<T>::ShowAll(data_row<T>* list) {

	cout << "\t\trow\tcol\tvalue\n";
	if (list==nullptr) {
		for (int i = 0; i < terms; i++) {
			cout << "elements " << i + 1 << ":\t" << elements[i].row << "\t" << elements[i].col << "\t" << elements[i].value << endl;
		}
	}
	else {
		for (int i = 0; i < terms; i++) {
			cout << "elements " << i + 1 << ":\t" << list[i].row << "\t" << list[i].col << "\t" << list[i].value << endl;
		}
	}

}

template <class T>
inline void SparseMatrix<T>::ExpandSize() {
	data_row<T>* new_elements = new data_row<T>[capacity + 10];
	memcpy(new_elements, this->elements, capacity);
	delete[] this->elements;
	this->elements = new_elements;
}

template <class T>
inline void SparseMatrix<T>::Insert(int& row, int& col, T& value) {
	
	if (terms + 1 > Max_capacity) {
		cout << "Matrix is full!" << endl;
		return;
	}

	if (row >= row_num) {
		cout << "Invalid row index!" << endl;
		return;
	}

	if (col >= col_num) {
		cout << "Invalid col index!" << endl;
		return;
	}
	
	if (terms + 1 > capacity)
		ExpandSize();

	elements[terms].row = row;
	elements[terms].col = col;
	elements[terms++].value = value;

}

template <class T>
inline data_row<T>* SparseMatrix<T>::Transpose() {
	
	data_row<T>* Transpose = new data_row<T>[terms];

	int k = 0;
	
	for (int i = 0; i < col_num; i++) {
		for (int j = 0; j < terms; j++) {
			if (elements[j].col == i) {
				Transpose[k].row = elements[j].col;
				Transpose[k].col = elements[j].row;
				Transpose[k++].value = elements[j].value;
			}
		}
	}

	return Transpose;
}