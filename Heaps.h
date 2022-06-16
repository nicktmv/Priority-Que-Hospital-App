#include <iostream>
#include "PQType.h"
using namespace std;


template<class ItemType>
struct HeapType
{
	void ReheapDown(ItemType values[], int root, int bottom);
	void ReheapUp(int root, int bottom);
	void Swap(ItemType& a, ItemType& b);

	void HeapSort(ItemType values[], int numElements);
	ItemType* elements; 						// Array to be allocated dynamically
	int numElements;


};



template<class ItemType>			   		 
void HeapSort(ItemType values[], int numElements)
// Post: The elements in the array values are sorted by key.
{
	int index;
	// Convert the array of values into a heap.
	for (index = numElements / 2 - 1; index >= 0; index--)
		ReheapDown(values, index, numElements - 1);
	// Sort the array.
	for (index = numElements - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}
}

template<class ItemType>			     
void HeapType<ItemType>::ReheapDown(ItemType values[], int root, int bottom)
// If the element is less than or equal to its parent then we are done.
// Otherwise we swap the element and its parent and repeat the reheaping
// up process with the parent.
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (values[leftChild].priority <= values[rightChild].priority)
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (values[root].priority < values[maxChild].priority)
		{
			Swap(values[root], values[maxChild]);
			ReheapDown(values, maxChild, bottom);
		}
	}
}


template<class ItemType>			    
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
	int parent;
	if (bottom > root)
	{
		parent = (bottom - 1) / 2;
		if (elements[parent].priority <= elements[bottom].priority)
		{
			Swap(elements[parent], elements[bottom]);
			ReheapUp(root, parent);
		}
	}
}
template<class ItemType>			   		 
void HeapType<ItemType>::HeapSort(ItemType values[], int numElements)
// The elements in the array values are sorted by priority.
{
	int index;
	for (index = numElements / 2 - 1; index >= 0; index--)
	{
		ReheapDown(values, index, numElements - 1);
	}
	for (index = numElements - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}
}

template<class ItemType>
inline void Swap(ItemType& item1,
	ItemType& item2)
{
	ItemType tempItem;
	tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}


template<class ItemType>
void HeapType<ItemType>::Swap(ItemType& a, ItemType& b) {
	ItemType z(a);
	a = b;
	b = z;
}




