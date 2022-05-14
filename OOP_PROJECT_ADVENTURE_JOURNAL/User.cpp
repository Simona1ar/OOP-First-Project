#include "User.h"
#include "DataBaseValidation.h"
#include <iostream>
#include <cstring>
using namespace std;



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
MyString User::getUsername() {
	return username;
}
MyString User::getPassword() {
	return password;
}
MyString User::getEmail() {
	return email;
}
void User::setUsername(MyString username) {
		this->username = username;
}
void User::setPassword(MyString password) {
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