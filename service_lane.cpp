//============================================================================
// Name        : service_lane.cpp
// Author      : Sudharsan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

int main() {

	long service_lanes;
	int test_case_count;


	vector<short int> lane_width;

	cout << "Enter the service Lanes & test case count" << endl;

	cin>>service_lanes>>test_case_count;

	assert((service_lanes>=2) && (service_lanes<=pow(10,5)));
	assert((test_case_count>=1) && (test_case_count<= pow(10,3)));

	string line;
	std::getline(std::cin,line);
	std::istringstream this_line(line);
	std::istream_iterator<int> begin(this_line), end;
	std::vector<int> values(begin, end);

	return 0;
}
