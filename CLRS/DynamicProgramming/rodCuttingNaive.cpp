/* rod cutting problem naive solution
 * bestCut is naive recursive solution, bestCutMemo is naive recursive solution with where to cut.
 * printBestCut is called after bestCutMemo, records at each length, how we cut.
 * ForenewHan 2018.1.11 at XMU
 */
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::vector;

// naive method for rod cutting problem, len is the length for rod, prize[i] indicates prize at length
int bestCut(int prize[], const int len)
{
    // if length is 0, return 0
    if(len == 0)
        return 0;
    else{
        // value the value to return, at start it is 0
        int value = 0;
        // from cut at 1 to cut at len(which means no cut), find the best prize
        for(int i=1;i<=len;i++){
            // best value is the max value between last best choice and new cut method
            value = max(value, prize[i] + bestCut(prize, len-i));
        }
        return value;
    }
}

// naive method for rod cutting problem with memo for how we cut
// memo is an array, memo[i] indicates best cut at length i.
int bestCutMemo(int prize[], int memo[], const int len)
{
    // if length is 0, return 0
    if(len == 0)
        return 0;
    else{
        // value the value to return, at start it is 0
        int value = 0;
        // q records the last cut value, indicates if value is changed or not, if changed,
        // which means we've come to a better cut, then record this better cut.
        int q = 0;
        for(int i=1;i<=len;i++){
            value = max(value, prize[i] + bestCutMemo(prize, memo, len-i));
            // if cut is better than last cut, record it
            if(q != value){
                memo[len] = i;
            }
            // q is the last best cut
            q = value;
        }
        return value;
    }
}

// the function to print the best cut, bestLenCut[i] means at length i, where we cut
void printBestCut(int bestLenCut[], int N)
{
    // i is indicating var, indicates length.
    int i = N;

    // cutAlready means how much we've cut, at start, we cut nothing
    int cutAlready = 0;

    // if we have not cut till end, then keep cutting
    while(cutAlready != N){
        // add to how much we've cut
        cutAlready += bestLenCut[i];
        // print out where we've cut
        printf("cut %d\n", cutAlready);
        // reduce the length, change to next length to cut
        i = N - cutAlready;
    }
}
int main(){
    const int N = 5;
    const int arrayLen = N + 1;
    // different prize for different length of rod, for example, length 10: prize[30];
    //int prize[] = {0,1,5,8,9,10,17,17,20,24,30};

    int prize[] = {0,1,50,8,9,10};


    int bestLenCut[arrayLen] = {0};    // best length for every cut, bestLenCut[5] stands for length 5 best cut.

    cout << bestCutMemo(prize, bestLenCut, N) << endl;

    printf("\n----------------------------\n");
    for(int i=0;i<arrayLen;i++)
        printf("%d len best cut is %d\n", i, bestLenCut[i]);

    printBestCut(bestLenCut, N);

}