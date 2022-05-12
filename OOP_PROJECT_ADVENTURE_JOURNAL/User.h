#pragma once

class User {
private:
	char* username;
	char* password;
	char* email;
	void copy(const char* username, const char* password, const char* email);
	void clear();

public:
	bool usernameValidation(const char* username);
	bool passwordValidation(const char* password);
	bool validEmail(const char* email);
	char* getUsername();
	char* getPassword();
	char* getEmail();
	void setUsername(char* username);
	void setPassword(char* password);
	void setEmail(char* email);
	User();
	User(const char* username, const char* password, const char* email);
	User(const User& other);
	User& operator=(const User& other);
	~User();

};