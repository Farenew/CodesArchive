#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>

using std::string;

void get_next(string s){
    const int size = s.size();
    int i=0;
    int array[size];
    array[0] = -1;
    int j = -1;
    while(i<=s.size()){
        if(j == -1 || s[i] == s[j]){
            j++;
            i++;
            array[i] = j;

        }
        else
            j = array[j];
    }

    for(auto t:array)
        std::cout << t+1 << " ";
}

void get_next_2(string s){
    const int size = s.size();
    int i=0;
    int array[size];
    array[0] = -1;
    int j = -1;
    while(i<=s.size()){
        if(j == -1 || s[i] == s[j]){
            j++;
            i++;
            if(s[i]!=s[j])
                array[i]=j;
            else
                array[i]=array[j];

        }
        else
            j = array[j];
    }

    for(auto t:array)
        std::cout << t+1 << " ";
}
int main(){
    string t = "abcaacabaca";
    get_next(t);
    std::cout << std::endl << "---------------------------" << std::endl;
    get_next_2(t);
}