#pragma once
#include <iostream>
#include <fstream>
#include "User.h"
#include "MyString.h"
using namespace std;

User* users;
MyString username;
MyString password;
MyString email;
int recordsTimes = 0;

void checkUsername(MyString usern);
void regUser();