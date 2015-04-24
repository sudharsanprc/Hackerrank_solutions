// previous2_power.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

string counter_game(unsigned long long int input){
	string user;

	unsigned long long int iteration = 0;

	if (input == 1) {
		user = "Louise";
	}
	else {

		while (input != 1) {

			iteration++;
		//	cout << "While loop";

			if (!((input) && (input & (input - 1))) == 0) {
				
				// Step 1: Check the number is not a power of 2.
				// Find the previous power of 2
				
				input |= input >> 1;
				input |= input >> 2;
				input |= input >> 4;
				input |= input >> 8;
				input |= input >> 16;
				input |= input >> 32;
				input = input + 1;

				//Step 2 : If input is power of 2, divide by half.
				input = input >> 1;		
			}
			else {		
				// Step 1: Check the number is power of 2.
				//Step 2 : If input is power of 2, divide the input by half.
				input = input >> 1;
			} 
		} 

		if (iteration % 2 == 0)
			user = "Louise";
		else
			user = "Richard";

	} // input number is not 1

	return user;
}

int main()
{
	int test_case_count = 0, count = 0;
	vector<unsigned long long int> numbers;
	unsigned long long int input;
	string winner = "";	
	cin >> test_case_count;
	assert((test_case_count >= 1) && (test_case_count <= 10));	

	for (int count = 0; count < test_case_count; count++) {
		cin >> input;
		assert((input >= 1) && (input <= (pow(2, 64) - 1)));
		numbers.push_back(input);
	}

	for (count = 0; count < test_case_count; count++) {
		winner = counter_game(numbers[count]);
		cout << winner << endl;
	}

	cin.clear();
	cin.get();
	cin >> test_case_count;
	return 0;
}

