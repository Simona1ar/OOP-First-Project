#pragma once
#include "MyString.h"
#include "DataBaseValidation.h"

class User {
private:
	MyString username;
	MyString password;
	MyString email;

public:
	MyString getUsername();
	MyString getPassword();
	MyString getEmail();
	void setUsername(MyString username);
	void setPassword(MyString password);
	void setEmail(MyString email);
	User();
	User(const char* username, const char* password, const char* email);
};