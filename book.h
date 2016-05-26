#ifndef BOOK_H
#define BOOK_H
class Book
{
private:
	char name[256];
	int maxAMT;
	int curAMT;

public:
	// Constructors Destructors
	Book(char* nm, int max, int cur);
	Book() = default;
	~Book();

	// Getters and setters
	char* getName();
	int getMax();
	int getCur();
	void setName(char* nm);
	void setMax(int max);
	void setCur(int cur);
	
	// Utility functions
	//void checkIn();
	//void checkOut();
};
#endif
