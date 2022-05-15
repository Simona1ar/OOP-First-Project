#pragma once
#include <iostream>
#include <fstream>
#include "User.h"
#include "MyString.h"
#include "DataBaseValidation.h"
using namespace std;

int getRecordTimes();
void closeFile();
void checkUsername(MyString usern);
void regUsername();
void regPassword();
void regEmail();
