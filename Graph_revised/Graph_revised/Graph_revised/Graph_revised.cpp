// Graph_revised.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "C_Graph.h"

int main()
{
    unsigned int N = 5;
    UnDiGraph<int> G1(N);

	G1.add_edge(0, 1, 0);
	G1.add_edge(0, 4, 0);
	G1.add_edge(1, 2, 0);
	G1.add_edge(1, 3, 0);
	G1.add_edge(1, 4, 0);
	G1.add_edge(2, 3, 0);
	G1.add_edge(3, 4, 0);

	G1.Show_adj_list();

	unsigned int root_index = 0;

	cout << "DFS traversal:\n";
	G1.DFS(G1.get_head_list(root_index));
	cout << endl;
	cout << "DFS predecessor:\n";
	G1.Show_predecessor();

	if (G1.visited_reset() && G1.predecessor_reset()) {
		cout << "BFS traversal:\n";
		G1.BFS(G1.get_head_list(root_index));
		cout << endl;
		cout << "BFS predecessor:\n";
		G1.Show_predecessor();
	}


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
