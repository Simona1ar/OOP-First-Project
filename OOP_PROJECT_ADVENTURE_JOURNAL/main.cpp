#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "User.h"

int main() {
	int endProgram = 0;
	fstream iofile;


	char options[50];
	
	while (endProgram == 0) {
		cout << "Choose option: " << endl;
		cout << "Register" << endl;
		cout << "Sign in" << endl;
		cin >> options;
		if (strcmp(options, "Register")== 0)
		{

		}
		else if (strcmp(options, "Sign in") == 0) {

		}
		else {
			endProgram = 1;
		}
	}
	return 0;
}
