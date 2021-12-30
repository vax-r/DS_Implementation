#pragma once

#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
class C_MyStack
{
private:
	T* m_Element;
	int m_StackSize;
	int m_End;
public:
	C_MyStack();
	~C_MyStack();
	bool SetSize(int);
	bool Push(T &);
	bool Pop(T &);
	bool Insert(int ,T);
	bool Delete(int ,T &);
};

template <class T>
inline C_MyStack<T>::C_MyStack():m_Element(0),m_StackSize(0),m_End(NULL){}

template <class T>
inline C_MyStack<T>::~C_MyStack() {
	delete[]this->m_Element;
}

template <class T>
inline bool C_MyStack<T>::SetSize(int size) {
	if (this->m_Element)
		delete[]m_Element;
	m_Element = new T[size];

	if (!this->m_Element)
		return false;

	this->m_StackSize = size;
	return true;
}

template <class T>
inline bool C_MyStack<T>::Push(T &num) {

	if (this->m_End == this->m_StackSize) {
		cout << "Stack is full." << endl;
		return false;
	}

	this->m_Element[this->m_End++] = num;
	cout << "Successfully push " << num << " in Stack." << endl;
	return true;
}

template <class T>
inline bool C_MyStack<T>::Pop(T& num) {
	if (this->m_End == 0) {
		cout << "Stack is empty." << endl;
		return false;
	}

	num = this->m_Element[--this->m_End];
	cout << "Successfully pop " << num << " out of Stack." << endl;
	return true;
}

template <class T>
inline bool C_MyStack<T>::Insert(int pos, T val) {
	if (pos < 0 || pos >= this->m_StackSize) {
		cout << "invalid index number." << endl;
		return false;
	}

	if (pos >= this->m_End) {
		Push(val);
		return true;
	}

	if (pos >= 0 && pos < this->m_End) {
		
		for (int i = m_End; i >= pos; i--) {
			if (i == pos)
				m_Element[i] = val;
			else
				this->m_Element[i] = this->m_Element[i - 1];
		}
		this->m_End++;
		cout << "Successfully insert " << val << " into position " << pos << "." << endl;
		return true;
	}

}

template <class T>
inline bool C_MyStack<T>::Delete(int pos, T& val) {
	if (pos < 0 || pos >= this->m_End) {
		cout << "invalid index number." << endl;
		return false;
	}

	if (pos == this->m_End - 1) {
		Pop(val);
		return true;
	}

	if (pos >= 0 && pos < this->m_End) {
		val = this->m_Element[pos];
		for (int i = pos; i < this->m_End&&i+1!=this->m_End; i++) {
			this->m_Element[i] = this->m_Element[i + 1];
		}
		this->m_End--;
		cout << "Successfully delete " << val << " from Stack" << endl;
		return true;
	}

}


