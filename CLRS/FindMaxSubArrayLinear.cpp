/* using Kadane's algorithm
 *
 *
 */
#include <iostream>
#include <ctime>

using namespace std;

/* define a return type */
typedef struct multi{
    int L;
    int R;
    int sum;
}multi;

/* find max subarray in linear time */
multi FindMaxSubArrayLinear(int array[], int left, int right)
{
    multi data;
    int temp_left, temp_right;
    /*initialize*/
    data.sum = array[left];
    data.L = left;
    data.R = left;
    int temp_sum = data.sum;

    for(int i=left+1; i<=right; i++){
        /* if array[i] is distinct larger, then mark it as starting point of subarray*/
        if(array[i] > (array[i] + temp_sum)){
            temp_left = i;
            temp_right = i;
            temp_sum = array[i];
        }
            /* else, continue looping, temporary update temp_right*/
        else{
            temp_sum += array[i];
            temp_right = i;
        }

        /* when temp_sum is bigger, update the data */
        if(temp_sum > data.sum){
            data.sum = temp_sum;
            data.R = temp_right;
            data.L = temp_left;
        }
    }
    return data;
}


int main(){
    const int N = 16;

    int array[N]={13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

//    srand(time(NULL));
//
//    for(int i=0; i<N; i++){
//        array[i] = rand()%20 - 19;
//    }

    for(auto i:array)
        cout << i << endl;

    cout << "----------------------------" << endl;

    multi data = FindMaxSubArrayLinear(array,0, N-1);

    printf("<%d %d> is %d\n", data.L, data.R, data.sum);
}