#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "User.h"

int main() {
	cout << "Choose option: " << endl;
	cout << "Register" << endl;
	cout << "Sign in" << endl;
	ofstream writeMyFile;
	ifstream readMyFile;


	char options[50];
	bool a = true;
	do
	{
		cin >> options;
		if (strcmp(options, "Register") == 0) {
			cout << "\nCreate username: ";
			cin.ignore();
		}
		else if (strcmp(options, "Sign in") == 0) {
			a = false;
		}
		else {
			cout << "Invalid option." << endl;
		}
	} while (a);
	return 0;
}
