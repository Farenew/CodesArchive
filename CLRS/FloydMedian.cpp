#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::cout;
using std::endl;

// find median of array, using Floyd's method, divide by 5
int median(const int array[], size_t size)
{
    // length of array divide by 5
    const int len = (size+4)/5;
    // build up array to store median for 5 elements
    int medianArray[len];
    // temp median value
    int median;
    // vector to store temp 5 elements
    std::vector<int> fiveElement;
    // t is used to increment medianArray index
    int t = 0;
    // go through array by 5 element
    for(int i=0;i<size;i+=5){
        // k is used to store every 5 elements, however, it may also be less than 5
        for(int k=i;k<(i+5) && k<size;k++){
            fiveElement.push_back(array[k]);
        }
        // sort vector
        std::sort(fiveElement.begin(),fiveElement.end());
        // find median of 5 element
        median = fiveElement[fiveElement.size()/2];
        // add median to medianArray
        medianArray[t] = median;
        // increment t
        t++;
        // clear vector for next 5 element
        fiveElement.clear();
    }
    // sort medianArray
    std::sort(medianArray, medianArray + len);
    return medianArray[len/2];
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// to partition array by median
void partition(int array[], size_t size, int median)
{
    int index;
    // find the index of median first
    for(int i = 0;i<size;i++){
        if(array[i] == median){
            index = i;
            break;
        }
    }
    // place median at the beginning of array
    swap(array[0], array[index]);

    // go through array to partition it with median as indicator
    int left = 1;
    int right = size-1;
    while(left < right){
        if(array[left]>median){
            swap(array[left], array[right]);
            right--;
        } else{
            left++;
        }

        if(array[right]<median){
            swap(array[right], array[left]);
            left++;
        } else{
            right--;
        }
    }
    // place median at the proper place
    swap(array[0], array[right]);
}

int select(int array[], size_t size, size_t index)
{


}
int main(){
    const int N = 3;
    srand(time(NULL));
    int array[N];
    for(int i=0; i<N; i++)
        array[i] = rand()%50;
    for(auto i:array)
        cout << i << endl;

    printf("-*---------------\n");
    auto t = median(array, N);
    cout << t << endl;
    printf("-*---------------\n");
    partition(array, N, t);
    for(auto i:array)
        cout << i << endl;
}