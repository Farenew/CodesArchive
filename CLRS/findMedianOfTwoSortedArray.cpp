/*
 * find the median of two sorted array in lgN time.

*/

#include <iostream>
#include <ctime>
#include <algorithm>

using std::cout;
using std::endl;

int twoMedian(int array1[], size_t l1, size_t r1,
              int array2[], size_t l2, size_t r2)
{
	// len1 is always equal to len2
    auto len1 = r1 - l1 + 1;
    auto len2 = r2 - l2 + 1;

	// if len is 1, then just return, in our case, we always return the right element(median of bigger one)
    if(len1 == 1) {
        if (array1[l1] > array2[l2])
            return array1[l1];
        else
            return array2[l2];
    }
	// if len is 2, then modify it to len 1
    if(len1 == 2){
        if(array1[l1 + len1/2] > array2[l2 + len2/2])
            twoMedian(array1, l1, l1, array2, r2, r2);
        else
            twoMedian(array1, r1, r1, array2, l2, l2);
    }
	// if len is greater than 2, find median recursively.
    else{
        if(array1[l1 + len1/2] > array2[l2 + len2/2])
            return twoMedian(array1, l1, len1/2 + l1, array2, r2 - len2/2, r2);
        else
            return twoMedian(array1, r1 - len1/2, r1, array2, l2, l2 + len2/2);
    }
}

int main(){
    const int N = 5;
    srand(time(NULL));
    int array1[N];
    int array2[N];
    for(int i=0; i<N; i++)
        array1[i] = rand()%50;

    srand(1235);
    for(int i=0; i<N; i++)
        array2[i] = rand()%50;

    std::sort(array1, array1+N);
    std::sort(array2, array2+N);

    for(auto i:array1)
        cout << i << endl;
    cout << "---------------------" << endl;
    for(auto i:array2)
        cout << i << endl;
    cout << "---------------------" << endl;

    cout << twoMedian(array1, 0, N-1, array2, 0, N-1);
}
