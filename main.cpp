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

// libraries
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

// headers
#include "book.h"
#include "user.h"
#include "LinkedList.h"

// namespaces globals
using namespace std;
const int MAX_SZ = 256;
LinkedList bookTransactions;

// functions for users and login
void readUserFile(LinkedList & userList);
void loginDisplay();
bool loginUser(LinkedList & userList, User * currentUser);
void createUser(LinkedList & userList);
bool loginScreen(LinkedList & userList, User * currentUser);

// functions for main
int mainMenuDisplay();

// functions for booksz
void checkOutBook(char* userName);
void displayPersonalBooks();

int main()
{
	int mainReply = 0;
	bool mainTerminate = false;
	bool loggedIn = false;
	//LinkedList bookList;
	//LinkedList transactionList;
	LinkedList userList;
	User * currentUser = nullptr; // this will be a pointer to the user who will be performing the actions
	char userName[MAX_SZ];

	readUserFile(userList);
	cout << endl << "********************** LIBRARY PROGRAM **************************" << endl << endl;
	while (mainTerminate == false) 
	{
		loggedIn = loginScreen(userList, currentUser);
		if (currentUser){
			strcpy(userName, currentUser->GetUserName());
			cout << endl << "Welcome " << userName << "!" << endl << endl;
		}
		while (loggedIn == true)
		{
			
			mainReply = mainMenuDisplay();
			
			switch(mainReply)
			{
			case 1:
				//search books
				break;
			case 2:
				//checkout books
				checkOutBook(userName);
				break;
			case 3:
				//check in books
				break;
			case 4:
				//display checked out books
				displayPersonalBooks();
				break;
			case 5:		
				//logout
				loggedIn = false;
				break;
			case 6:
				//quit
				loggedIn = false;
				mainTerminate = true;
				break;
			default:
				//error
				cout << "ERROR: INVALID INPUT. PLEASE TRY AGAIN." << endl;		
			}
		}
	}
	return 0;
}

void readUserFile(LinkedList & userList)
{
	ifstream userFile;
	User * tempUser;
	char userNM[MAX_SZ];

	userFile.open("userFile.txt");
	// load users into user linked list omitting names shorter than 4 characters
	cout << "* current users *" << endl; // debug
	while (!userFile.eof()) {
		userFile.getline(userNM, MAX_SZ, '\n');
		if (strlen(userNM) > 2){
			cout << userNM << endl; // debug
			tempUser = new User();
			tempUser->SetUserName(userNM);
			userList.AddLinkToBack((User*)tempUser);
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
			currentNode = ((Node*)userList.GetFirstNode());
			for (int i = 0; i < userList.GetListLength(); i++){
				if (strcmp(loginReply, ((User*)currentNode->data1_)->GetUserName()) == 0){
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
		tempUser->SetUserName(newUserNM);
		cout << "made new user" << endl; // debug
		userList.AddLinkToBack((User*)tempUser);
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
	cout << "number of users: " << userList.GetListLength() << endl;
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

int mainMenuDisplay()
{
	int option;

	cout << "Please make a selection from the menu below" << endl;
	cout << "1) Search for a book" << endl;
	cout << "2) Check out a book" << endl;
	cout << "3) Check in a book" << endl;
	cout << "4) View checked out books" << endl;
	cout << "5) Logout" << endl;
	cout << "6) Exit progam" << endl;

	cin >> option;
	cout << endl;
	return option;
}

void checkOutBook(char* userName)
{
	string novelName;
	char bookName[MAX_SZ];
	//char loggedInUser[MAX_SZ] = userName;	
	
	cout << endl;

	//cout << "Please enter your first name: ";
	//cin >> userName;

	cout << "Please enter a book title: ";
	cin.ignore();
	getline(cin, novelName);

	strcpy(bookName, novelName.c_str());

	User* patron = new User();
	patron->SetUserName(userName);
	Book* checkOutBook = new Book(bookName, 1, 1);

	Node* newNode = new Node();
	newNode->data1_ = patron;
	newNode->data2_ = checkOutBook;

	void* ptr = newNode;

	bookTransactions.AddLinkToBack(ptr);

	cout << endl << "Success! " << bookName << " checked out to " << userName << endl << endl;
}
void displayPersonalBooks()
{
	cout << "---- CHECKED OUT BOOKS ----" << endl;
	cout << "     User | Book Name" << endl;

	if(bookTransactions.GetListLength() < 1)
	{
		cout << "No books checked out to this user" << endl << endl;
	}
	else
	{
		void* ptr = bookTransactions.GetFirstNode();

		for(int i = 0; i < bookTransactions.GetListLength(); i++)
		{
			Node* nodePtr = (Node*)ptr;
			void* userPtr = nodePtr->data1_;
			void* bookPtr = nodePtr->data2_;

			User* currentUser = (User*)userPtr;
			Book* currentBook = (Book*)bookPtr;

			cout << "Patron: " << currentUser->GetUserName() << " | Book: " << currentBook->getName() << endl;
			ptr = bookTransactions.GetNextNode(ptr);
		}
		cout << endl;
	}
}
