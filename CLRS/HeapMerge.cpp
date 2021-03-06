// HeapMerge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using std::vector;

// define myCompare function, to initialize a min priority queue
class myCompar {
public:
	int operator() (const std::pair<int, int>& a, std::pair<int, int>& b)
	{
		return a.first > b.first;
	}
};

int main() {
	srand(123);		// set random seed
	const int eleNum = 10;		// element number for each vector, actually it can be different length for different vector
	const int k = 10;		// number of list

	vector<int> finalArray;		// final array to output

	std::priority_queue<std::pair<int,int>, vector<std::pair<int, int>>, myCompar> q;		// min priority queue to store k elements. using pair type to track the element
	
	vector<vector<std::pair<int,int>>> vt2d;		// 2d vector, to store all elements
	vector<std::pair<int, int>> temp;		// temp vector, to store a list every time.
	// initialize every list
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < eleNum; j++) {
			auto ele = std::make_pair(rand() % 160, i + 1);
			temp.push_back(ele);
		}
		vt2d.push_back(temp);
		temp.clear();		// after input value, clear temp for next use
	}

	// sort every list
	for (auto start = vt2d.begin(); start != vt2d.end(); start++) {
		std::sort(start->begin(), start->end());
	}

	// print out all n elements with the place it from(1 to k)
	for (auto start = vt2d.begin(); start != vt2d.end(); start++) {
		for (auto instrt = start->begin(); instrt != start->end(); instrt++) {
			std::cout << instrt->first << "\t";
		}
		printf("\n------------------------\n");
		for (auto instrt = start->begin(); instrt != start->end(); instrt++) {
			std::cout << instrt->second << "\t";
		}
		printf("\n******************************\n");
	}

	// build initial heap with k head elements
	auto p = vt2d.begin();
	for (int i = 0; i < k; i++) {
		q.push(*(p->begin()));
		p->erase(p->begin());
		p++;
	}

	// while q is not empty, push elements
	while (!q.empty()) {
		std::pair<int, int> temp = q.top();
		int i = temp.second;		// i indicates where the element comes from
		finalArray.push_back(temp.first);		// here we only need to obtain first element, track is no longer needed
		q.pop();		// delete top

		if (!vt2d[i - 1].empty()) {		// if vector is not empty, find another element to fill 
			q.push(*(vt2d[i - 1].begin()));		// NOTE, the syntax here
			vt2d[i - 1].erase(vt2d[i - 1].begin());
		}

	}

	// print out final array merged
	printf("FINAL\n");
	for (auto a = finalArray.begin(); a != finalArray.end(); a++) {
		std::cout << *a << "\t";
	}
	printf("OVER\n");
	printf("length %d\n", finalArray.size());


	int test;
	std::cin >> test;
}