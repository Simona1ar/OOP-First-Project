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
	int len = strlen(username);
	if (len < 3) {
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (isDigit(!username[i]) || !isAlphabet(username[i])) {
			return false;
		}
	}
	return true;
}
bool validEmail(const char* email) {
	if (!isAlphabet(email[0])) //email can't start with digit
		return false;
	int len = strlen(email);
	int aPos = -1; //@
	int dotPos = -1; //.
	for (int i = 0; i < len; ++i) {
		if (email[i] == '@')
			aPos = i;
		if (email[i] == '.')
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
bool passwordValidation(const char* password) {
	int len = strlen(password);
	if (len < 6) {
		return false;
	}
	return true;
}

bool isValidDestination(const char* des) {
	for (int i = 0; i < strlen(des); i++)
	{
		if (!isAlphabet(des[i]) && des[i] != ',')
			return false;
	}
	return true;
}

bool isValidPictureName(const char* pictureName) {
	int nameLen = strlen(pictureName);
	char buffer[maxFormatLen] = { '\0' };
	int index = 0;
	for (int i = 0; i < nameLen; i++)
	{
		if (!isAlphabet(pictureName[i]) && !isDot(pictureName[i]) && !isDownDash(pictureName[i]))
		{
			cout << "Invalid symbol!\n";
			return false;
		}
		if (isDot(pictureName[i]))
		{
			if (isDownDash(pictureName[i - 1]) == 1 || isDownDash(pictureName[i + 1] == 1))
				return false;
			int formatLen = nameLen - i;
			if (formatLen > maxFormatLen)
			{
				cout << "Invalid picture format!\n";
				return false;
			}
			for (int j = i + 1; j < nameLen; j++)
			{
				buffer[index++] = pictureName[j];
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
bool isValidDate(const char* date) {
	int dateLen = strlen(date);
	int arr[constDateLen] = { 0 };
	int index = 0;
	int year = 0;
	int month = 0;
	int day = 0;

	if (dateLen != 10)
		return false;
	for (int i = 0; i < maxDateLen; i++)
	{
		if ((!isDigit(date[i])) && (!isDash(date[i])))
		{
			return false;
		}
		if (!isDash(date[i])) {
			arr[index++] = date[i] - '0';
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
