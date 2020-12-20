
#include "priorityQuene.h"


priorityQuene::priorityQuene()
{
}


priorityQuene::~priorityQuene()
{
}

int priorityQuene::heapExtractMax()
{
	if (heapSize < 1) {			// if heap size is less than 1, then error
		printf("heap is empty!\n");
		return 0;
	}
	auto max = heapElement[0];		// the max element to return
	heapSize--;		// decrease the heap size
	change(0, heapSize);		// switch the last element with the first one
	maxHeapify(0, heapSize);	// adjust heap to maintain it's property

	heapElement.erase(heapElement.end()-1);		// delete last element in heap
	return max;
	
}
void priorityQuene::heapIncreaseKey(size_t index, int key)
{
	if (key < heapElement[index]) {		// if the element increased is less than initial element, then error
		printf("The key is too small!\n");
		return;
	}
	heapElement[index] = key;		// fresh the element
	while (index>=0 && heapElement[index] > heapElement[parent(index)]) {		// if element is bigger than it's parent, do switch until it's fine
		auto prt = parent(index);
		change(prt, index);
		index = prt;
	}
}

void priorityQuene::maxHeapInsert(int key)		
{
	heapSize++;		// increase heapsize
	heapElement.push_back(key - 1);		// add a new element, in order to do later increase, here we initialize the push_back element as key-1
	heapIncreaseKey(heapSize - 1, key);		// increase key, and using heapIncreaseKey function to maintain heap properity
}