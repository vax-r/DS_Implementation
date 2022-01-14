// Sparse_Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SparseMatrix.h"



int main()
{   
    int row_size = 6, col_size = 6;
    SparseMatrix<int> M1(row_size,col_size);
    SparseMatrix<int> M2(row_size, col_size);

    int row[8] = { 0,0,0,1,1,2,4,5 }, col[8] = { 0,3,5,1,2,3,0,2 }, val[8] = {15,22,-15,11,3,-6,91,28};
    
    for (int i = 0; i < 8; i++) {
        M1.Insert(row[i], col[i], val[i]);
        M2.Insert(row[i], col[i], val[i]);
    }
    cout << "Before Transpose...\n";
    M1.ShowAll();
    
    cout << "---\n";
    cout << "After Transpose...\n";
    M1.ShowAll(M1.Transpose());
    
    cout << "---\n";
    cout << "After Fast Transpose...\n";
    M1.ShowAll(M1.Fast_Transpose());

    SparseMatrix<int>* Product;
    cout << "---\n";
    cout << "Multiply...\n";
    Product=M1.Multiply(&M2);
    if (Product != nullptr)
        Product->ShowAll();
    else
        cout << "Fail to multiply\n";

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
