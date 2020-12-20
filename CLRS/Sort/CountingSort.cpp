#include <iostream>
#include <ctime>
// counting sort, array is the array to be sorted, N is the number of elements,
// min stands for the minimum number in array, max stands for the max number in array.
// 复杂度是O(n+k),k表示了数字范围是从0到k-1
void CountingSort(int array[], int N, int min, int max)
{
    // build up a countArray of size K to store the value of array
    const int K = max - min + 1;
    // initialize countArray to 0
    int countArray[K] = {0};

    // build up a output array to store the sorted value
    int outArray[N];
    // count the value of array to further initialize countArray
    for(int i=0; i<N; i++){
        countArray[array[i]-min] += 1;
    }
    // add up countArray
    for(int i=1; i<K; i++){
        countArray[i] += countArray[i-1];
    }

    for(int i=0; i<N; i++){
        outArray[countArray[array[i]-min]-1] = array[i];
        countArray[array[i]-min]--;
    }
    // write back value to array
    for(int i=0; i<N; i++){
        array[i] = outArray[i];
    }

}


int main(){
    const int N = 7;
    const int MIN = 5;
    const int MAX = 15;
    int array[N];
    srand(time(NULL));

    for(int i=0; i<N; i++){
        array[i] = rand()%(MAX-MIN+1) + MIN;
    }

    for(auto i:array)
        std::cout<< i << std::endl;

    std::cout << " this is dividing line" << std::endl;

    CountingSort(array, N, MIN, MAX);

    for(auto i:array)
        std::cout<< i << std::endl;
}

