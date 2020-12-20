#include <iostream>
#include <ctime>
/* merge inversions, doing merge_sort as well
 * as calculate the inversions. Array is modified.
*/
using namespace std;

const int INF = 1000000;

/* function 1, merge two parts together;
 * which is the combine step in divide and conquer
 * during last step, we calculated the inversions
 */
template <typename T>
int merge(T array[], int left, int middle, int right)
{
    // left part start from left, stop at 1 over middle
    const int left_length = middle - left + 2;
    // right part start from middle +1, stop at 1 over right
    const int right_length = right - middle + 1;
    int inversions = 0;

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
        if(L[k] > R[j]){
            array[i] = R[j];
          /* if now we are not at the INF of R, we calculate the inversion
           * now that L and R are sorted already, if L is bigger than R,
           * than every number in right side of L is bigger than R, which
           * is middle - left - +1 - k*/
            if(R[j] != INF)
                inversions = inversions + (middle - left + 1 - k);
//            j++ must be later
            j++;

        }
        else{
            array[i] = L[k];
            k++;
        }
    }
    return inversions;
}

/* main part of merge_sort, start at array[left], stop at array[right] */
template<typename T>
int merge_sort(T array[], int left, int right)
{
    int inversions = 0;
    int middle = (right - left)/2 + left;
    if(left != middle) {
        inversions += merge_sort(array, left, middle);
        inversions += merge_sort(array, middle + 1, right);
    }
    inversions += merge(array, left, middle, right);
    return inversions;
}

int main(){
    const int N = 5;
    int array[N];
    srand(time(NULL));
    for(int i=0; i<N; i++){
        array[i] = rand()%20;
    }

    for(auto i:array)
        cout << i << endl;

    cout << "--------------------------" << endl;

    int inversions = merge_sort(array, 0, N-1);

    for(auto i:array)
        cout << i << endl;

    cout << "the inversion is " << inversions << endl;
}