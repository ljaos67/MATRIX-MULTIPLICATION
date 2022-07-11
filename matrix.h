/**************************************************************************************************
CSCI 340 - Assignment 02 - Fall 2020

Programmer: Leonart Jaos
Z-ID: z1911688
Section: 0002
TA: Saiteja Alubelli
Date Due: 9/23/2020

Purpose: Purpose listed in matrix_sub.cc. The following file is the header file for function
 definitions, global variables such as the definitons for the file locations "matrix01.dat" and
 "matrix02.dat". 

***************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

#ifndef H_PROG2
#define H_PROG2

// data files
#define FILE1 "./matrix01.dat"
#define FILE2 "./matrix02.dat"

#define ITEM_W 8 // no of spaces for each printed number

// to open two data files
void open_files(ifstream &is1, ifstream &is2);

// to read contents of two data files
void read_data(ifstream &is, vector<vector<int>> &m);

// to print contents of all matrices
void print_data(const vector<vector<int>> &m);

// to generate a matrix by multiplying two input matrices
void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C);

#endif
