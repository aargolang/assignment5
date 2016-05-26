OBJS = main.o user.o linkedList.o book.o
CC = g++
CPPFLAGS = -Wall -c -g -std=c++11
LFLAGS = -Wall -g

run: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o run

main.o: main.cpp
	$(CC) $(CPPFLAGS) main.cpp

likedList.o: linkedList.cpp linkedList.h
	$(CC) $(CPPFLAGS) linkedList.cpp

user.o: user.cpp user.h
	$(CC) $(CPPFLAGS) user.cpp

book.o: book.cpp book.h
	$(CC) $(CPPFLAGS) book.cpp

clean: 
	rm -f *.o 
	rm -f run
