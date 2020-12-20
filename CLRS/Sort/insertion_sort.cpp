#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

template <size_t SIZE> // define function template, so we can pass different size of array
void insertion_sort(array<int, SIZE>& arr, const int size) {
    int key;
    int i;
    for (int j = 1; j < size; j++){
        key = arr[j];
        i = j-1;
        while(i>=0 && key<arr[i]){    // insertion
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int main(){
    array<int, 10> array1;
    srand(time(NULL));

    for(int i=0; i<10; i++)
        array1[i] = rand()%20;     // generate some random numbers to test
    for(auto e:array1)
        cout << e << endl;

    insertion_sort(array1,10);    // doing insertion sort

    cout << "after sorting" << endl;
    for(auto e:array1)
        cout << e << endl;

    return 0;

}
