#include "MyString.h"

MyString::MyString() : myStr{nullptr} {//default constructor
	myStr = new char[1];
	myStr[0] = '\0';
}

MyString::MyString(const char* str) {//constructor
	myStr = new char[strlen(str) + 1];
	strcpy_s(this->myStr, strlen(str) + 1, str);
}

MyString::MyString(MyString const& other) : myStr(new char[strlen(other.myStr) + 1]) {//copy constructor
	strcpy_s(this->myStr, strlen(other.myStr) + 1, other.myStr);
}

MyString& MyString::operator=(MyString const& other) {//operator=
	if (this != &other) {
		delete[] myStr;
		int len = strlen(other.myStr) + 1;
		myStr = new char[len];
		strcpy_s(this->myStr, len, other.myStr);
	}
	return *this;
}

MyString::~MyString() {//destructor
	delete[] myStr;
	myStr = nullptr;
}

const char* MyString::getMyStr() const {
	return this->myStr;
}

unsigned int MyString::size()const {
	return strlen(myStr);
}
const char MyString::getSymbolAt(int pos) const {
	for (int i = 0; i < strlen(myStr); i++)
	{
		if (i == pos) {
			return myStr[i];
		}
	}
}
bool MyString::cmpStrWithCharArray(const char* str)
{
	return (strcmp(str, myStr));
}
MyString& operator+(MyString& const lhs, MyString& const rhs) {
	return (lhs + rhs);
}

ostream& operator<<(ostream& out, const MyString& obj) {
	out << obj.myStr << '\n';
	return out;
}

istream& operator>>(istream& in, MyString& obj) {
	obj.~MyString();

	const int buffSize = 100;
	char buffer[buffSize];
	in.getline(buffer, buffSize);
	obj.myStr = new char[strlen(buffer) + 1];
	strcpy_s(obj.myStr, strlen(buffer) + 1, buffer);

	return in;
}

