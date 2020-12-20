#include <iostream>
#include <array>
#include <ctime>

using namespace std;

const int arr_size = 10;

template<size_t SIZE>
void bubble_sort(array<int,SIZE>& arr, const int size)
{
    for(int i=0; i<size; i++){
        for(int j=size; j>i; j--){
            if(arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
int main(){

    array<int, arr_size> arr;
    srand(time(NULL));
    for(int i=0; i<arr_size; i++){
        arr[i] = rand()%20;
    }

    for(auto a: arr) {
        cout << a << endl;
    }

    cout << "after sort" << endl;
    bubble_sort(arr, arr_size);

    for(auto a: arr) {
        cout << a << endl;
    }

    return 0;

}
