#include "DataBaseValidation.h"
const int maxFormatLen = 5;
const int maxDateLen = 10;
const int constDateLen = 8;
const int minYear = 1900;
const int maxYear = 3000;

bool isAlphabet(const char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
bool isDot(const char c) {
	return(c == '.');
}
bool isDownDash(const char c) {
	return(c == '_');
}
bool isDash(const char c) {
	return(c == '-');
}
bool isDigit(const char c) {
	return (c >= '0' && c <= '9');
}
bool isValidGrade(const int grade) {
	return (grade >= 1 && grade <= 5);
}


bool usernameValidation(const MyString username) {
	int len = username.size();
	if (len < 3 && len > 32) {
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (!isDigit(username.getSymbolAt(i)) || !isAlphabet(username.getSymbolAt(i))) {
			return false;
		}
	}
	return true;
}
bool validEmail(MyString email) {
	if (!isAlphabet(email.getSymbolAt(0))) //email can't start with digit
		return false;
	int len = email.size();
	int aPos = -1; //@
	int dotPos = -1; //.
	for (int i = 0; i < len; ++i) {
		if (email.getSymbolAt(i) == '@')
			aPos = i;
		if (email.getSymbolAt(i) == '.')
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
bool passwordValidation(const MyString password) {
	int len = password.size();
	if (len < 6) {
		return false;
	}
	return true;
}

bool isValidDestination(const MyString des) {
	for (int i = 0; i < des.size(); i++)
	{
		if (!isAlphabet(des.getSymbolAt(i)) && des.getSymbolAt(i) != ',')
			return false;
	}
	return true;
}

bool isValidPictureName(const MyString pictureName) {
	int nameLen = pictureName.size();
	char buffer[maxFormatLen] = { '\0' };
	int index = 0;
	for (int i = 0; i < nameLen; i++)
	{
		if (!isAlphabet(pictureName.getSymbolAt(i)) && !isDot(pictureName.getSymbolAt(i)) && !isDownDash(pictureName.getSymbolAt(i)))
		{
			cout << "Invalid symbol!\n";
			return false;
		}
		if (isDot(pictureName.getSymbolAt(i)))
		{
			if (isDownDash(pictureName.getSymbolAt(i-1)) == 1 || isDownDash(pictureName.getSymbolAt(i+1) == 1))
				return false;
			int formatLen = nameLen - i;
			if (formatLen > maxFormatLen)
			{
				cout << "Invalid picture format!\n";
				return false;
			}
			for (int j = i + 1; j < nameLen; j++)
			{
				buffer[index++] = pictureName.getSymbolAt(j);
			}
			buffer[index] = '\0';
			break;
		}
	}
	if (strcmp(buffer, "png") != 0 && strcmp(buffer, "jpeg") != 0)
		return false;

	return true;
}


bool isLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}
bool isValidYear(int year) {
	return(year >= minYear && year <= maxYear);
}
bool isValidMonth(int month) {
	return (month >= 1 && month <= 12);
}
bool isValidDay(int day) {
	return (day >= 1 && day <= 31);
}
bool dateValidation(int year, int month, int day) {
	if (month == 2) {
		if (isLeapYear(year))
			return (day <= 29);
		else
			return (day <= 28);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);
	return true;
}
bool isValidDate(const MyString date) {
	int dateLen = date.size();
	int arr[constDateLen] = { 0 };
	int index = 0;
	int year = 0;
	int month = 0;
	int day = 0;

	if (dateLen != 10)
		return false;
	for (int i = 0; i < maxDateLen; i++)
	{
		if ((!isDigit(date.getSymbolAt(i))) && (!isDash(date.getSymbolAt(i))))
		{
			return false;
		}
		if (!isDash(date.getSymbolAt(i))) {
			arr[index++] = date.getSymbolAt(i) - '0';
		}
	}
	//year
	for (int i = 0; i < 4; i++)
	{
		year *= 10;
		year += arr[i];
	}
	if (!isValidYear(year)) {
		cout << "Invalid year!\n";
		return false;
	}
	//month
	for (int i = 4; i < 6; i++)
	{
		month *= 10;
		month += arr[i];
	}
	if (!isValidMonth(month)) {
		cout << "Invalid month!\n";
		return false;
	}
	//day
	for (int i = 6; i < 8; i++)
	{
		day *= 10;
		day += arr[i];
	}
	if (!isValidDay(day)) {
		cout << "Invalid day!\n";
		return false;
	}
	if (!dateValidation(year, month, day))
		return false;
	return true;
}
