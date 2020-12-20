/* BFS implemation
 * using 0 as first vertex, G.size()-1 as the last one.
 * insertVex, deleteVex, insertArc, deleteArc BFS operations.
 * ------------------------------------------------
 * algorithm from CLRS
 * ------------------------------------------------
 * The difference between this one and lecture one is this version uses the color
 * to indicate the state of a vertex, so we can know if we should visit it or not.
 * in another version, we used level to indicate if we should visit it or not, so 
 * we have to search in level to make sure it has not been visited before.
 * ------------------------------------------------
 * in both version we used adjacancy matrix to store the graph, in fact, we just need to
 * modify for loop about how we visit adj[u], we can use adjacancy list as well.
 * ------------------------------------------------
 * ForenewHan 2018.1.5 at XMU
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::map;
using std::make_pair;

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

void breadthFirst(vector<vector<int>>& Gmatrix)
{
    if(Gmatrix.empty()){    // fisrt of all, judge if Gmatrix is empty
        return;
    }

    const int startVex = 0;		// start vertex, from here to start BFS
    const int N = Gmatrix.size();
    enum color {white, grey, black};    // vertex has 3 colors

    struct vexState{
        color c;		// color of vertex
        int d;			// distance of vertex
        int p;			// parent of vertex
    }vexstate[N];       // using vexstate to store the state of vertex


    for(int i=0;i<N;i++){       // initialize vertices
        vexstate[i].c = white;
        vexstate[i].d = -1;     // -1 indicates inf
        vexstate[i].p = -1;     // -1 indicates NIL
    }

    queue<int> q;       // using queue to store grey vertex, which has not been fully visited
    vexstate[startVex].c = grey;    // start from startVex to BFS
    vexstate[startVex].d = 0;

    q.push(startVex);

    int currentVex;     // currentVex is the vextex we just take out from queue
    while(!q.empty()){
        currentVex = q.front();     // take a vertex out
        q.pop();

        printf("%d\n", currentVex);     // visit currentVex


        for(int i=0;i<Gmatrix[currentVex].size();i++){      // find the adj of currentVex
            if(Gmatrix[currentVex][i] == 1){
                if(vexstate[i].c == white){     // if the adj vex has never been visited before, visit it and store it in queue
                    vexstate[i].c = grey;
                    vexstate[i].d = vexstate[currentVex].d + 1;
                    vexstate[i].p = currentVex;
                    q.push(i);
                }
            }
        }
        vexstate[currentVex].c = black;     // after visit all adj of currentVex, paint it to black
    }

}




int main(){
    vector<vector<int>> t;
    insertVex(t);
    insertVex(t);
    insertVex(t);
    insertVex(t);
    insertVex(t);
    insertArc(t,0,1);
    insertArc(t,1,0);
    insertArc(t,0,2);
    insertArc(t,2,0);
    insertArc(t,1,3);
    insertArc(t,3,1);
    insertArc(t,3,4);
    insertArc(t,4,3);
    insertArc(t,0,4);
    insertArc(t,4,0);
//    insertArc(t,1,2);
//    insertArc(t,2,1);

    //deleteVex(t,0);
    for(auto i=t.begin();i<t.end();i++){
        for(auto j = (*i).begin(); j<(*i).end();j++){
            printf("%d\t",*j);
        }
        cout << endl;
    }

    printf("------------\n");

    breadthFirst(t);

//    map<int, int> mt;
//    mt.insert(make_pair(99,2));
//    mt.insert(make_pair(128,3));
//    auto fd = mt.find(59);
//    cout << (*fd).first;
}