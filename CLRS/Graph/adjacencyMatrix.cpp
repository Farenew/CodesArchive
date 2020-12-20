/* Adjacency Matrix basic operation implemation.
 * using 0 as first vertex, G.size()-1 as the last one.
 * insertVex, deleteVex, insertArc, deleteArc operations.
 * Intended for data structure homework.
 * ForenewHan 2018.1.3 at XMU
*/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void insertVex(vector<vector<int>>& Gmatrix){
    size_t len; // len is used to indicate the current number if vertex
    if(Gmatrix.size()==0){	// if Gmatrix is empty, we just add a new element
        len = 1;
        vector<int> elements(len, 0);
        Gmatrix.push_back(elements);
        return;
    }
	// if Gmatrix is not empty, we need to add a row 
	// of 0 as well as modify other rows.
    else {
        len = Gmatrix[0].size();
        vector<int> elements(len, 0);
        Gmatrix.push_back(elements);
        for (int i = 0; i < Gmatrix.size(); i++) {
            Gmatrix[i].push_back(0);
        }
    }
}
void insertArc(vector<vector<int>>& Gmatrix, int v, int w){
    if(v<Gmatrix.size())
        Gmatrix[v][w] = 1;
    return;
}

void deleteVex(vector<vector<int>>& Gmatrix, int v){
    Gmatrix.erase(Gmatrix.begin()+v);	// first erase a whole row
    for(int i=0;i<Gmatrix.size();i++){	// then erase following elements within each row
        Gmatrix[i].erase(Gmatrix[i].begin()+v);
    }
    return;
}
void deleteArc(vector<vector<int>>& Gmatrix, int v, int w){
    if(v<Gmatrix.size())
        Gmatrix[v][w] = 0;
    return;
}
int main(){
    vector<vector<int>> t;
    insertVex(t);
    insertVex(t);
    insertVex(t);
    insertVex(t);
    insertArc(t,0,2);
    deleteVex(t,1);
    deleteArc(t,0,1);
    for(auto i=t.begin();i<t.end();i++){
        for(auto j = (*i).begin(); j<(*i).end();j++){
            printf("%d\t",*j);
        }
        cout << endl;
    }
//    vector<vector<int>>  t;
//    cout << t[0].size();
}