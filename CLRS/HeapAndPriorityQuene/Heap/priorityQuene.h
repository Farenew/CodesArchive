#pragma once
#include "heap.h"
// max priority quene, inherentd from heap
class priorityQuene: public heap
{
public:
	priorityQuene();
	~priorityQuene();
	inline int heapMaximum() const { return heapElement[0]; }		// return max element in heap
	int heapExtractMax();		// return max element in heap and delete it from heap
	void heapIncreaseKey(size_t index, int key);	// increase index element to key
	void maxHeapInsert(int key);		// insert a new element to heap and maintain it's property
};

