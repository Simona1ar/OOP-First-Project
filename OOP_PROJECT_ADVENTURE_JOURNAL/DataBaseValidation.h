#pragma once
#include "MyString.h"
#include <iostream>
using namespace std;
#include <cstring>

bool isAlphabet(const char c);
bool isDash(const char c);
bool isDigit(const char c);
bool isDot(const char c);
bool isDownDash(const char c);
bool isLeapYear(int year);
bool isValidDay(int day);
bool isValidMonth(int month);
bool isValidYear(int year);
bool isValidGrade(const int grade);
bool usernameValidation(const MyString username);
bool isValidDestination(const MyString des);
bool isValidPictureName(const MyString picture);
bool dateValidation(int year, int month, int day);
bool isValidDate(const MyString date);
bool validEmail(const MyString email);
bool passwordValidation(const MyString password);

