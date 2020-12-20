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

// MaxHeapify function, input array, array size and the index
// we want to adjust, index starts from 0
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


int main(){
    // test array
    int array[10] = {16,4,10,14,7,9,3,2,8,1};
    for(auto i:array)
        std::cout << i << std::endl;

    MaxHeapify(array, 10, 1);

    std::cout << "-----------------------" << std::endl;
    for(auto i:array)
        std::cout << i << std::endl;
}