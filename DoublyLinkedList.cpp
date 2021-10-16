#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	NodeType<T> * beforeHead = new NodeType<T>;
	NodeType<T> * afterEnd = new NodeType<T>;
	before = beforeHead;
	after = afterEnd;
	//before->next = head;
	//after->back = tail;
	length = 0; 
} // DoublyLinkedList

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	delete(before);
	while (head != NULL)
	{
		before = head;
		head = head->next;
		delete(before);
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
		before->next = head;
		after->back = head;
		tail = newItem;
	} 
	else
	{
	NodeType<T> * traverse = head;
	
//	cout <<" this should print" << head->data;
	//cout << "thing" << traverse->data;
		while (traverse != after && (newItem->data)>(traverse->data))
		{
			traverse = traverse->next;
		} // while
		newItem->next = traverse;
		newItem->back = traverse->back;
		traverse->back = newItem;
		newItem->back->next = newItem;
	} // if	
	head = before->next;
	tail = after->back;
	length++;
} // insertItem

template<class T>
void DoublyLinkedList<T>::deleteItem(T &item) //Seg Fault when deleting the last element
{ 
	NodeType<T> *traverse = head;
	if (traverse == NULL)
	{
		cout << "You cannot delete from an empty list." << endl;
		return;
	} // if
	while ((traverse->data != item) && (traverse != after))
	{
		traverse = traverse->next;
	} // while
	if (traverse == after)
	{
		cout << "Item not in list!" << endl;
		return;
	} // if
	traverse->back->next = traverse->next;
	traverse->next->back = traverse->back;
	delete(traverse);
	length--;
	if (lengthIs() > 0)
	{ 
		head = before->next;
		tail = after->back;
	}
	else
	{
		head = NULL;
		tail = NULL;
	} // if
} // deleteItem

template<class T>
int DoublyLinkedList<T>::lengthIs() const
{
    return length;
} // lengthIs

template<class T>
void DoublyLinkedList<T>::print()
{
	NodeType<T> *traverse = head;
	while (traverse != after)
	{
		cout << traverse->data << " ";
		traverse = traverse->next;
	}// while
	cout << endl; 
} // print

template<class T>
void DoublyLinkedList<T>::printReverse()
{
	NodeType<T> *traverse = tail;
	if (traverse == NULL) 
	{
		cout << "empy list error message" << endl;
		return;
	} // if
	while (traverse != before)
	{
		cout << traverse->data << " ";
		traverse = traverse->back;
	} // while
	cout << endl; 
} // printReverse

template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &start, T &finish)
{
    if (finish < start)
    {
        cout << "end cannot be smaller than finish error message" << endl;
    } // if
    NodeType<T> *traverse = head;
    while (traverse != after)
    {
        if (traverse->data >= start && traverse->data <= finish)
        {
            deleteItem(traverse->data);
            traverse = head;
        } // if
    traverse = traverse->next;
    } // while
} // deleteSubsection

template<class T>
void DoublyLinkedList<T>::mode()
{
	T theData;
	NodeType<T> *traverse = head;
	int previous = 0;
	int current = 0;
	while (traverse != after)
	{
		if(previous < (current = countNum(traverse->data)))
		{
			theData = traverse->data;
			previous = current;
		} // if	
	} // while
	cout << theData;
} // mode

template<class T>
void DoublyLinkedList<T>::swapAlternate()
{

} // swapAlternate

template<class T>
int DoublyLinkedList<T>::countNum(T &theData)
{
	int i = 0;
	NodeType<T> *traverse = head;
	while (traverse != after)
	{
		if (theData == traverse->data)
		i++;	
	} // while
	return i;
} // if

void uo() {
	write(1,"hi", 3);	
} // uo
// Needs to stay at very bottom
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;