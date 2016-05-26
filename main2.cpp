/*
1)Create users and login as that user (permissions optional, to show normal users versus the admin. No passwords)
- requires User Class and User document (linkedlist)

2)Store books
- requires Book Class and Book stored document (and linkedlist?)

3)Be able to search books
- Search in the Book Linkedlist

4)Be able to check in and check out books
- Book class has an original book count, and an available book count. Save checked out books to a seperate .txt file that is read/written to by functions. You can search who a certain book is checked out to and what books you have checked out. Make a struct/class to make functions specific to this

Functions
User functions required, admin functions optional features
1) Create user(Arthur)
2) Login(Arthur)
3) Search books (Arthur)
4) Check out book (Paul)
5) Check in book (Paul)
6) Check who has book X checked out (admin)
7) Check what I have checked out (Paul)
8) opt - Include due dates and late fees
9) View all books that are checked out (admin)
10) Delete User (admin)
11) Remove book from system (admin)
12) Change book count of certain book (admin)

User Class
Private
char* Name

Public
User(char*)
~User()
char* getUserName()
dd
Book Class (Arthur)

Private
char* bookName
int origCount
int availCount

Public
char* getBookName()
int getOrigCount()
int getAvailCount()
void checkoutBook()
void checkinBook()

LinkedList Class (update) (Paul)
Node
data1
data2
next

Private

Public

void checkoutBook(data1*, data2*)
void checkinBook(data1*, data2*)
*/

// Assignment 5 - Library Terminal
//
// Goals - this program will be able to:
// 	* read library catolog from file
// 	* read user database from file
// 	* register new users
// 	* check books out to users
// 	* check books back in
#define _CRT_SECURE_NO_WARNINGS
const int MAX_SZ = 256;
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "user.h"
#include "linkedList.h"

void readUserFile(LinkedList & userList)
{
	ifstream userFile;
	User * tempUser;
	char userNM[MAX_SZ];

	userFile.open("userFile.txt");
	// load users into user linked list omitting names shorter than 4 characters
	while (!userFile.eof()) {
		userFile.getline(userNM, MAX_SZ, '\n');
		if (strlen(userNM) > 2){
			cout << "* current users *" << endl; // debug
			cout << userNM << endl; // debug
			tempUser = new User();
			tempUser->setUserName(userNM);
			userList.addLinkToBack((User*)tempUser);
		}
	}
}

void loginDisplay()
{
	cout << "# USER LOGIN SCREEN #" << endl;
	cout << "1) login" << endl;
	cout << "2) register" << endl;
}

bool loginUser(LinkedList & userList, User * currentUser)
{
	char loginReply[MAX_SZ];
	Node * currentNode;
	bool exitLogMenu = false;

	cin.ignore();
	while (exitLogMenu == (false)){ // login menu
		cout << "Please login with your user name (x to cancel)" << endl;
		cin.getline(loginReply, MAX_SZ);
	
		if (strcmp(loginReply, "x") == 0){ // exit case
			cout << "cancelling login" << endl;
			exitLogMenu = true;
		}
		else { // login case
			currentNode = ((Node*)userList.getFirstNode());
			for (int i = 0; i < userList.getListLength(); i++){
				if (strcmp(loginReply, ((User*)currentNode->data1_)->getUserName()) == 0){
					cout << "YESS!!!!!" << endl;
					currentUser = (User*)currentNode->data1_; 
					return true;
				}
				else 
					currentNode = currentNode->next_;
			}
		}
	}
	return false;
}

void createUser(LinkedList & userList){
	char newUserNM[MAX_SZ];
	User * tempUser;	
	
	cin.ignore();
	cout << "Please enter your desired user name(no spaces)" << endl;
	cin.get(newUserNM, MAX_SZ, '\n');
	cout << strlen(newUserNM) << endl; // debug
	if (strlen(newUserNM) > 4){
		tempUser = new User();
		tempUser->setUserName(newUserNM);
		cout << "made new user" << endl; // debug
		userList.addLinkToBack((User*)tempUser);
		cout << "added user to LL" << endl; // debug
	}
	else {
		cout << "invalid username :'(" << endl;
	}
}

bool loginScreen(LinkedList & userList, User * currentUser)
{
	int logScreenReply = 0;
	//bool loggedIn = false;	
	
	loginDisplay();
	cout << "number of users: " << userList.getListLength() << endl;
	cin >> logScreenReply;

	if (logScreenReply == 1) { // user login
		return loginUser(userList, currentUser);
		//return loggedIn;
	}
	else if (logScreenReply == 2) { // register new user
		createUser(userList);
	}
	else {
		cout << "invalid selection" << endl;
	}
	return false;
}

void mainMenuDisplay()
{
	cout << "1) #MENUITEM#" << endl;
	cout << "2) #MENUITEM#" << endl;
	cout << "3) #MENUITEM#" << endl;
	cout << "4) #MENUITEM#" << endl;
	cout << "5) Logout" << endl;
	cout << "6) Quit" << endl;
}

int main()
{
	char mainReply[MAX_SZ] = "0";
	bool mainTerminate = false;
	bool loggedIn = false;
	//LinkedList bookList;
	//LinkedList transactionList;
	LinkedList userList;
	User * currentUser = nullptr; // this will be a pointer to the user who will be performing the actions

	readUserFile(userList);
	while (mainTerminate == false) {
		loggedIn = loginScreen(userList, currentUser);

		while (loggedIn == true)
		{
			mainMenuDisplay(); // include "welcome " << user.getName() << "! what do want to do today?"
			cin >> mainReply;

			if (atoi(mainReply) == 1) {// search for book
									   //searchForBook();
				cout << "search for book" << endl;
			}
			if (atoi(mainReply) == 2) {// check out book
									   //checkBookOut();
				cout << "check book out" << endl;
			}
			if (atoi(mainReply) == 3) {// check in book
									   //checkBookIn();
				cout << "check book in" << endl;
			}
			if (atoi(mainReply) == 4) {// display currently checked out
									   //displayCheckedOut(currentUser, transactionList);
				cout << "display currently checked out" << endl;
			}
			if (atoi(mainReply) == 5) {// logout
				loggedIn = false;
				cout << "log out" << endl;
			}
			if (atoi(mainReply) == 6) {// exit program
				loggedIn = false;
				mainTerminate = true;
				cout << "exit" << endl;
			}
		}
	}
	return 0;
}
