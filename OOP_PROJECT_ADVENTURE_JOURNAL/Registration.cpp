#include "Registration.h"
ifstream iFile;
ofstream oFile("DataBase.txt", ios::app);

int recordsTimes = 0;
User* users;
MyString usernameReg;
MyString passwordReg;
MyString emailReg;
MyString usernameInFile;

int getRecordTimes(){
	return recordsTimes;
}
void closeFile() {
	oFile.close();
}
void checkUsername(MyString usern) {
	iFile.open("DataBase.txt");
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
		cin >> usernameReg;
		//file.close();???
		checkUsername(usernameReg);
	}
}

void regUsername() {
	cout << "\nEnter username: ";
	cin >> usernameReg;
	if (!usernameValidation(usernameReg)) {
		cout << "\nInvalid username!";
	}
	else
	{
		users->setUsername(usernameReg);
		recordsTimes = 0;
		checkUsername(usernameReg);
		oFile << usernameReg << endl;
	}
}

void regPassword() {
	cout << "\nEnter password: ";
	cin >> passwordReg;
	if (!passwordValidation(passwordReg)) {
		cout << "\nToo short password!";
	}
	else {
		users->setPassword(passwordReg);
		oFile << passwordReg << endl;
	}
}

void regEmail() {
	cout << "\nEnter email: ";
	cin >> emailReg;
	if (!validEmail(emailReg)) {
		cout << "\nInvalid email!";
	}
	else {
		users->setEmail(emailReg);
		oFile << emailReg << endl;
	}
}