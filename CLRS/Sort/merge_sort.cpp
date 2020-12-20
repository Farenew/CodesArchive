#include <iostream>
#include <ctime>

using namespace std;

const int INF = 1000000;

/* function 1, merge two parts together;
 * which is the combine step in divide and conquer
 */
template <typename T>
void merge(T array[], int left, int middle, int right)
{
    // left part start from left, stop at 1 over middle
    const int left_length = middle - left + 2;
    // right part start from middle +1, stop at 1 over right
    const int right_length = right - middle + 1;

    T L[left_length];
    int i, j=0;
    for(i = left; i<=middle; i++){
        L[j] = array[i];
        j++;
    }
    L[j] = INF;

    T R[right_length];
    j = 0;
    for(i = middle+1; i<=right; i++){
        R[j] = array[i];
        j++;
    }
    R[j] = INF;

    int k=0;
    j=0;
    for(i = left; i<=right; i++){
        if(L[k] < R[j]){
            array[i] = L[k];
            k++;
        }
        else{
            array[i] = R[j];
            j++;
        }
    }
}

/* main part of merge_sort, start at array[left], stop at array[right] */
template<typename T>
void merge_sort(T array[], int left, int right)
{
    int middle = (right - left)/2 + left;
    if(left != middle) {
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
    }
    merge(array, left, middle, right);

}

int main(){
    const int N = 20;
    int array[N];
    srand(time(NULL));
    for(int i=0; i<N; i++){
        array[i] = rand()%20;
    }

    for(auto i:array)
        cout << i << endl;

    cout << "--------------------------" << endl;

    merge_sort(array, 0, N-1);

    for(auto i:array)
        cout << i << endl;
}