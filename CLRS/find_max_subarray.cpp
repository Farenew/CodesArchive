#include <iostream>
#include <ctime>

using namespace std;

/* define a structure multipair to store all the information to return*/
typedef struct multipair{
    int L;
    int R;
    int S;
}multipair;

const int INF_SMALL = -10000000;

/* find the max subarray which lies across the midpoint*/
multipair find_crossing_max_subarray(int array[], int left, int right, int middle)
{
    int sum = INF_SMALL;
    multipair return_data;
    for(int i=middle, temp_sum = 0 ; i>=left; i--){
        temp_sum += array[i];
        /* this must be >=, if = is ignored, then we cannot record return_data.L and sum */
        if(temp_sum >= sum) {
            sum = temp_sum;
            return_data.L = i;
        }
    }
    return_data.S = sum;

    sum = INF_SMALL;
    for(int i=middle+1, temp_sum = 0 ; i<=right; i++){
        temp_sum += array[i];
        if(temp_sum >= sum) {
            sum = temp_sum;
            return_data.R = i;
        }
    }
    return_data.S += sum;
    return return_data;
}

multipair find_max_subarray(int array[], int left, int right)
{
    multipair left_max;
    multipair right_max;

    int middle = (right + left)/2;
    if(middle != left){
        left_max = find_max_subarray(array, left, middle);
        right_max = find_max_subarray(array, middle+1, right);
    }
        /* if we are at the end of recursion, the we must at a point left = right or left + 1 = right,
         * at when we should assign the value on our own*/
    else{
        left_max.L = left;
        left_max.R = left;
        left_max.S = array[left];
        right_max.L = right;
        right_max.R = right;
        right_max.S = array[right];
    }
    multipair middle_max = find_crossing_max_subarray(array, left, right, middle);

    /* comparing step */
    if(middle_max.S > left_max.S){
        if(middle_max.S > right_max.S)
            return middle_max;
        else
            return right_max;
    }
    else if(left_max.S > right_max.S)
        return left_max;
    else
        return right_max;
}

int main(){
    const int N = 16;
    int array[N];
    srand(time(NULL));

    for(int i=0; i<N; i++){
        array[i] = rand()%20 - 19;
    }

//    array[7] = 0;

    for(auto i:array)
        cout << i << endl;

    multipair subarray_max = find_max_subarray(array, 0, 15);
    printf("the subarray max is < %d, %d>, sum is %d\n", subarray_max.L, subarray_max.R, subarray_max.S);
}