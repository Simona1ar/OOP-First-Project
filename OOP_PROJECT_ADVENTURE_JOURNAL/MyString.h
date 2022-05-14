#pragma once
#include <fstream>
#include <cstring>
using namespace std;

class MyString {
private:
	char* myStr;
public:
	MyString(const char* str = "\0");
	MyString(MyString const& other);
	MyString& operator=(MyString const& other);
	~MyString();

	const char* getMyStr()const;
	friend MyString& operator+(MyString& const lhs, MyString& const rhs);
	friend ostream& operator<<(ostream& out, const MyString& obj);
	friend istream& operator>>(istream& in, MyString& obj);
};