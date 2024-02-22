/**
 * @author Irmak İmdat 
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename ids>
struct Node
{
    ids item;
    Node<ids>* next;
};

template<typename ids>
class LinkedList
{
    public:

        LinkedList();
        LinkedList(const LinkedList<ids>& aList);
        virtual ~LinkedList();

        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ids& newEntry);
        bool remove(int position);
        void clear();
        ids& getEntry(int position) const;
        
    private:  

        Node<ids>* headPtr;
        int itemCount;
        Node<ids>* getNodeAt(int position) const;
        
};

#include "LinkedList.cpp"
#endif