/* random quicksort, only need slightly tuning raw quicksort,
 * swap the pivot with the left most element*/
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
int RandomPartition(T array[], int left, int right)
{
    /* generate a random variable between left and right,
     * make it as pivot, then change to the left most element*/
    int R = rand()%(right-left) + left;
    T pivot = array[R];
    swap(&array[left], &array[R]);

    int i = left;
    for(int j = i+1; j<=right; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[left], &array[i]);
    return i;

}


template <typename T>
void QuickSort(T array[], int left, int right)
{
    if(left<right){
        int i;
        i = RandomPartition(array, left, right);
        QuickSort(array, left, i-1);
        QuickSort(array, i+1, right);
    }
}


int main(){
    const int N = 10;
    srand(time(NULL));
    int array[N];
    for(int i=0; i<N; i++)
        array[i] = rand()%20;

//    int array[N] = {19,19,10,0,11};
    for(auto i:array)
        cout << i << endl;
    cout << "---------------------" << endl;
    QuickSort(array, 0, N-1);
    for(auto i:array)
        cout << i << endl;

}