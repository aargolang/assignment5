#ifndef USER_H
#define USER_H
#define _CRT_SECURE_NO_WARNINGS
const int ENTRY_SZ = 256;

class User 
{
private:
	char * name_;

public:
	// Constructors Destructors
	//User(char * nm); ## CAUSING SEGMENTATION FAULTS ##
	User();
	~User();
	
	// Getters and Setters
	char * GetUserName();
	void SetUserName(char * nm);	
};
#endif