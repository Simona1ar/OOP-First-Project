#pragma once
#include "MyString.h"

class User {
private:
	MyString username;
	MyString password;
	MyString email;
	void copy(const char* username, const char* password, const char* email);
	void clear();

public:
	bool usernameValidation(MyString username);
	bool passwordValidation(MyString password);
	bool validEmail(MyString email);
	char* getUsername();
	char* getPassword();
	char* getEmail();
	void setUsername(MyString username);
	void setPassword(MyString password);
	void setEmail(MyString email);
	User();
	User(const MyString username, MyString password, MyString email);
	User(const User& other);
	User& operator=(const User& other);
	~User();

};