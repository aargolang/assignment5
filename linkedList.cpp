/*
Paul Calvert
05/03/16
LinkedList.cpp
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	first_ = NULL;
	last_ = NULL;
	listLen_ = 0;
}

LinkedList::~LinkedList()
{
	
}

void LinkedList::AddLinkToBack(void* ptr)
{
	if(listLen_ == 0)
        {
                first_ = last_ = ((Node*)ptr);
        }

        else
        {
		Node* Nptr = first_;
                while(Nptr->next_ != NULL)
                {
                       Nptr = Nptr->next_;
                }
                Nptr->next_ = last_ = ((Node*)ptr);
        }
        listLen_++;	
}


void* LinkedList::RemoveLinkFromFront()
{
	void* ptr = NULL;//needs to be a void pointer because it is returns a void pointer at the end

        if(listLen_ == 0)
                return ptr;

        else if(listLen_ == 1)
        {
               	ptr = first_;
                first_ = NULL;
        }

        else
       	{
               	ptr = first_;//sets the pointer at the first link, which will be returned at the end
                first_ = ((Node*)ptr)->next_;//sets the new first_ to the next node of the previous first_
        }
        listLen_--;//can be done at the end because the earlier return if count == 0 exits this process before it is decremeneted
        return ptr;
}

void* LinkedList::GetFirstNode()
{
	void* ptr = NULL;

	if(listLen_ == 0)
		return ptr;

	else
	{
		ptr = first_;
	}

	return ptr;
}

void* LinkedList::GetLastNode()
{
	void* ptr = NULL;

	if(listLen_ == 0)
		return ptr;

	else
	{
		ptr = last_;
	}
	return ptr;
}

void* LinkedList::GetNextNode(void* ptr)
{
	void* Nptr = NULL;
	if(listLen_ == 0 || listLen_ == 1)
		return Nptr;

	else
	{
		Nptr = ((Node*)ptr)->next_; 
	}

	return Nptr;
}

long LinkedList::GetListLength()
{
	return listLen_;
}

void LinkedList::DecrementListLength()
{
	listLen_--;
}
