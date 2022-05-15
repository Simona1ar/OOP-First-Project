#include "User.h"
#include <iostream>
#include <cstring>
using namespace std;

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
void User::setEmail(MyString email) {
		this->email = email;
}
User::User() : username(), password(), email() {}

User::User(const char* _username, const char* _password, const char* _email) {
	this->username = MyString(_username);
	this->password = MyString(_password);
	this->email = MyString(_email);
}