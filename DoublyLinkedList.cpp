#include <iostream>
#include "DoublyLinkedList.h"
#include <string.h>

using namespace std;
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    length = 0; 
}

template<class T>
void DoublyLinkedList<T>::insertItem(T &item)
{
    length++;
}
template<class T>
void DoublyLinkedList<T>::deleteItem(T &item)
{  
    length--; 
}
template<class T>
int DoublyLinkedList<T>::lengthIs() const
{
    return length;
}
template<class T>
void DoublyLinkedList<T>::print()
{

}
template<class T>
void DoublyLinkedList<T>::printReverse()
{

}
template<class T>
void DoublyLinkedList<T>::deleteSubsection()
{

}
template<class T>
void DoublyLinkedList<T>::mode()
{

}
template<class T>
void DoublyLinkedList<T>::swapAlternate()
{

}
// Needs to stay at very bottom
template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<std::string>;



