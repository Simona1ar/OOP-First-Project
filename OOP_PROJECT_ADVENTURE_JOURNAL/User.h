#pragma once
#include "MyString.h"
#include "DataBaseValidation.h"

class User {
private:
	MyString username;
	MyString password;
	MyString email;

public:
	//getters helped with login cheks
	MyString getUsername();
	MyString getPassword();
	MyString getEmail();
	//setters helped with registration
	void setUsername(MyString username);
	void setPassword(MyString password);
	void setEmail(MyString email);
	User();//default constructor
	User(const char* username, const char* password, const char* email);//constructor
};