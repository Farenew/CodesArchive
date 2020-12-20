/* Adjacency list basic operation implemation.
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

void insertVex(vector<vector<int>>& Glist)
{
    vector<int> newVex;
    Glist.push_back(newVex);
}
void insertArc(vector<vector<int>>& Glist, int v, int w)
{
    if(v < Glist.size()){
        Glist[v].push_back(w);
    }
}
void deleteVex(vector<vector<int>>& Glist, int v)
{
    Glist.erase(Glist.begin()+v);
    for(int i=0;i<Glist.size();i++){
        for(int j=0;j<Glist[i].size();j++){
            if(Glist[i][j]==v)
                Glist[i].erase(Glist[i].begin()+j);
        }
    }
}
void deleteArc(vector<vector<int>>& Glist, int v, int w)
{
    if(v < Glist.size()){
        for(int i=0;i<Glist[v].size();i++){
            if(Glist[v][i] == w){
                Glist[v].erase(Glist[v].begin()+i);
                return;
            }
        }
    }
}
int main(){
    vector<vector<int>> t;
    insertVex(t);
    insertVex(t);
    insertVex(t);
    insertArc(t,0,1);
    insertArc(t,0,2);
    insertArc(t,1,0);
    insertArc(t,1,2);
    insertArc(t,2,1);
    //deleteVex(t,0);
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