// HoareQuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
int HoarePartition(T array[], size_t left, size_t right) {
	auto key = array[left];
	size_t i = left ;
	size_t j = right;

	while (1) {
		while(array[j] > key)
			j = j - 1;

		while(array[i] < key)
			i = i + 1;

		if (i < j)
			swap(array[i], array[j]);
		else
			return j;
	}
}

template <typename T>
void QuickSort(T array[], int left, int right)
{
	if (left<right) {
		int i;
		i = HoarePartition(array, left, right);
		QuickSort(array, left, i - 1);
		QuickSort(array, i + 1, right);
	}
}

using std::cout;
using std::endl;

int main()
{
	const int N = 12;
	    //srand(123);
	    //int array[N];
	    //for(int i=0; i<N; i++)
	    //    array[i] = rand()%50;

	int array[N] = { 13,19,9,5,12,8,7,4,11,2,6,21 };
	for (auto i : array)
		cout << i << endl;
	cout << "---------------------" << endl;
	//QuickSort(array, 0, N - 1);
	printf("j = %d", HoarePartition(array, 0, N - 1));
	for (auto i : array)
		cout << i << endl;



	int test;
	std::cin >> test;
    return 0;
}

