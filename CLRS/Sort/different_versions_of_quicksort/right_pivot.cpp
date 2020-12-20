/* quicksort, take the right one as pivot*/
#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void swap(T *a, T *b)  // function to change two variable
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
int Partition(T array[], int left, int right)
{
    T pivot = array[right];
    int i = left-1;
    for(int j=i+1; j<right; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[right]);
    return i+1;
}

template <typename T>
void QuickSort(T array[], int left, int right)
{
    if(left<right){
        int i;
        i = Partition(array, left, right);
        QuickSort(array, left, i-1);
        QuickSort(array, i+1, right);
    }
}


int main(){
    const int N = 5;
    srand(time(NULL));
    int array[N];
    for(int i=0; i<N; i++)
        array[i] = rand()%50;
    for(auto i:array)
        cout << i << endl;
    cout << "---------------------" << endl;
    QuickSort(array, 0, N-1);
    for(auto i:array)
        cout << i << endl;

}