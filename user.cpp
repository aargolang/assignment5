#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include <cstring>

// Constructors Destructors
User::User(){
	name_ = 0;
}
// ## CAUSING SEGMENTATION FAULTS ##
//User::User(char * nm){
//	setUserName(nm);
//}

User::~User(){
}

// Getters and Setters
char * User::GetUserName(){
	return name_;
}
void User::SetUserName(char * nm){
	if (name_) {
		delete[] name_;
	}
	name_ = new char[strlen(nm) + 1];
	strcpy(name_, nm);
}
