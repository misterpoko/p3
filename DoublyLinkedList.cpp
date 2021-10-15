#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>

using namespace std;
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	NodeType<T> * beforeHead = new NodeType<T>;
	NodeType<T> * afterEnd = new NodeType<T>;
	before = beforeHead;
	after = afterEnd;
	before->next = head;
	after->back = tail;
	length = 0; 
} // DoublyLinkedList

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	delete(before);
	NodeType<T> * traverse = head;
	while (head != NULL)
	{
		before = head;
		traverse = head;
		head = head->next;
		delete(before);
		delete(traverse);
	} // while
} // ~DoublyLinkedList

template<class T>
void DoublyLinkedList<T>::insertItem(T &item)
{
	NodeType<T> *newItem = new NodeType<T>;
	newItem->data = item;
	if (lengthIs() == 0)
	{
		head = newItem;
		head->back = before;
		head->next = after;
		tail = newItem;
	} 
	else
	{
		NodeType<T> * traverse = head;
		while ((newItem->data)>(traverse->data))
		{
			traverse = traverse->next;
		} // while
		newItem->next = traverse;
		newItem->back = traverse->back;
		traverse->back = newItem;
		newItem->back->next = newItem;
	} // if
	length++;
} // insertItem

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item)
{  
    length--; 
} // deleteItem

template<class T>
int DoublyLinkedList<T>::lengthIs() const
{
    return length;
} // lengthIs

template<class T>
void DoublyLinkedList<T>::print()
{

} // print

template<class T>
void DoublyLinkedList<T>::printReverse()
{

} // printReverse

template<class T>
void DoublyLinkedList<T>::deleteSubsection()
{

} // deleteSubsection

template<class T>
void DoublyLinkedList<T>::mode()
{

} // mode

template<class T>
void DoublyLinkedList<T>::swapAlternate()
{

} // swapAlternate

// Needs to stay at very bottom
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;



