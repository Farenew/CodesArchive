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

// MaxHeapify function using loop, input array, array size and the index
// we want to adjust, index starts from 0
template <typename T>
void MaxHeapify(T array[], int N, int index)
{
    // using id as index
    int id = index;

    while(id < N){
        // find the leftChild and rightChild
        int L = leftChild(id);
        int R = rightChild(id);

        // set the temp maxIndex
        int maxIndex = id;
        // compare and find the maxIndex
        if(array[L]>array[maxIndex] && L<N)
            maxIndex = L;
        if(array[R]>array[maxIndex] && R<N)
            maxIndex = R;
        if(maxIndex == id)
            return;
        else{
            T temp = array[id];
            array[id] = array[maxIndex];
            array[maxIndex] = temp;
        }
        // refresh id
        id = maxIndex;
    }

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