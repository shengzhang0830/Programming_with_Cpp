/***********************************************************************************************************************
** hw8.cpp
** Fill two matrices from a flie or using random numbers; Output two matrices; Compute their sums; Output the results.
** Sheng Zhang
** SID 604029836
***********************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


// Write the function that fills a matrix with random values
void fill_random(int matrixA[10][10], int row_size, int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			matrixA[i][j] = rand() % 21 - 10;
		}
	}
}

// Write the function that fills a matrix from a file
void fill_from_file(int matrixA[10][10], int row_size, int col_size, ifstream &fin)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			fin >> matrixA[i][j];
		}
	}
}

// Write the function that adds up two matrices together to a new matrix called matrix_sum
void add_matrices(int matrixA[10][10], int matrixB[10][10], int matrix_sum[10][10], int row_size, int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			matrix_sum[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
}

// Write the function that outputs a matrix to the console
void output_to_console(int matrixA[10][10], int row_size, int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			cout << setw(5) << matrixA[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// Write the function that outputs a matrix to a file
void output_to_file(int matrixA[10][10], int row_size, int col_size, ofstream &fout)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			fout << setw(5) << matrixA[i][j];
		}
		fout << endl;
	}
	fout << endl;
}


int main()
{
	// Declare variables and objects to be used
	ifstream fin;
	ofstream fout;
	int matrix1[10][10], matrix2[10][10], matrix_sum[10][10];
	int row_size, col_size;
	string method_fill, method_output, file_matrix_fill, file_matrix1_output, file_matrix2_output, file_results;

	// Ask for the dimensions of the matrices
	cout << "What is the number of rows of your matrices? ";
	cin >> row_size;
	while (row_size > 10 || row_size < 0)
	{
		cout << "Illegal entry, please enter again. What is the number of rows of your matrices? ";
		cin >> row_size;
	}
	cout << "What is the number of columns of your matrices? ";
	cin >> col_size;
	while (col_size > 10 || col_size < 1)
	{
		cout << "Illegal entry, please enter again. What is the number of columns of your matrices? ";
		cin >> col_size;
	}

	// Ask for the method to fill the matrices
	cout << "Do you want to fill the matrices with a file or with random values? If with a file, enter \"F\", if with random numbers, enter \"R\". ";
	cin >> method_fill;

	if (method_fill == "F")
	{
		// Ask for the file name if the user wants to input the matrices from a file
		cout << "Enter the file name to read for the matrices: ";
		cin >> file_matrix_fill;
		fin.open(file_matrix_fill.c_str());
		// Fill the matrices with the file the user indicated
		fill_from_file(matrix1, row_size, col_size, fin);
		fill_from_file(matrix2, row_size, col_size, fin);
		fin.close();
	}
	else if (method_fill == "R")
	{
		// Fill the matrices with random values
		fill_random(matrix1, row_size, col_size);
		fill_random(matrix2, row_size, col_size);
	}
	
	// Ask for the output method for the matrices
	cout << "Do you want to output the matrices to a console or a file? " << endl << "Enter \"C\" for console or \"F\" for file.  ";
	cin >> method_output;
	if (method_output == "C")
	{
		// Output the matrices to the console
		output_to_console(matrix1, row_size, col_size);
		output_to_console(matrix2, row_size, col_size);
	}
	else if (method_output == "F")
	{
		// Output the matrices to files
		cout << "What is the file name that you want matrix 1 to be outputed to? ";
		cin >> file_matrix1_output;
		fout.open(file_matrix1_output.c_str());
		output_to_file(matrix1, row_size, col_size, fout);
		fout.close();
		cout << "What is the file name that you want matrix 2 to be outputed to? ";
		cin >> file_matrix2_output;
		fout.open(file_matrix2_output.c_str());
		output_to_file(matrix2, row_size, col_size, fout);
		fout.close();
	}

	// Add matrix 1 and matrix 2
	add_matrices(matrix1, matrix2, matrix_sum, row_size, col_size);

	// Output the results
	if (method_output == "C")
	{
		// Output the results to the console
		cout << "The sum of the matrices is as follows: " << endl;
		output_to_console(matrix_sum, row_size, col_size);
	}
	else if (method_output == "F")
	{
		// Output the results to a file
		cout << "What is the file name that you want matrix sum to be outputed to? ";
		cin >> file_results;
		fout.open(file_results.c_str());
		output_to_file(matrix_sum, row_size, col_size, fout);
		fout.close();
	}

	return 0;
}
