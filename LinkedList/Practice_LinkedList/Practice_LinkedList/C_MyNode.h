#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class C_MyNode
{
public:
	T m_Data;
	C_MyNode<T>* m_Next;
	C_MyNode();
	~C_MyNode();
	
};

template <class T>
inline C_MyNode<T>::C_MyNode():m_Data(),m_Next(NULL){}

template <class T>
inline C_MyNode<T>::~C_MyNode() {}

