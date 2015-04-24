// matrix_number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int short_count = 0;
	int iRow, iCol, iMax_Index, iShort_Count = 0;
	double value = 0, dCount = 0;
	double dMax_Rows = 0;
	vector<double> matrix;
	vector<int> temp;

	cout << "enter the input"<<endl;
	// Read the input
	cin >> iRow >> iCol;

	// Validate the input
	assert((iCol >= 1) && (iCol <= 5));
	assert((iRow >= 1) && (iRow <= ( 2 * pow(10, 9)) ) );

	// Calculate the Max Index

	iMax_Index = ((iRow - 1) * 5 + iCol ) - 1;
	dMax_Rows = iRow * 5;

	// Problem solution

	// Loop till maximum index to find the value
	while (dCount < dMax_Rows) {

		// Fill the odd numbers first
		while (iShort_Count < 5) {
			matrix.push_back(dCount);
			dCount++;
			temp.push_back(dCount);
			dCount++;
			iShort_Count++;
		}

		iShort_Count = 0;

		// Fill the even numbers

		while (iShort_Count < 5) {

			matrix.push_back(temp[iShort_Count]);			
			iShort_Count++;
		}
		temp.clear();
		iShort_Count = 0;

	}

	// Fetch the answer

	value = matrix[iMax_Index];

	cout << value;
	cin.get();
	return 0;
}

