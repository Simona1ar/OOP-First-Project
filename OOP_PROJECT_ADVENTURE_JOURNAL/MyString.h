#pragma once
#include <fstream>
#include <cstring>
using namespace std;

/*create the class so that wherever I have a char*, 
it can take care of its own memory*/
class MyString {
private:
	char* myStr;
public:
	//Big four
	MyString();
	MyString(const char* str);
	MyString(MyString const& other);
	MyString& operator=(MyString const& other);
	~MyString();

	const char* getMyStr()const;//function which returns char*
	unsigned int size() const;//function which returns size of char*
	const char getSymbolAt(int pos) const;/*function to take the position of a char* character
	I made the function an auxiliary because objects of type MyString cannot be crawled as an array*/
	bool cmpStrWithCharArray(const char* str);/*function for comparing two char*
	This feature helped me compare the file in the login check*/
	friend MyString& operator+(MyString& const lhs, MyString& const rhs);//redefining '+' helped concatenate two MyString-type variables
	friend ostream& operator<<(ostream& out, const MyString& obj);
	friend istream& operator>>(istream& in, MyString& obj);
	
};