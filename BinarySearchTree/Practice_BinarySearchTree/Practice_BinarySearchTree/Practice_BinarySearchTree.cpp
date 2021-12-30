// Practice_BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	C_BinarySearchTree<int> Tree1;
	int val;
	for (int i = 0; i < 8; i++) {
		cin >> val;
		Tree1.Insert(val);
	}
	Tree1.Show();
	

	int delete_val;
	cin >> delete_val;
	while (delete_val != 100) {
		Tree1.Delete(delete_val);
		Tree1.Show();
		
		cin >> delete_val;
	}





	return 0;
}


