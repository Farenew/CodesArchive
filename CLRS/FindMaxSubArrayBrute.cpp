#include <iostream>
#include <ctime>

using namespace std;

typedef struct multipair{
    int L;
    int R;
    int S;
}multipair;

const int INF_SMALL = -10000000;

multipair FindMaxSubArrayBrute(int array[], int left, int right)
{
    multipair return_data;
    return_data.S = INF_SMALL;
    /* brute method to find the max subarray,
     * doing a loop for a double time*/
    for(int i=left, temp_sum; i<=right; i++){
        temp_sum = array[i];
        for(int j=i+1; j<=right; j++){
            temp_sum += array[j];
            if(temp_sum >= return_data.S){
                return_data.S = temp_sum;
                return_data.L = i;
                return_data.R = j;
            }
        }
    }

    return return_data;
}

int main(){
    int array[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    multipair data = FindMaxSubArrayBrute(array, 0, 15);
    printf("the subarray max is < %d, %d>, sum is %d\n", data.L, data.R, data.S);
}