#include <cstring>
#include <iostream>
#include <string>
#include "book.h"

// Constructors and Destructors
Book::Book(char * nm, int max, int cur){
	setName(nm);
	setMax(max);
	setCur(cur);
}
/*
Book::Book(){
	name = "DEFAULT";
	maxAMT = 0;
	curAMT = 0;
}
*/
Book::~Book(){
	// nothing needed for destructor
}

// Getters and Setters
char * Book::getName(){
	return name;	
}

int Book::getMax()
{
	return maxAMT;
}

int Book::getCur(){
	return curAMT;
}

void Book::setName(char * nm)
{
	strcpy(name, nm);
}

void Book::setMax(int max)
{
	maxAMT = max;
}

void Book::setCur(int cur)
{
	curAMT = cur;
}

// Utility Functions
/*void checkIn(){
	if (curAMT < maxAMT){
		curAMT++;
	}
	else 
		; // maybe output "error: all books checked in"
}
void checkOut(){
	if (curAMT > 0){
		curAMT--;
	}
	else 
		;
}*/
