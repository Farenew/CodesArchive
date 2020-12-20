#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int RandomPartition(T array[], int left, int right)
{
    /* generate a random variable between left and right,
    * make it as pivot, then change to the left most element*/
    int R = rand() % (right - left) + left;
    T pivot = array[R];
    swap(array[left], array[R]);

    int i = left;
    for (int j = i + 1; j <= right; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[j], array[i]);
        }
    }
    swap(array[left], array[i]);
    return i;

}

template<typename T>
T findiElement(T array[], int left, int right, int i)
{
    if(left == right)
        return array[left];

    int k = RandomPartition(array, left, right);
    int index = k - left;
    while(i != index){
        if(i < index){
            k = RandomPartition(array, left, k-1);
            index = k - left;
        }
        else{
            k = RandomPartition(array, k+1, right);
            index = k- left;
        }
    }
    return array[index];
}

int main() {
    const int N = 10;
    srand(3494);
    int array[N];
    for (int i = 0; i<N; i++)
        array[i] = rand() % 90;

    for (auto i : array)
        std::cout << i << std::endl;
    printf("----------------------------\n");


    int out;
    out = findiElement(array, 0, N - 1,0);
    std::cout << out << std::endl;
    out = findiElement(array, 0, N - 1,1);
    std::cout << out << std::endl;

    out = findiElement(array, 0, N - 1, 2);
    std::cout << out << std::endl;
    out = findiElement(array, 0, N - 1, 3);
    std::cout << out << std::endl;

    out = findiElement(array, 0, N - 1, 4);
    std::cout << out << std::endl;
    out = findiElement(array, 0, N - 1, 5);
    std::cout << out << std::endl;

}