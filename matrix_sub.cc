/****************************************************************************************
CSCI 340 - Assignment 02 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
TA: Saiteja Alubelli
Date Due: September 23, 2020

Purpose: The following is the implentation file for a matrix.cc. The general purpose
 of the program is to  store the result of the multiplication of two matrices into a 
 third matrix. The data for the matrices is taken from "matrix01.dat" and "matrix02.dat"
 which are defined in the header file "matrix.h". That data is stored into 2-Dimension
 -al vectors. There is a function that opens the files, a function that stores file dat
 -a, a function that prints matrix data, and function that performs the matrix multipl
 -ication.

***************************************************************************************/

// Preprocessing directives
// Input and output stream, format spacing, file stream, vector container, and out
// header file which contains our global variables and function definitions

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "matrix.h"

using namespace std;

// opens files that were defined in "matrix.h"
// if the files do not open, an error message is printed to the console and the program
// is exited

void open_files(ifstream &is1, ifstream &is2)
{
	is1.open(FILE1);
	if(!is1)
	{
		cerr<< "Unable to open file matrix01.dat";
		exit(1);
	};
	is2.open(FILE2);
	if(!is2)
	{
		cerr<< "Unable to open file matrix02.dat";
		exit(1);
	}
}

// reads data from file stream into the vector passed as a parameter
// The amount of rows in the matrix is the size allotted from matrix.cc
// That value was initially read and stored into the vector in matrix.cc
// We set up a double for loop to access store values into the vector
// Everytime we call the insertion stream, another value is read 
// from the file, we then store that value into the vector

void read_data(ifstream &is, vector<vector<int>> &m)
{
	int rows = m.size();
	int cols = m[0].size();
	int val;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			is >> val;
			m[i][j]=val;
		}	
	}
}

// prints the matrix
// prints newlines between data and allows at least 8 spaces for each 
// value
// for loop to print dashes for formatting
// double for loop to read matrix values

void print_data(const vector<vector<int>> &m)
{
	int rows = m.size();
	int cols = m[0].size();
	cout << rows << " "<< "x"<< " " << cols << endl;
	for(int i=0;i<70;i++)
	{
		cout<< '-';
	}
	cout<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout <<setw(8)<< m[i][j];
		}
		cout <<endl;
	}
}

// multiples matrix A into Matrix B, stored into Matrix C
// A and B are read only
// we access the index of matrix C as we have previous matrices
// the innermost loop iterates for the amount of colunns in A
// the algorithm multiplies row 'k' of A and column 'k' of B while
// once those values have all added into C, the iteration continues 
// for each proceeding column and row 
// whatever is stored before calculation in C is set to zero 

void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C)
{
	int rows=C.size();
	int cols = C[0].size();
	int ksize= A[0].size();
	int val1,val2;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			C[i][j]=0;
			for(int k=0;k<ksize; k++)
			{
				val1=A[i][k];
				val2=B[k][j];
				C[i][j]=C[i][j]+(val1*val2);
			}
		}
	}
}

