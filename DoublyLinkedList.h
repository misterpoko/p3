#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
using namespace std;

template<class T> struct NodeType;
template<class T>
class DoublyLinkedList 
{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertItem(T &item);
    void deleteItem(T &item);
    int lengthIs() const;
    void print();
    void printReverse();
    void deleteSubsection();
    void mode();
    void swapAlternate();

  private:
    int length;    
    NodeType<T> *head;	
    NodeType<T> *tail;
	  NodeType<T> *before;
	  NodeType<T> *after;
};

template<class T>
struct NodeType 
{
    T data;
    NodeType<T> *next;
    NodeType<T> *back;
};

#endif
