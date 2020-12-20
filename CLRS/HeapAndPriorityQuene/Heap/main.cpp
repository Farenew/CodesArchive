#include "heap.h"
#include "priorityQuene.h"

int main()
{
	priorityQuene h1;
	/*srand(123);
	for (int i = 0; i < 4; i++) {
		h1.insert(rand() % 20);
	}*/

	// int ar[] = { 4,1,3,2,16,9,10,14,8,7 };
	int ar[] = { 16,14,10,8,7,9,3,2,4,1 };
	for (int i = 0; i < 10; i++)
		h1.insert(ar[i]);


	h1.print();
	printf("--------------\n");
	h1.buildMaxHeap();
	h1.print();
	printf("--------------\n");
	h1.print();
	

	int test;
	std::cin >> test;
	return 0;
}
