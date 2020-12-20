#include <iostream>
#include <ctime>
#include <algorithm>
#include <bitset>

// this is the count sort by digits, say that we use CountingByDigits(array, 5, 1, 3),
// we are sorting be bit 1 to bit 3, bit 3 included.
void CountingByDigits(int array[],const int N, const int startDigit, const int lastDigit)
{
    // this is the digits count
    const int digit = lastDigit - startDigit + 1;
    // k is the count number, if 3 digits, than there are 8 numbers
    const int k = 1 << digit;
    // rightShift is used to reduce the number, since after comparing, we have to take elem to proper place
    // without rightShift, than elem would be bigger than array size, which causes overflow
    const int rightShift = (startDigit-1);

    // initialize countArray to 0
    int countArray[k] = {0};

    // build up a output array to store the sorted value
    int outArray[N];

    // mask is used to mask out digits we don't need for present
    int mask = 1 << (startDigit-1);
    for(int i = startDigit; i<lastDigit; i++){
        mask |= mask << 1;
    }


    // count the value of array to further initialize countArray
    for(int i=0; i<N; i++){
        // remember to use bracket, since >> is higher than &
        countArray[(array[i]&mask) >> rightShift] += 1;
    }

    // add up countArray
    for(int i=1; i<k; i++){
        countArray[i] += countArray[i-1];
    }


    for(int i=N-1; i>=0; i--){
        outArray[countArray[(array[i]&mask) >> rightShift]-1] = array[i];
        countArray[ (array[i]&mask) >> rightShift]--;
    }

    // write back value to array
    for(int i=0; i<N; i++){
        array[i] = outArray[i];
    }

}


int main(){
    const int N = 10;
    const int MIN = 0;
    const int MAX = 512;
    int array[N];
    srand(time(NULL));

    for(int i=0; i<N; i++){
        array[i] = rand()%(MAX-MIN+1) + MIN;
    }

    for(auto i:array)
        std::cout<< i << "\t\t" << std::bitset<6>(i) << std::endl;




    std::cout << " this is dividing line" << std::endl;


    // using 3 as counting division digit
    CountingByDigits(array, N, 1, 3);
    CountingByDigits(array, N, 4, 6);
    CountingByDigits(array, N, 7, 9);

    for(int i=0; i<N; i++)
        printf("%d\n", array[i]);

}