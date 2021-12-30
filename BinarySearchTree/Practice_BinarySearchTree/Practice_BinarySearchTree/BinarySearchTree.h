#pragma once

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

template <class T>
class C_Node {
public:
	T m_data;
	int node_index;
	bool is_empty;
	C_Node<T>* m_Left;
	C_Node<T>* m_Right;
	C_Node() :m_data(),node_index(0) ,is_empty(true), m_Left(NULL), m_Right(NULL) {};
	~C_Node() {};
};

template <class T>
class C_BinarySearchTree {
private:
	C_Node<T>* m_Root;
	vector<T> level_order_vec;
public:
	C_BinarySearchTree();
	~C_BinarySearchTree();
	void DeleteTree(C_Node<T>*);
	void Inorder(C_Node<T>*);
	void Preorder(C_Node<T>*);
	void Posorder(C_Node<T>*);
	bool Insert(T);
	C_Node<T>* GetEmptyNode(C_Node<T>*,T);
	bool SetNode(C_Node<T>*,T);
	bool Delete(T);
	bool DeleteNode(C_Node<T>*);
	void Swap(T& a, T& b);
	C_Node<T>* GetDeleteNode(C_Node<T>*, T);
	C_Node<T>* GetMaxInLeftTree(C_Node<T>*);
	void Show();
	void ShowByShell();
	int GetTreeHeight(C_Node<T>*);
};

template <class T>
void C_BinarySearchTree<T>::Show() {
	cout << "Inorder Traversal:\n";
	Inorder(this->m_Root); cout << endl;
	cout << "Preorder Traversal:\n";
	Preorder(this->m_Root); cout << endl;
	cout << "Posorder Traversal:\n";
	Posorder(this->m_Root); cout << endl;
	cout << "Level-order Traversal:\n";
	ShowByShell();
	cout << "height: " << GetTreeHeight(this->m_Root) << endl << endl;
}

template <class T>
inline C_BinarySearchTree<T>::C_BinarySearchTree() {
	m_Root = new C_Node<T>;
	m_Root->node_index = 1;
	level_order_vec.assign(100, -1);
}

template <class T>
inline C_BinarySearchTree<T>::~C_BinarySearchTree() {
	DeleteTree(this->m_Root);
}

template <class T>
inline void C_BinarySearchTree<T>::DeleteTree(C_Node<T>* root) {
	if (root->m_Left)
		DeleteTree(root->m_Left);
	if (root->m_Right)
		DeleteTree(root->m_Right);
	delete root;
}

template <class T>
inline void C_BinarySearchTree<T>::Inorder(C_Node<T>* root) {
	if (root->is_empty == true || root == NULL) {
		return;
	}
	Inorder(root->m_Left);
	cout << root->m_data << " ";
	Inorder(root->m_Right);

}

template <class T>
inline void C_BinarySearchTree<T>::Preorder(C_Node<T>* root) {
	if (root->is_empty == true || root == NULL) {
		return;
	}
	cout << root->m_data << " ";
	Preorder(root->m_Left);
	Preorder(root->m_Right);
}

template <class T>
inline void C_BinarySearchTree<T>::Posorder(C_Node<T>* root) {
	if (root->is_empty == true || root == NULL) {
		return;
	}
	Posorder(root->m_Left);
	Posorder(root->m_Right);
	cout << root->m_data << " ";
}

template <class T>
inline bool C_BinarySearchTree<T>::Insert(T val) {
	C_Node<T>* new_Node=GetEmptyNode(this->m_Root, val);
	if (!new_Node)
		return false;
	return SetNode(new_Node, val);
}

template <class T>
inline C_Node<T>* C_BinarySearchTree<T>::GetEmptyNode(C_Node<T>* root,T val) {
	if (!root)
		return NULL;
	if (root->is_empty)
		return root;
	if (root->is_empty == false && root->m_data == val) {
		cout << "Repeated value: " << val << endl;
		return NULL;
	}

	if (val > root->m_data)
		return GetEmptyNode(root->m_Right,val);
	else if (val < root->m_data)
		return GetEmptyNode(root->m_Left,val);

}

