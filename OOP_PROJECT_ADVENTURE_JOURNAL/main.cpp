#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Registration.h"
#include "LogIn.h"

int main() {
	int endProgram = 0;

	char options[50];
	
	while (endProgram == 0) {
		cout << "Choose option: " << endl;
		cout << "Register" << endl;
		cout << "Sign in" << endl;
		cin >> options;
		if (strcmp(options, "Register")== 0)
		{
			regUsername();
			if (getRecordTimes() == 3)
				continue;
			regPassword();
			regEmail();
			cout << "\nYou are successfully registered!";
			closeFile();
		}
		else if (strcmp(options, "Sign in") == 0) {
			logIn();
		}
		else {
			endProgram = 1;
		}
	}
	return 0;
}
