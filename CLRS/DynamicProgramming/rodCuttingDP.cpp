/* rod cutting problem DP solution
 * two version, one is bottom up the other is top down
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

// dynamic programming for rod cutting, top down method, memorize every best value to reduce time
// bestCutPrize is best prize, for example, bestCutPrize[5] means at length 5, best value we can get
int DPbestCutTopDown(int prize[], int bestCutPrize[], const int len)
{
    // if length is 0, return 0
    if(len == 0)
        return 0;
    else{
        // value the value to return, at start it is 0
        int value = 0;
        // from cut at 1 to cut at len(which means no cut), find the best prize
        for(int i=1;i<=len;i++){
            // -1 means it has not been calculated before, so we do calculation.
            if(bestCutPrize[len-i] == -1)
                bestCutPrize[len-i] = DPbestCutTopDown(prize, bestCutPrize, len-i);
            // best value is the max value between last best choice and new cut
            value = max(value, prize[i] + bestCutPrize[len-i]);
        }
        return value;
    }
}

// dynamic programming for rod cutting in bottom up method.
// bestCutPrize is best prize, for example, bestCutPrize[5] means at length 5, best value we can get
int DPbestCutBottomUp(int prize[], int bestCutPrize[], const int len)
{
    // first of all, initialize bestCutPrize[0] to 0, means no length, no prize
    bestCutPrize[0] = 0;
    // value the current best value cut prize
    int value=0;
    // from length 1 to len, find out best cut prize for each
    for(int i=1;i<=len;i++){
        // every loop, initialize value to 0
        value = 0;
        // find all cut combination for current length, from 1 to current i
        for(int j=1;j<=i;j++){
            value = max(value, prize[j]+bestCutPrize[i-j]);
        }
        // at length i, best prize is no cut at all(prize[i]) or with calculated cut(value)
        bestCutPrize[i] = max(prize[i], value);
    }
    return bestCutPrize[len];
}

int main(){
    const int N = 4000; // N stands the length for rod
    const int arrayLen = N + 1;

    // different prize for different length of rod, for example, length 10: prize[30];
    // int prize[] = {0,1,5,8,9,10,17,17,20,24,30};

    int prize[N+1];
    prize[0] = 0;
    srand(59995);
    for(int i=1;i<N+1;i++){
        prize[i] = prize[i-1] + rand()%5;
    }


   // int bestLenCut[arrayLen] = {0};    // best length for every cut, bestLenCut[5] stands for length 5 best cut.
    int bestCutPrize[N+1];     // initialize bestCut as -1, -1 means it has not been initialized before
    std::fill_n(bestCutPrize, N, -1);

    cout << DPbestCutTopDown(prize, bestCutPrize, N) << endl;

    cout << DPbestCutBottomUp(prize, bestCutPrize, N) << endl;
}