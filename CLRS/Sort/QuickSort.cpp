/* QuickSort, using the most left element as pivot
 *
 */

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

/* partition step, using pivot to partition array into two subarrays,
 * such that left subarray is less than pivot, while the right one is bigger*/
template <typename T>
int Partition(T array[], int left, int right)
{
    T pivot = array[left];
    int i = left;
    for(int j=i+1; j<=right; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i], &array[left]); // move pivot into the place we are at
    return i;
}

/* main content of quicksort, using recurrence*/
template <typename T>
void QuickSort(T array[], int left, int right)
{
    if(left < right){
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