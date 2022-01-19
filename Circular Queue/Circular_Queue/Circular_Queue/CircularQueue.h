#pragma once

#include <iostream>
#include <cstring>

using namespace std;


template <class T>
class Circular_Queue {
private:
	unsigned int front;
	unsigned int rear;
	unsigned int capacity;
	T* elements;

public:
	Circular_Queue();
	Circular_Queue(unsigned int& size);
	~Circular_Queue();
	void Push(T element);
	void Pop();
	//T get_Front();
	//T get_Rear();
	bool Empty();
	bool Full();
	void ExpandCapacity();
	void View_All();


};

template <class T>
inline Circular_Queue<T>::Circular_Queue() {
	front = 0; rear = 0;
	capacity = 10;
	elements = new T[capacity];
}

template<class T>
inline Circular_Queue<T>::Circular_Queue(unsigned int& size)
{
	front = 0; rear = 0;
	capacity = size;
	elements = new T[capacity];
}

template<class T>
inline Circular_Queue<T>::~Circular_Queue()
{
	delete[] elements;
}

template<class T>
inline void Circular_Queue<T>::Push(T element)
{
	if (Full()) {
		//cout << "Queue is full!\n";
		//return;
		ExpandCapacity();
	}

	rear = (rear + 1) % capacity;
	elements[rear] = element;
}

template<class T>
inline void Circular_Queue<T>::Pop()
{
	if (Empty()) {
		cout << "Queue is empty!\n";
		return;
	}

	front = (front + 1) % capacity;

}

template <class T>
inline bool Circular_Queue<T>::Empty() {
	if (rear == front)
		return true;
	else
		return false;
}

template <class T>
inline bool Circular_Queue<T>::Full() {
	if ((rear + 1) % capacity == front)
		return true;
	else
		return false;
}

template<class T>
inline void Circular_Queue<T>::ExpandCapacity()
{
	T* new_elements = new T[capacity + 10];
	unsigned int start, end;

	if (front == capacity - 1 || front == 0) {
		start = (front + 1) % capacity;
		memcpy(new_elements + 1, (this->elements) + start, (capacity - 1)*sizeof(T));
		delete[] this->elements;
		this->elements = new_elements;
		front = 0; rear = capacity - 1;
		capacity += 10;
	}
	else {
		start = (front + 1) % capacity;
		memcpy(new_elements + 1, (this->elements) + start, (capacity - start)*sizeof(T));
		memcpy(new_elements + 1 + (capacity - start), (this->elements), (start-1) * sizeof(T));
		delete[] this->elements;
		this->elements = new_elements;
		front = 0; rear = capacity - 1;
		capacity += 10;

	}
}

template <class T>
inline void Circular_Queue<T>::View_All() {
	cout << "front ";
	for (unsigned int i = front + 1; i != rear; i = (i + 1) % capacity) {
		cout << elements[i] << " ";
	}
	cout << elements[rear] << " ";
	cout << "rear";
	cout << endl;
}


