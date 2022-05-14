#include "Registration.h"
#include "DataBaseValidation.h"

ifstream iFile;
ofstream oFile;

void checkUsername(MyString usern){
	MyString fileDirection;
	MyString type = ".db";
	fileDirection = usern + type;
	iFile.open(fileDirection.getMyStr());
	if (!iFile.is_open() && iFile.fail()) {
		//file.close();???
		return;
	}
	else {
		recordsTimes++;
		if (recordsTimes == 3) {
			cout << "\nThis username is already exists!";
			//file.close();???
			return;
		}
		cout << "\nThis username is already taken! Create another username: ";
		cin >> username;
		//file.close();???
		checkUsername(username);
	}
}
void regUser() {
	cout << "\nEnter username: ";
	cin >> username;
	if (!usernameValidation(username)) {
		cout << "\nInvalid username.";
	}
	else {
		users->setUsername(username);
	}

	cout << "\nEnter password: ";
	cin >> password;
	if (!passwordValidation(password)) {
		cout << "\nToo short password!";
	}
	else {
		users->setPassword(password);
	}

	cout << "\nEnter email: ";
	cin >> email;
	if (!validEmail(email)) {
		cout << "\nInvalid email.";
	}
	else {
		users->setEmail(email);
	}
	
}