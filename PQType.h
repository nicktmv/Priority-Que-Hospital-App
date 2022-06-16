#pragma once
#include "Heaps.h"
#include <iostream>
using namespace std;
template<class ItemType>
class PQType
{
public:
    PQType(int);          	// parameterized class constructor
    ~PQType();			    // class destructor
    void MakeEmpty();
    // Function: Initializes the queue to an empty
    // state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is
    // empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is
    // full.
    // Post: Function value = (queue is full)
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the
    // queue.
    // Pre:  Queue is not full.
    // Post: newItem is in the queue.
    void Dequeue(ItemType& item);
    void Print();
    // Function: Removes element with highest priority from the queue,
    // and returns it in item.
    // Pre:  Queue is not empty.
    // Post: Highest priority element has been removed from the queue.
    // item is a copy of the removed element

private:
    int numItems;
    HeapType<ItemType> items;
    int maxItems;
};

template<class ItemType>
PQType<ItemType>::PQType(int max)
{
    maxItems = max;
    items.elements = new ItemType[max];
    numItems = 0;
}

template<class ItemType>
PQType<ItemType>::~PQType()
{
    delete[] items.elements;
}

// Creates empty PQType
template<class ItemType>
void PQType<ItemType>::MakeEmpty()
{
    numItems = 0;
}

template<class ItemType>
bool PQType<ItemType>::IsEmpty() const
// Post: Function value = true if the queue is empty; false, otherwise
{
    return numItems == 0;
}
template<class ItemType>
bool PQType<ItemType>::IsFull() const
// Post: Function value = true if the queue is full; false, otherwise
{
    return numItems == maxItems;
}

template<class ItemType>
void PQType<ItemType>::Enqueue(ItemType newItem)
// newItem is added to the queue.
{
    numItems++;
    items.elements[numItems - 1] = newItem;
    items.ReheapDown(items.elements, 0, numItems - 1);
}


template<class ItemType>
void PQType<ItemType>::Dequeue(ItemType& item)
// element with highest priority is removed from the queue
{
    item = items.elements[0];
    items.elements[numItems - 1] = items.elements[numItems - 1];
    numItems--;
    items.ReheapUp(0, numItems - 1);
}


template<class ItemType>
void PQType<ItemType>::Print()
// Print function to display patients details: Priority and Name
// using "items.elements.priority" for the heap to fetch the priorty variable,
// inputed by user or pre initialised via hard code
{
    // Before printing, call HeapSort to restore the order property of the heap
    items.HeapSort( items.elements,  numItems);
    cout << "[--Patients Waiting--]" << endl;
    if (IsEmpty()) //If the queue is empty displays the message
    {
        cout << "No one is in the queue!" << endl;
    }
    else
    {
        for (int i = numItems - 1; i >= 0 ; i--)
        //Allows to iterate down through the array rather then up to display 5 ---> 1 rather then 1 -- > 5
        {
            cout << "[" << items.elements[i].priority << "] " << items.elements[i].name << endl;
        }
    }
}