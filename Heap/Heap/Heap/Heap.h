#pragma once

#include <iostream>
#include <cstring>
using namespace std;

enum class Heap_type {
	Max,Min
};

template <class T>
class Heap {
private:
	T* elements;
	unsigned int Capacity;
	unsigned int num_elements;
	Heap_type hp;
	T* sorted_elements;
	
public:
	Heap(T* e, unsigned int size,Heap_type type);
	~Heap();
	void Init_Heap();//driver to build a heap
	void Heaplify(unsigned int index);//workhorse
	void SWAP(T& a, T& b);
	bool InsertNode(T new_element);
	void Expand_Capacity();
	void ShowHeap();
	void Pop();
	void HeapSort();
};

template<class T>
inline Heap<T>::Heap(T* e, unsigned int size,Heap_type type)
{
	if (size % 10 != 0)
		Capacity = size + (size - size % 10);
	else
		Capacity = size;
	this->num_elements = size;
	this->elements = e;
	this->hp = type;
	Init_Heap();
}

template<class T>
inline Heap<T>::~Heap()
{
	delete[] this->elements;
}

template<class T>
inline void Heap<T>::Init_Heap()
{
	for (unsigned int i = this->num_elements / 2; i > 0; i--) {
		this->Heaplify(i);
	}
	this->Heaplify(0);
}

template <class T>
inline void Heap<T>::SWAP(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
inline bool Heap<T>::InsertNode(T new_element)
{
	unsigned int origin_Cap = this->Capacity;

	if (this->num_elements + 1 >= Capacity)
	{
		Expand_Capacity();
		if (this->Capacity <= origin_Cap)
			return false;
	}
	
	
	this->elements[this->num_elements] = new_element;
	this->num_elements++;
	unsigned int i,parent;
	
	for (i = this->num_elements - 1; i > 0; i = (i + 1) / 2 - 1) {
		parent = (i + 1) / 2 - 1;
		if (this->elements[i] <= this->elements[parent])
			return true;
		else
			SWAP(this->elements[i], this->elements[parent]);
	}
	

}

template<class T>
inline void Heap<T>::Expand_Capacity()
{
	T* new_list = new T[Capacity + 10];
	memcpy(new_list, this->elements, sizeof(T) * this->Capacity);
	delete[] this->elements;
	this->elements = new_list;
	Capacity += 10;
}

template<class T>
inline void Heap<T>::ShowHeap()
{
	for (unsigned int i = 0; i < this->num_elements; i++) {
		cout << this->elements[i] << " ";
	}
	cout << endl;
}

template<class T>
inline void Heap<T>::Pop()
{
	if(this->num_elements==0)
	{
		cout << "Heap is empty!" << endl;
		return;
	}

	SWAP(this->elements[0], this->elements[num_elements - 1]);

	num_elements--;
	Heaplify(0);

}

template<class T>
inline void Heap<T>::HeapSort()
{	
	int size = this->num_elements;
	this->sorted_elements = new T[size];

	for (unsigned int i = 0; i < size; i++) {
		if (this->num_elements == 0)
			break;
		SWAP(this->elements[0], this->elements[num_elements - 1]);
		num_elements--;
		Heaplify(0);
	}

	this->num_elements = size;
}


template<class T>
inline void Heap<T>::Heaplify(unsigned int index)
{
	unsigned int child=(index+1)*2-1;
	bool done = false;
	while (!done && child < this->num_elements) {
		switch (this->hp) {
		case Heap_type::Max:
			if (child+1<this->num_elements && this->elements[child] < this->elements[child + 1])
				child++;

			if (this->elements[index] >= this->elements[child]) {
				done = true;
				break;
			}
			SWAP(this->elements[index], this->elements[child]);
			index = child;
			child = (index+1) * 2-1;
			break;
		case Heap_type::Min:
			if (child+1<this->num_elements && this->elements[child] > this->elements[child + 1])
				child++;
			if (this->elements[index] <= this->elements[child]) {
				done = true;
				break;
			}
			SWAP(this->elements[index], this->elements[child]);
			index = child;
			child = (index+1) * 2-1;
			break;
		}
	}
}
