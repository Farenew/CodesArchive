/* Naive way to compute matrix multiplication, complexity is n cube*/
#include <iostream>
#include <ctime>

using namespace std;

/* using template, we can compute any kind of data*/
template<typename T>
T** MatrixMultiply(T **array1, T **array2, int n, int m, int l)
{
    /* new a 2d array to return*/
    T **array = new T*[n];
    for(int i=0; i<l; i++){
        array[i] = new T[l];
    }

    /* 3 loops*/
    for(int i=0; i<n; i++){
        for(int k=0; k<l; k++){

            T final_element=0;
            for(int j=0; j<m; j++){
                final_element += *(*(array1+i)+j) * *(*(array2+j)+k);
            }
            *(*(array+i)+k) = final_element;

        }
    }

    // we cannot delete the array we created, if we do that, then we lost our data
    return array;
}


int main(){
    const int N = 2;
    const int M = 3;
    const int L = 2;
    // declare new arrays
    int **array1 = new int*[N];
    for(int i=0; i<N; i++){
        array1[i] = new int[M];
    }
    int **array2 = new int*[M];
    for(int i=0; i<M; i++){
        array2[i] = new int[L];
    }

    // initialize array
    srand(time(NULL));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            *(*(array1+i)+j) = rand()%2;
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<L; j++){
            *(*(array2+i)+j) = rand()%2;
        }
    }

    // output the array
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << array1[i][j] << "\t" << ends;
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
    for(int i=0; i<M; i++){
        for(int j=0; j<L; j++){
            cout << array2[i][j] << "\t" << ends;
        }
        cout << endl;
    }

    // doing multiplication
    int **array;
    array = MatrixMultiply(array1, array2, N, M, L);
    cout << "-------------------" << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<L; j++){
            cout << *(*(array+i)+j) << "\t" << ends;
        }
        cout << endl;
    }

    // delete the data we've created
    for(int i=0; i<N; i++){
        delete[] array1[i];
    }
    delete[] array1;

    for(int i=0; i<M; i++){
        delete[] array2[i];
    }
    delete[] array2;
}