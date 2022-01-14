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
	SparseMatrix<T>* Multiply(SparseMatrix* b);
	data_row<T>* Transpose();
	data_row<T>* Fast_Transpose();

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
	if (capacity + 10 > Max_capacity) {
		cout << "exceeed max capacity!\n";
		return;
	}
	data_row<T>* new_elements = new data_row<T>[capacity + 10];
	memcpy(new_elements, this->elements, terms*sizeof(data_row<T>));
	delete[] this->elements;
	this->elements = new_elements;
	capacity += 10;
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

template<class T>
inline data_row<T>* SparseMatrix<T>::Fast_Transpose()
{
	data_row<T>* Transpose = new data_row<T>[terms];
	int* rowSize = new int[col_num];
	int* rowStart = new int[col_num];
	
	memset(rowSize, 0, col_num*sizeof(int));//initialize
	for (int i = 0; i < terms; i++)
		rowSize[elements[i].col]++;

	rowStart[0] = 0;
	for (int i = 1; i < col_num; i++) {
		rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	}

	int j;
	for (int i = 0; i < terms; i++) {
		j = elements[i].col;
		Transpose[rowStart[j]].col = elements[i].row;
		Transpose[rowStart[j]].row = elements[i].col;
		Transpose[rowStart[j]].value = elements[i].value;
		rowStart[j]++;
	}

	delete[] rowSize;
	delete[] rowStart;

	return Transpose;
}

template<class T>
inline SparseMatrix<T>* SparseMatrix<T>::Multiply(SparseMatrix* b)
{	

	if (this->col_num != b->row_num) {
		cout << "Matrix size are imcompatible!\n";
		return nullptr;
	}

	SparseMatrix<T>* d = new SparseMatrix<T>(this->row_num,b->col_num);
	int curAindex, curBindex, curArow, curBcol,Astart,Bstart;
	data_row<T>* bT = b->Fast_Transpose();
	curAindex = 0; curArow = this->elements[0].row;
	Astart = 0;
	int product = 0;

	while (curAindex < terms) {
		curBindex = 0;
		curBcol = bT[curBindex].row;


		while (curBindex < b->terms) {
			if (this->elements[curAindex].row != curArow) {
				if(product!=0)
					d->Insert(curArow, curBcol, product);
				product = 0;
				curAindex = Astart;
				while (bT[curBindex].row == curBcol)
					curBindex++;
				curBcol = bT[curBindex].row;
			}
			else if (bT[curBindex].row != curBcol) {
				if(product!=0)
					d->Insert(curArow, curBcol, product);
				product = 0;
				curAindex = Astart;
				curBcol = bT[curBindex].row;
			}
			else {
				if (this->elements[curAindex].col < bT[curBindex].col)
					curAindex++;
				else if (this->elements[curAindex].col > bT[curBindex].col)
					curBindex++;
				else {
					product += (this->elements[curAindex].value * bT[curBindex].value);
					curAindex++;
					curBindex++;
				}
			}
		}

		while (this->elements[curAindex].row == curArow)
			curAindex++;
		Astart = curAindex;
		curArow = this->elements[curAindex].row;


	}

	return d;
}