#pragma once
#include <iostream>
#include <fstream>
#include "User.h"
#include "MyString.h"
#include "DataBaseValidation.h"
using namespace std;

int getRecordTimes(); //counts how many times it is saved by a user in the file
void closeFile();//function for file closing
void checkUsername(MyString usern);//check if the username is already exists
void regUsername();//username validation + records in file
void regPassword();//password validation + records in file
void regEmail();//email validation + records in file
