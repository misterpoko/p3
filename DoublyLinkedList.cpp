#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
/*
 * This contructs the doubly linked list with an empty before and after pointers
*/
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	before = new NodeType<T>;
	after = new NodeType<T>;
	before->next = head;
	after->back = tail;
	length = 0; 
} // DoublyLinkedList

/*
 * This goes through the list one by one and deletes each node
*/
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while(lengthIs() != 0)
	{
		deleteItem(head->data);
	} // while
	delete(before);
	delete(after);
	before = after = head = tail = NULL;
} // ~DoublyLinkedList

/*
 * Method takes in an item and adds it to the link or makes it the head of the list. 
*/
template<class T>
void DoublyLinkedList<T>::insertItem(T &item)
{ 
	NodeType<T> *newItem = new NodeType<T>;
	newItem->data = item;
	// If item is the first element being added to and empty list it is made the head and tail.
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

/*
 * Prints the nodes one by one.  
*/
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

/*
 * Takes in an item and checks it with each item in the list. If they match it is deleted.
 * If the list is empty it doesnt delete and prints out corresponding message. 
 * If the item is not found in the list then "Item not in list".
*/
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
	}//if
} // deleteItem

/*
 * Returns the length of the list.
*/
template<class T>
int DoublyLinkedList<T>::lengthIs() const
{
    return length;
} // lengthIs

/*
 * Prints the list in reverse order.
*/
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



//Extra Methods
/*
 * This method takes in two items and deletes everthing in between the two items.
 * The method goes until it finds a match with the first @param 'start' and then 
 * deletes each node past it until its finds a match of the second @parma 'finish'.
 * If the list is empty nothing is printed.
*/
template<class T>
void DoublyLinkedList<T>::deleteSubsection(T &start, T &finish)
{
	/*
	 Checks to see if the lower bound is bigger than the upper bound.
	*/
	if (finish < start)
    {
        cout << "Lower bound cant be larger than upper bound" << endl;
		return;
    } //if
    NodeType<T> *traverse = head;
	//Checks to see if the list is empty.
	if(before->next == after)
	{
		cout << "Original List: " << endl;
		return;
	}//if 
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
            traverse = before;
        } // if
    	traverse = traverse->next;
    } // while
	if(before->next == after)
	{
		cout << "Modified List: ";
		cout << endl;
	}
	else
	{
		cout << "Modified List: " << endl;
		print();
	}
} // deleteSubsection


/*
 * A helper method that counts the number of times the same variable appears.
*/
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

/*
 * This method compares the number of times the same variarable appears. 
 * The value that is appears the most is stored in a genaric variable to be 
 * printed out.
*/
template<class T>
void DoublyLinkedList<T>::mode()
{
	T theData;
	NodeType<T> *traverse = head;
	int previous = 0;
	int current = 0;
	while (traverse != after)
	{
		//Calling helper method
		current = countNum(traverse->data);
		// Compares number of times the perivous value apears vs the number the current value does.
		if(previous < current)
		{
			previous = current; 
			theData = traverse->data;
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

/*
 * The method has takes the two pointers and takes the nodes and 
 * swaps them alternating.
*/ 
template<class T>
void DoublyLinkedList<T>::swapAlternate()
{
	NodeType<T> *traverse = head;
	NodeType<T> *traverse2 = head->next;
	NodeType<T> *dataBefore;
	NodeType<T> *dataAfter;
	cout << "Original List: ";
	print();
	//Checks to see if both are at the end of the list. 
	//This is and edge chase so that the last node isnt lost. 
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

//Template definitions
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;
