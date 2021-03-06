// EqualElementPartition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template <typename T>
void swap(T &a, T &b)  // function to change two variable
{
	auto temp = a;
	a = b;
	b = temp;
}

template<typename T>
std::pair<int,int> Partition(T array[], int left, int right)
{
	// i-1 is always the element less or equal than pivot, k-1 is always the element less than pivot
	T pivot = array[left];
	int i = right + 1;
	int k = right + 1;
	for (int j = i - 1; j>left; j--) {			// in this for loop, it looks as if pivot elements are pushed by i
		if (array[j] > pivot) {
			i--;
			k--;
			swap(array[i], array[j]);
			if(i!=k)			// if i!=k, we have to swap array[k] and array[j] to make sure pivot element are just ahead of i
				swap(array[k], array[j]);
		}
		if (k!=j && array[j] == pivot) {		// if k reached j, there is no need to just, just skip and let j continue
			k--;
			swap(array[k], array[j]);
		}
	}
	
	swap(array[left], array[k - 1]);
	return std::make_pair(k-1, i - 1);
}


template <typename T>
void QuickSort(T array[], int left, int right)
{
	if (left < right) {
		std::pair<int, int> i;
		i = Partition(array, left, right);
		QuickSort(array, left, i.first - 1 );
		QuickSort(array, i.second +1 , right);
	}
}


int main()
{
	int const N = 90;
	srand(487);
	int array[N];
	for (int i = 0; i < N; i++)
		array[i] = rand() % 20;

	for (auto i : array)
		std::cout << i << std::endl;

	printf("--------------------\n");
	QuickSort(array, 0, N - 1);

	for (auto i : array)
		std::cout << i << std::endl;

	int test;
	std::cin >> test;
    return 0;
}

