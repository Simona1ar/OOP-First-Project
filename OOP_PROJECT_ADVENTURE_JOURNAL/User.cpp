#include "User.h"
#include "DataBaseValidation.h"
#include <iostream>
#include <cstring>
using namespace std;

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}
bool User::usernameValidation(const char* username) {
	int len = strlen(username);
	if (len < 3) {
		cout << "Too short.Username should be at least 3 symbols.";
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (isDigit(!username[i]) || !isAlphabet(username[i])) {
			cout << "Invalid symbol!";
			return false;
		}
	}
	return true;
}
bool User::validEmail(const char* email) {
	if (!isAlphabet(email[0])) //email can't start with digit
		return false;
	int len = strlen(email);
	int aPos = -1; //@
	int dotPos = -1; //.
	for (int i = 0; i < len; ++i) {
		if (email[i] == '@')
			aPos = i;
		if (email[i] == '.')
			dotPos = i;
	}
	if (aPos == -1 || dotPos == -1) //email should include dot and @
		return false;
	if (dotPos >= len - 1) // dot can't be the last symbol 
		return false;
	if (aPos > dotPos) //dot should be after @
		return false;
	return true;
}
bool User::passwordValidation(const char* password) {
	int len = strlen(password);
	if (len < 6) {
		cout << "Too short password!\n";
		return false;
	}
	return true;
}

void User::copy(const char* username, const char* password, const char* email) {
	this->username = new char[strlen(username) + 1];
	this->password = new char[strlen(password) + 1];
	this->email = new char[strlen(email) + 1];

	strcpy_s(this->username, strlen(username) + 1, username);
	strcpy_s(this->password, strlen(password) + 1, password);
	strcpy_s(this->email, strlen(email) + 1, email);
}

void User::clear() {
	delete[] username;
	username = nullptr;
	delete[] password;
	password = nullptr;
	delete[] email;
	email = nullptr;
}
char* User::getUsername() {
	return username;
}
char* User::getPassword() {
	return password;
}
char* User::getEmail() {
	return email;
}
void User::setUsername(char* username) {
	this->username = username;
}
void User::setPassword(char* password) {
	this->password = password;
}
void User::setEmail(char* email) {
	this->email = email;
}
User::User() : username(nullptr), password(nullptr), email(nullptr) {}

User::User(const char* username, const char* password, const char* email) {

	copy(username, password, email);
}

User::User(const User& other) {
	copy(other.username, other.password, other.email);
}

User& User::operator=(const User& other)
{
	if (this != &other) {
		clear();
		copy(other.username, other.password, other.email);
	}
	return *this;
}

User::~User() {
	clear();
}