// RandomizedSelect.cpp : Defines the entry point for the console application.
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
int RandomPartition(T array[], int left, int right)
{
	/* generate a random variable between left and right,
	* make it as pivot, then change to the left most element*/
	int R = rand() % (right - left) + left;
	T pivot = array[R];
	swap(array[left], array[R]);

	int i = left;
	for (int j = i + 1; j <= right; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(array[j], array[i]);
		}
	}
	swap(array[left], array[i]);
	return i;

}

template<typename T>
T findielement(T array[], size_t left, size_t right, int i)
{
	if (left == right)
		return array[left];

	int k = RandomPartition(array, left, right);
	auto index = k -left;
	if (index == i)
		return array[k];
	else if(index > i){
		findielement(array, left, k-1, i);
	}
	else {
		findielement(array, k+1, right, i-index-1);
	}
}
int main()
{
	const int N = 10;
	srand(3494);
	int array[N];
	for (int i = 0; i<N; i++)
		array[i] = rand() % 90;

	for (auto i : array)
		std::cout << i << std::endl;
	printf("----------------------------\n");
	int out;

	out = findielement(array, 0, N - 1,0);
	std::cout << out << std::endl;
	out = findielement(array, 0, N - 1,1);
	std::cout << out << std::endl;

	out = findielement(array, 0, N - 1, 2);
	std::cout << out << std::endl;
	out = findielement(array, 0, N - 1, 3);
	std::cout << out << std::endl;

	out = findielement(array, 0, N - 1, 4);
	std::cout << out << std::endl;
	out = findielement(array, 0, N - 1, 5);
	std::cout << out << std::endl;
	int input;
	std::cin >> input;

    return 0;
}

