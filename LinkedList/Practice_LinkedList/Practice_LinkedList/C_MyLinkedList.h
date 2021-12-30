#pragma once

#include <iostream>
#include <stdlib.h>
#include "C_MyNode.h"

using namespace std;

template <class T>
class C_MyLinkedList
{
private:
	C_MyNode<T> * m_Head;
public:
	C_MyLinkedList();
	~C_MyLinkedList();
	void Show();
	bool AddBack(T val);
	bool AddFront(T val);
	bool Remove(int pos);
	bool Insert(int pos, T val);
	bool Inverse();
};

template <class T>
C_MyLinkedList<T>::C_MyLinkedList():m_Head(NULL){}

template <class T>
C_MyLinkedList<T>::~C_MyLinkedList() {
	C_MyNode<T> * Now, * Delete;
	
	Delete = this->m_Head;
	Now = this->m_Head->m_Next;
	while (Delete != NULL) {
		delete Delete;
		Delete = Now;
		if(Now!=NULL)
			Now = Now->m_Next;
	}
}

template <class T>
void C_MyLinkedList<T>::Show() {
	C_MyNode<T>* Now;
	Now = this->m_Head;

	while (Now != NULL) {
		cout << Now->m_Data << " ";
		Now = Now->m_Next;
	}
	cout << endl;

}





template <class T>
bool C_MyLinkedList<T>::AddBack(T val) {
	C_MyNode<T>* Current;
	Current = this->m_Head;

	if (Current == NULL) {
		Current = new C_MyNode<T>;
		if (!Current)
			return false;
		Current->m_Data = val;
		Current->m_Next = NULL;
		m_Head = Current;
		return true;
	}
	else {
		while (Current->m_Next != NULL) {
			Current = Current->m_Next;
		}
		C_MyNode<T>* Add = new C_MyNode<T>;
		if (!Add)
			return false;
		Add->m_Data = val;
		Current->m_Next = Add;
		Add->m_Next = NULL;
		return true;
	}

}

template <class T>
bool C_MyLinkedList<T>::AddFront(T val) {
	C_MyNode<T>* Current;
	Current = this->m_Head;
	
	if (Current == NULL) {
		m_Head = new C_MyNode<T>;
		if (!m_Head)
			return false;
		m_Head->m_Data = val;
		m_Head->m_Next = NULL;
		return true;
	}
	else {
		C_MyNode<T>* Add;
		Add = new C_MyNode<T>;
		if (!Add)
			return false;
		Add->m_Data = val;
		Add->m_Next = this->m_Head;
		m_Head = Add;
		return true;
	}

}

template <class T>
bool C_MyLinkedList<T>::Remove(int pos) {

	if (!this->m_Head) {
		cout << "LinkedList is empty." << endl;
		return false;
	}

	C_MyNode<T>* Current = this->m_Head;
	if (!Current)
		return false;

	if (pos == 0) {
		Current = m_Head->m_Next;
		delete m_Head;
		m_Head = Current;
		return true;
	}

	for (int i = 0; i < pos-1; i++) {
		if (Current->m_Next == NULL) {
			cout << "no such element exist." << endl;
			return false;
		}

		Current = Current->m_Next;
	}
	C_MyNode<T>* Delete = Current->m_Next;
	Current->m_Next = Current->m_Next->m_Next;
	delete Delete;
	return true;

}

template <class T>
bool C_MyLinkedList<T>::Insert(int pos, T val) {
	if (!m_Head) {
		m_Head = new C_MyNode<T>;
		m_Head->m_Data = val;
		m_Head->m_Next = NULL;
	}

	if (pos == 0) {
		C_MyNode<T>* Add = new C_MyNode<T>;
		if (!Add)
			return false;
		Add->m_Data = val;
		Add->m_Next = this->m_Head;
		this->m_Head = Add;
		return true;
	}
	
	C_MyNode<T>* Current = this->m_Head;

	for (int i = 0; i < pos - 1; i++) {
		if (Current->m_Next == NULL) {
			break;
		}
		Current = Current->m_Next;
	}

	C_MyNode<T>* Add = new C_MyNode<T>;
	if (!Add)
		return false;
	Add->m_Data = val;
	Add->m_Next = Current->m_Next;
	Current->m_Next = Add;
	return true;

}

template <class T>
bool C_MyLinkedList<T>::Inverse() {
	C_MyNode<T>* pre, * cur, * temp;
	
	if (!m_Head)
		return false;

	pre = m_Head;
	cur = pre->m_Next;
	if (!cur)
		return false;
	temp = cur->m_Next;
	if (!temp) {
		pre->m_Next = NULL;
		cur->m_Next = pre;
		m_Head = cur;
		return true;
	}

	while (1) {
		if(pre==m_Head)
			pre->m_Next = NULL;

		cur->m_Next = pre;
		pre = temp;
		temp = pre->m_Next;
		pre->m_Next = cur;
		if (temp == NULL) {
			m_Head = pre;
			return true;
		}
		cur = temp;
		temp = cur->m_Next;
		if (temp == NULL) {
			cur->m_Next = pre;
			m_Head = cur;
			return true;
		}
	}



}