template <class T>
inline bool C_BinarySearchTree<T>::SetNode(C_Node<T>* node, T val) {
	if (!node)
		return false;
	node->m_Left = new C_Node<T>;
	node->m_Left->node_index = node->node_index * 2;
	if (!node->m_Left)
		return false;
	node->m_Right = new C_Node<T>;
	node->m_Right->node_index = node->node_index * 2 + 1;
	if (!node->m_Right) {
		delete node->m_Left;
		return false;
	}
	node->m_data = val;
	level_order_vec[node->node_index] = val;
	node->is_empty = false;
	return true;
}



template <class T>
inline bool C_BinarySearchTree<T>::Delete(T val) {
	C_Node<T>* d_Node = GetDeleteNode(this->m_Root, val);
	if (!d_Node) {
		cout << "there's no such Node exist in this tree.\n";
		return false;
	}

	C_Node<T>* replace_Node = GetMaxInLeftTree(d_Node);
	Swap(replace_Node->m_data, d_Node->m_data);
	Swap(level_order_vec[replace_Node->node_index], level_order_vec[d_Node->node_index]);
	return DeleteNode(replace_Node);
	
}

template <class T>
inline bool C_BinarySearchTree<T>::DeleteNode(C_Node<T>* node) {
	if (!node)
		return false;
	node->is_empty = true;
	level_order_vec[node->node_index] = -1;
	if (node->m_Left != NULL) {
		delete node->m_Left;
		node->m_Left = NULL;
	}
	if (node->m_Right != NULL) {
		delete node->m_Right;
		node->m_Right = NULL;
	}
	return true;
}

template <class T>
inline void C_BinarySearchTree<T>::Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
inline C_Node<T>* C_BinarySearchTree<T>::GetMaxInLeftTree(C_Node<T>* root) {
	if (root->m_Left->is_empty == true && root->m_Right->is_empty == true)
		return root;
	if (root->m_Left->is_empty == true && root->m_Right->is_empty == false) {
		C_Node<T>* now = root->m_Right;
		while (now->m_Left->is_empty!=true)
			now = now->m_Left;
		return now;
	}
	else if (root->m_Left->is_empty == false) {
		C_Node<T>* now = root->m_Left;
		while (now->m_Right->is_empty != true)
			now = now->m_Right;
		return now;
	}
}

template <class T>
inline C_Node<T>* C_BinarySearchTree<T>::GetDeleteNode(C_Node<T>* root, T val) {
	if (!root)
		return NULL;
	else if (root->is_empty == true)
		return NULL;

	if (root->m_data == val)
		return root;

	if (val > root->m_data)
		return GetDeleteNode(root->m_Right, val);
	else if (val < root->m_data)
		return GetDeleteNode(root->m_Left, val);
}


template <class T>
inline int C_BinarySearchTree<T>::GetTreeHeight(C_Node<T>* root) {
	if (root->is_empty)
		return 0;
	else if (GetTreeHeight(root->m_Left) > GetTreeHeight(root->m_Right)) {
		return GetTreeHeight(root->m_Left) + 1;
	}
	else if (GetTreeHeight(root->m_Left) < GetTreeHeight(root->m_Right)) {
		return GetTreeHeight(root->m_Right) + 1;
	}
	else if (GetTreeHeight(root->m_Left) == GetTreeHeight(root->m_Right)) {
		return GetTreeHeight(root->m_Left) + 1;
	}
}

template <class T>
inline void C_BinarySearchTree<T>::ShowByShell() {
	
	for (int i = 0; i < 100; i++) {
		if (level_order_vec[i] != -1) {
			cout << level_order_vec[i] << " ";
		}
	}
	cout << endl;
}
