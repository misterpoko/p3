#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	before = new NodeType<T>;
	after = new NodeType<T>;
	before->next = head;
	after->back = tail;
	length = 0; 
} // DoublyLinkedList

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() // The mem leak/error in main is from when the compiler has to free the same object twice.
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
void DoublyLinkedList<T>::deleteItem(T &item)
{ 
	NodeType<T> *traverse = head;
	if(length == 0)
	{
		head = NULL;
		tail = NULL;
	} // if
	if (head == NULL)
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
} // deleteItem

template<class T>
int DoublyLinkedList<T>::lengthIs() const
{
    return length;
} // lengthIs

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
        cout << "Lower bound cant be larger than upper bound" << endl;
		return;
    } // if*/
    NodeType<T> *traverse = head;
	if(before->next == after)
	{
		cout << "Original List: " << endl;
	}
	else 
	{
		cout << "Original List: ";
		print();
	}
    while (traverse != after)
    {
        if ((traverse->data >= start) && (traverse->data <= finish))
        {
            deleteItem(traverse->data);
            traverse = before;// Do we need this command? 
        } // if
    traverse = traverse->next;
    } // while
	if(before->next == after)
	{
		cout << "Modified List: " << endl;
	}
	else 
	{
		cout << "Modified List: ";
		print();
	}
} // deleteSubsection

template<class T>
int DoublyLinkedList<T>::countNum(T &theData)
{
	int i = 0;
	NodeType<T> *traverse = head;
	while (traverse != after)
	{
		if (theData == traverse->data)
		{
			i++;	
		}
		traverse = traverse->next;
	} // while
	return i;
} // if

template<class T>
void DoublyLinkedList<T>::mode()
{
	T theData;
	NodeType<T> *traverse = head;
	int previous,current = 0;
	while (traverse != after)
	{
		current = countNum(traverse->data);
		if(previous < current)
		{
			previous = current;
			theData = traverse->data;
			//cout << theData << endl;
		}//if
		traverse = traverse->next;
	} // while
	if(previous == 1 || previous == current)
	{
		cout << "There is no mode. There are tied values" << endl;
	}//if
	else
		cout << "Mode: " << theData << endl;
} // mode

template<class T>
void DoublyLinkedList<T>::swapAlternate()
{
	/*NodeType<T> *traverse = head;
	NodeType<T> *ahead = traverse ->next;
	cout << "Original List: ";
	print();  
	while (traverse != after)
	{
		if (traverse == head)//Has to handle before and after cases so not to have a mem leak
		{
			ahead->next=traverse;
			ahead ->back = before;
			traverse->next = ahead->next;
			traverse->back = ahead;
			before->next = ahead;

			ahead = head; // update head
		}
		
		traverse = traverse->next;
		
	}*/
	NodeType<T> *traverse = head;
	NodeType<T> *traverse2 = head->next;
	NodeType<T> *dataBefore;
	NodeType<T> *dataAfter;
	while (traverse2 != after && traverse2 != NULL)
	{
		dataBefore = traverse->back;
		dataAfter = traverse2->next;
		dataBefore->next = traverse2;
		dataAfter->back = traverse; 

		traverse->next = dataAfter;
		traverse2->back = dataBefore;
		traverse->back = traverse2;
		traverse2->next = traverse;
		
		traverse = traverse->next;
		traverse2 = traverse->next;
	} // while
	head = before->next;
	cout << "Swapped List: ";
	print(); 
} // swapAlternate



void uo() {
	write(1,"hi", 3);	
} // uo

// Needs to stay at very bottom
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
