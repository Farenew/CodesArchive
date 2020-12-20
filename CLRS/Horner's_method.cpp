#include <iostream>
#include <array>
#include <cmath>
using namespace std;

const int arr_size = 100;

template<size_t SIZE, typename T>                       // naive way to calculate polynomial expression
long double polynomial_cal_naive(array<T,SIZE>& a, int size, int x)     // a is coefficient
{
    double answer = 0;
    for(int i=0; i<size; i++){
        answer =  answer+ a[i] * pow(x, i);
    }
    return answer;
}

template<size_t SIZE, typename T>                       // using Horner's way to calculate polynomial expression
long double polynominal_cal_horner(array<T,SIZE>& a, int size, int x)   // a is coefficient
{
    double answer = 0;
    for(int i=size-1; i>=0; i--){
        answer = answer * x + a[i];
    }
    return answer;
}

int main(){
    array<double, arr_size> arr;
    srand(time(NULL));

    for(int i=0; i<arr_size; i++){
        arr[i] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX)/(13)) + (-6);
    }

    cout << "coefficients are; " << endl;
    for(auto a: arr) {
        cout << a << endl;
    }

    cout << "naive method: " << polynomial_cal_naive(arr, arr_size, 7) << endl;

    cout << "Horner method: " << polynominal_cal_horner(arr, arr_size, 7) << endl;

    return 0;

}
