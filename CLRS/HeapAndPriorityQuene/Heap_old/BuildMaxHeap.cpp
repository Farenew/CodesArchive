#include <iostream>
#include <ctime>
#include <algorithm>
#include <bitset>

// return the leftChild node, since we start our array from 0
// so here leftChild is index*2+1 rather than index*2
int leftChild(int index)
{
    return index*2+1;
}
// return the rightChild node
int rightChild(int index)
{
    return index*2+2;
}

template <typename T>
void MaxHeapify(T array[], int N, int index)
{
    // find the leftChild and rightChild
    int L = leftChild(index);
    int R = rightChild(index);

    // set temporary maxIndex as index
    int maxIndex = index;
    // compare leftChild and rightChild, to find out the biggest one
    if(array[L]>array[maxIndex] && L<N)
        maxIndex = L;
    if(array[R]>array[maxIndex] && R<N)
        maxIndex = R;

    // if index is maxIndex, we are done, return.
    if(maxIndex == index)
        return;
        // else, exchange array[index] and array[maxIndex]
    else{
        T temp = array[index];
        array[index] = array[maxIndex];
        array[maxIndex] = temp;
    }
    // recursively do maxHeapify
    MaxHeapify(array, N, maxIndex);
}

// build up a max heap from input array and write it back
template <typename T>
void buildMaxHeap(T array[], int N)
{
    for(int i=(N-1)/2;i>=0;i--){
        MaxHeapify(array, N, i);
    }
}

int main(){

    const int N = 9;
    const int MIN = 5;
    const int MAX = 15;
    int array[N];
    srand(time(NULL));

    for(int i=0; i<N; i++){
        array[i] = rand()%(MAX-MIN+1) + MIN;
    }

    for(auto i:array)
        std::cout<< i << std::endl;

    buildMaxHeap(array, N);

    std::cout << "-----------------------" << std::endl;
    for(auto i:array)
        std::cout << i << std::endl;
}