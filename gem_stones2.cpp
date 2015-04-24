#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    /*Declarations*/

    int irocks_count =0;
    int iloop_count = 0;
    int irock_comp_len = 0;
    int itemp_size = 0;
    string strrock_elements = "";
    int element_index = 0;

    std::vector<string> rock_elements;

    /*Get the Rock Count from User*/
  //  cout <<"Enter the no of Rocks"<<endl;
    cin>>irocks_count;

    /*validate the element count*/
    if (irocks_count >= 1 && irocks_count <= 100) {
    	/*comment the below line*/
   //     cout<<"Valid input count"<<endl;
	} else {
	//	cout<<"******Invalid input count*****"<<endl;
		return 0;
	}

	/*Get the Rock elements from the user*/
	while (iloop_count < irocks_count) {
		//getline(std::cin,strrock_elements);
		cin>>strrock_elements;
		rock_elements.push_back(strrock_elements);
		itemp_size = strrock_elements.length();
		/*Validate the element name*/
		for(int iterator = 0; iterator != itemp_size; iterator++) {

			if(!isalpha(strrock_elements.at(iterator))) {
				// Invalid input
		//		cout<<"Invalid input element name.Exit.Re-Run"<<endl;
				return 0;
			}
		}
		if (iloop_count == 0) {
			irock_comp_len = itemp_size;
			element_index = iloop_count;
		} else {
			if (irock_comp_len > itemp_size) {
				irock_comp_len = itemp_size;
				element_index = iloop_count;
			}
		}
		iloop_count++;
	}
		/*working code*/

        int bavailcount = 0;
        int iglobalcount = 0;

		string master_element = rock_elements[element_index];

		std::sort(master_element.begin(), master_element.end());

		master_element.erase(std::unique(master_element.begin(), master_element.end()), master_element.end());

		for(int i =0; i< (int) master_element.length();i++) {

			char search_element = master_element.at(i);
			bavailcount = 0;

			for(int j = 0; j<(int)rock_elements.size();j++) {

				string search_rock = rock_elements[j];

				std::size_t found = search_rock.find_first_of(search_element);

					if (found != std::string::npos) {
						bavailcount++;
					}
			}


			if (bavailcount == (int)rock_elements.size()) {

				iglobalcount++;
			}
		}
          cout<<iglobalcount<<endl;
          return 0;
}
