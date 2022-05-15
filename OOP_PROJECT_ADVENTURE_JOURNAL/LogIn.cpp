#include "LogIn.h"

ifstream iFileLogIn;
ofstream oFileLogIn("DataBase.txt", ios::app);

MyString usernameLogIn;
MyString passwordLogIn;
User* usersLogIn;


void logIn() {
	char line[32]; //delete[]
	cout << "\nEnter username: ";
	cin >> usernameLogIn;
	
	iFileLogIn.open("DataBase.txt");
	if (iFileLogIn.is_open()) {
		while (iFileLogIn.getline(line, sizeof(line))) {
			if (usernameLogIn.cmpStrWithCharArray(usersLogIn->getUsername().getMyStr()))
			{
				cout << "\nEnter password.";
				int posInFile = iFileLogIn.tellg();
				int nextPos = posInFile + 1;
				iFileLogIn.seekg(nextPos, posInFile);
				iFileLogIn.getline(line, sizeof(line));
				if (passwordLogIn.cmpStrWithCharArray(usersLogIn->getPassword().getMyStr()))
				{
					cout << "\nYou are successesfully logged in.";
					iFileLogIn.close();
				}
			}
		}
	}
	else {
		cout << "\nYou are not registered!";
		iFileLogIn.close();
	}

	delete[] line;
}