/**
 * @author Irmak İmdat 
*/
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include <iostream>
#include "LinkedList.h"
using namespace std;

template<typename ids>
LinkedList<ids>::LinkedList()
{
    headPtr = nullptr;
    itemCount = 0;
}

template<typename ids>
LinkedList<ids>::LinkedList(const LinkedList<ids>& aList)
{
    headPtr = aList.headPtr;
    itemCount = aList.itemCount;
}

template<typename ids>
LinkedList<ids>::~LinkedList()
{
    clear();
}

template<typename ids>
bool LinkedList<ids>::isEmpty() const
{
    return itemCount == 0;
}

template<typename ids>
int LinkedList<ids>::getLength() const
{
    return itemCount;
}

template<typename ids>
bool LinkedList<ids>::insert(int newPosition, const ids& newEntry)
{
    bool insertSuccesfull = (newPosition >= 1) && (newPosition <= itemCount + 1);

    if(insertSuccesfull)
    {
        Node<ids>* newNodePtr = new Node<ids>();
        newNodePtr->item = newEntry;

        if(newPosition == 1)
        {
            newNodePtr->next = headPtr;
            headPtr = newNodePtr;
        }
        else
        {
            Node<ids>* prev = getNodeAt(newPosition - 1);

            newNodePtr->next = prev->next;
            prev->next = newNodePtr;
        }
        itemCount++;
    }
    return insertSuccesfull;
}

template<typename ids>
bool LinkedList<ids>::remove(int position)
{
    bool removeSuccesfull = (position >= 1) && (position <= itemCount + 1);

    if(removeSuccesfull)
    {
        Node<ids>* curPtr = nullptr;

        if(position == 1)
        {
            curPtr = headPtr; // to prevent memory leak
            headPtr = headPtr->next;
        }
        else
        {
            Node<ids>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr->next;
            prevPtr->next = curPtr->next;
        }

        curPtr->next = nullptr;
        delete curPtr;
        curPtr = nullptr;

        itemCount--;
    }

    return removeSuccesfull;
}

template<typename ids>
void LinkedList<ids>::clear()
{
    while(!isEmpty())
        remove(1);
}

template<typename ids>
ids& LinkedList<ids>::getEntry(int position) const 
{
    Node<ids>* nodePtr = getNodeAt(position);
    return nodePtr->item;
}

template<typename ids>
Node<ids>* LinkedList<ids>::getNodeAt(int position) const
{
    Node<ids>* curPtr = headPtr;

    for(int i = 1; i < position; i++)
    {
        curPtr = curPtr->next;
    }

    return curPtr;
}

#endif