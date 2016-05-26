#ifndef LL_h
#define LL_h

struct Node
{
    void* data1_;
    void* data2_;
    Node* next_;

    Node()
    {
        data1_ = 0;
        data2_ = 0;
	next_ = 0;
    }
};

class LinkedList
{
private:
    Node* first_;
    Node* last_;
    long listLen_;

public:
    LinkedList();
    ~LinkedList();
    void AddLinkToBack(void* ptr);
    void* RemoveLinkFromFront();
    void* GetFirstNode();
    void* GetLastNode();
    void* GetNextNode(void* ptr);
    long GetListLength();
    void DecrementListLength();
};

#endif
