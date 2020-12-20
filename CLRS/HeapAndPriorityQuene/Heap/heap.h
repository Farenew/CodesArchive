#pragma once
#include <vector>
#include <iostream>
class heap
{
public:
	heap();
	~heap();

	void maxHeapify(int i, int size);	// adjust heap with ith element not satisfy max_heap, from this element till leaf
	void insert(int i);		// insert an element into heap
	void buildMaxHeap();	// adjust element in heap, to make it a heap
	void print();		// print all elements in heap
	void heapSort();	// if it is a heap, then it would be sorted

	int &operator[](const size_t index) { return heapElement[index-1]; }	// overload subscript operator, two version for const and non const
	const int &operator[](const size_t index) const { return heapElement[index-1]; }	

protected:

	std::vector<int> heapElement;	// vector to store heap element
	int heapSize = 0;		// heap size

	inline int parent(const int i) const { return (i - 1) / 2; }	// return parent element
	inline int leftChild(const int i) const { return 2 * i + 1; }	// return leftchild
	inline int rightChild(const int i) const { return (i + 1) * 2; }	// return rightchild
	void change(const int &index1, const int &index2);		// change function changes the relative order of two element noted by their index
};

