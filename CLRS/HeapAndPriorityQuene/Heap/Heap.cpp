#include "heap.h"

heap::heap()
{
}


heap::~heap()
{
}

void heap::maxHeapify(int i, int size)
{
	int l = leftChild(i);
	int R = rightChild(i);
	int largest = i;
	if (l < size && heapElement[l] > heapElement[largest])
		largest = l;
	if (R < size && heapElement[R] > heapElement[largest])
		largest = R;
	if (largest != i) {
		change(i, largest);		// swith the largest to root, to maintain heap properity
		maxHeapify(largest, size);		// resursively use maxHeapify
	}
}


void heap::insert(int i)
{
	heapElement.push_back(i);
	heapSize++;
}

void heap::buildMaxHeap()
{
	auto size = heapSize;
	for (int i = (size-1) / 2; i >= 0; i--) {
		maxHeapify(i, heapSize);
	}
}

void heap::print()
{
	for (auto begin = heapElement.begin(); begin != heapElement.end(); begin++)
		std::cout << *begin << std::endl;
}

void heap::heapSort()
{
	int temp;
	auto size = heapSize;
	for (int i = size - 1; i > 0; i--) {
		change(0, i);	// switch two element
		maxHeapify(0, --size);		// matin heap, with only --size elements
	}
}

void heap::change(const int &index1, const int &index2)
{
	auto temp = heapElement[index1];
	heapElement[index1] = heapElement[index2];
	heapElement[index2] = temp;
}
