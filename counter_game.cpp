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
	int bitshift;

	if (input == 1) {
		user = "Louise";
	}
	else {

		while (input != 1) {		

			if (!((input) && (input & (input - 1))) == 0) {

				// Step 1: Check the number is not a power of 2.
				// Find the previous power of 2
				bitshift = -1;

				while (input)
				{
					input >>= 1;
					bitshift++;
				}

				input = ((unsigned long long int)1) << bitshift;

				//Step 2 : If input is power of 2, divide by half.
				input = input >> 1;

				cout << "The new input number is" << input << endl;

				if (user == "Louise") {
					user = "Richard";
				}
				else {
					user = "Louise";
				}

			}
			else {
				// Step 1: Check the number is power of 2.
				//Step 2 : If input is power of 2, divide the input by half.
				input = input >> 1;

				cout << "The new input number is" << input << endl;

				if (user == "Louise") {
					user = "Richard";
				}
				else {
					user = "Louise";
				}
			}
		}

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

