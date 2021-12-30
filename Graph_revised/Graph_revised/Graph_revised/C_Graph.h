#pragma once

#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

template <class T>
struct C_Node {
	unsigned int index;
	C_Node<T>* next;
	C_Node();
	~C_Node();
};

template <class T>
inline C_Node<T>::C_Node() {
	this->index = -1;
	this->next = NULL;
}

template <class T>
inline C_Node<T>::~C_Node() {

}

template <class T>
class UnDiGraph {
private:
	C_Node<T>* head_list;
	unsigned int list_len;
	bool* visited;
	int* predecessor;
public:
	UnDiGraph();
	UnDiGraph(unsigned int ver_num);
	~UnDiGraph();
	void add_edge(unsigned int start_ver, unsigned int end_ver, unsigned int weight);
	C_Node<T>* create_node(unsigned int index);
	C_Node<T>* get_head_list(unsigned int index);
	void Show_adj_list();
	bool visited_reset();
	bool predecessor_reset();
	void DFS(C_Node<T>* root);
	void BFS(C_Node<T>* root);
	void Show_predecessor();
	int ConnectComponent_Num();
};

template <class T>
inline UnDiGraph<T>::UnDiGraph() {
	list_len = (unsigned int)10;
	visited = new bool[list_len];
	predecessor = new int[list_len];
	head_list = new C_Node<T>[list_len];
	for (unsigned int i = 0; i < list_len; i++) {
		visited[i] = false;
		predecessor[i] = -2;
	}
}

template <class T>
inline UnDiGraph<T>::UnDiGraph(unsigned int ver_num) {
	list_len = ver_num;
	head_list = new C_Node<T>[list_len];
	visited = new bool[list_len];
	predecessor = new int[list_len];
	for (unsigned int i = 0; i < ver_num; i++) {
		visited[i] = false;
		predecessor[i] = -2;
	}
}

template <class T>
inline UnDiGraph<T>::~UnDiGraph() {
	C_Node<T> *cur, *next;
	
	for (unsigned int i = 0; i < list_len; i++) {
		cur = (head_list+i);
		cur = cur->next;
		while (cur != NULL) {
			next = cur->next;
			delete cur;
			cur = next;
		}
	}
	delete[] head_list;
	delete[] visited;
	delete[] predecessor;
}

template <class T>
inline void UnDiGraph<T>::add_edge(unsigned int start_ver, unsigned int end_ver, unsigned int weight) {
	if ((head_list+start_ver)->index==-1) {
		(head_list + start_ver)->index = start_ver;
	}
	
	C_Node<T>* cur = (head_list+start_ver);
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = create_node(end_ver);
	

	if ((head_list+end_ver)->index==-1) {
		(head_list + end_ver)->index = end_ver;
	}

	cur = (head_list+end_ver);
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = create_node(start_ver);

}

template <class T>
inline C_Node<T>* UnDiGraph<T>::create_node(unsigned int index) {
	C_Node<T>* new_node=new C_Node<T>;
	new_node->index = index;
	new_node->next = NULL;

	return new_node;
}

template <class T>
inline C_Node<T>* UnDiGraph<T>::get_head_list(unsigned int index) {
	return (head_list + index);
}

template <class T>
inline void UnDiGraph<T>::Show_adj_list() {
	C_Node<T>* cur = NULL;
	for (unsigned int i = 0; i < list_len; i++) {
		cout << "vertice:" << i << ":";
		cur = (head_list+i);

		while (cur != NULL) {
			if (cur->index != i) {
				cout << cur->index << " ";
			}
			cur = cur->next;
		}
		cout << endl;

	}
}

template <class T>
inline bool UnDiGraph<T>::visited_reset() {
	try {
		for (unsigned int i = 0; i < list_len; i++) {
			visited[i] = false;
		}
	}
	catch (exception& e) {
		return false;
	}

	return true;

}

template <class T>
inline bool UnDiGraph<T>::predecessor_reset() {
	try {
		for (unsigned int i = 0; i < list_len; i++) {
			predecessor[i] = -2;
		}
	}
	catch (exception& e) {
		return false;
	}

	return true;
}

template<class T>
inline void UnDiGraph<T>::DFS(C_Node<T>* root)
{
	C_Node<T>* cur = root;
	visited[cur->index] = true;
	cout << cur->index << " ";
	while (cur->next != NULL) {
		cur = cur->next;
		if (visited[cur->index] == false) {
			predecessor[cur->index] = (int)root->index;
			DFS((head_list+(cur->index)));
		}
	}
}

template <class T>
inline void UnDiGraph<T>::BFS(C_Node<T>* root)
{
	queue<C_Node<T>*> q;
	C_Node<T>* cur = root;
	C_Node<T>* p;
	cout << cur->index << " ";
	visited[cur->index] = true;
	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		cur = (head_list+(cur->index));
		p = (head_list + (cur->index));
		while (cur != NULL) {
			if (visited[cur->index] == false) {
				cout << cur->index << " ";
				visited[cur->index] = true;
				predecessor[cur->index] = (int)p->index;
				q.push(cur);
			}

			cur = cur->next;
		}
	}
}

template <class T>
inline void UnDiGraph<T>::Show_predecessor() {
	for (unsigned int i = 0; i < list_len; i++) {
		cout << i << ": " << predecessor[i] << endl;
	}
}

template <class T>
inline int UnDiGraph<T>::ConnectComponent_Num() {
	int sum = 0;
	for (unsigned int i = 0; i < list_len; i++) {
		if (predecessor[i] == -2)
			sum += 1;
	}

	return sum;
}