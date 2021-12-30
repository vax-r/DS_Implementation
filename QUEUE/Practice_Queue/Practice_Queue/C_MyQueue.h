#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class C_MyQueue
{
private:
	unsigned int m_Size;
	unsigned int m_Bottom;
	unsigned int m_Top;
	T* m_Element;
public:
	C_MyQueue();
	~C_MyQueue();
	void SetSize(int size);
	bool Push(T val);
	bool Pop(T& val);
	
	void ShowQueue();

};

template<class T>
inline C_MyQueue<T>::C_MyQueue() :m_Size(5), m_Bottom(0), m_Top(0) {
	m_Element = new T[m_Size];
}

template<class T>
inline C_MyQueue<T>::~C_MyQueue() {
	delete[]m_Element;
}

template <class T>
inline void C_MyQueue<T>::SetSize(int size) {
	if (m_Element)
		delete[]m_Element;
	m_Size = (unsigned int)size;
	m_Element = new T[m_Size];
}

template <class T>
inline bool C_MyQueue<T>::Push(T val) {
	if (m_Top >= m_Size) {
		cout << "Queue is full." << endl;
		return false;
	}

	m_Element[m_Top++] = val;
	return true;

}

template <class T>
inline bool C_MyQueue<T>::Pop(T& val) {
	if (m_Top == m_Bottom) {
		cout << "Queue is empty." << endl;
		return false;
	}

	val=m_Element[m_Bottom++];
	return true;
}

template <class T>
inline void C_MyQueue<T>::ShowQueue() {
	int i;
	for (i = 0; i < (int)m_Size; i++) {
		cout << m_Element[i] << endl;
	}
}

