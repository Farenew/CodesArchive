/* DFS with stack implemation
 * using 0 as first vertex, G.size()-1 as the last one.
 * insertVex, deleteVex, insertArc, deleteArc, DFS operations.
 * ------------------------------------------------
 * algorithm from CLRS
 * ------------------------------------------------
 * using depthFisrt to call DFS, within DFS, using stack to store vertices
 * ------------------------------------------------
 * we used adjacancy matrix to store the graph, in fact, we just need to
 * modify for loop about how we visit adj[u], we can use adjacancy list as well.
 * ------------------------------------------------
 * we put some common used stuff as global variable, including size N, time, color
 * and vexstate, but in this DFS with stack, we dont have to use global variable
 * as well.
 * ------------------------------------------------
 * ForenewHan 2018.1.5 at XMU
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::map;
using std::make_pair;
using std::stack;

const int N = 7;
int time;
enum color {white, grey, black};    // vertex has 3 colors
struct vexState{
    color c;		// color of vertex
    int d;			// discover time of vertex
    int f;          // finish time of vertex
    int p;			// parent of vertex
}vexstate[N];       // using vexstate to store the state of vertex

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

// DFS_visit, using this to recursively call visit
void DFS_visit(vector<vector<int>>& Gmatrix, int u)
{
    time++;			// increase current timestamp
    vexstate[u].d = time;		// set the discover time as current time
    vexstate[u].c = grey;		// set the vertex to visit as color grey
    stack<int> s;               // stack s is used to store the vertices to visit

    s.push(u);      // push u into stack as the first vertex to visit.
    int currentVex;
    while(!s.empty()){
        currentVex = s.top();
        s.pop();

        printf("%d\n",currentVex);      // visit vertex

        for(int i=0; i<N; i++){	// searching adj of vertex currentVex, we can change to adj list structure here
            if(Gmatrix[currentVex][i] == 1){
                if(vexstate[i].c == white){		// if vertex has never been visited before
                    vexstate[i].p = currentVex;		// set its parent
                    vexstate[i].c = grey;       // paint to vertex waiting to be visited grey
                    s.push(i);
                }
            }
        }           // after for loop, we visited all adj of currentVex
        time++;		// time increase
        vexstate[currentVex].f = time;		// u's finish time
        vexstate[currentVex].c = black;		// u is fully visited, paint black
    }
}
void depthFisrt(vector<vector<int>>& Gmatrix)
{
    if(Gmatrix.empty()){    // fisrt of all, judge if Gmatrix is empty
        return;
    }

    const int startVex = 0;		// start vertex, from here to start BFS

    for(int i=0;i<N;i++){       // initialize vertices
        vexstate[i].c = white;
        vexstate[i].p = -1;     // -1 indicates NIL
    }

    time = 0;		// set the start time
    for(int i=0;i<N;i++){
        if(vexstate[i].c == white)		// if i has never been visited before, visit it
            DFS_visit(Gmatrix, i);
    }
}



int main(){
    vector<vector<int>> t;
    for(int i=0;i<N;i++){
        insertVex(t);
    }

    insertArc(t,0,1);
    insertArc(t,0,3);
    insertArc(t,1,4);
    insertArc(t,2,4);
    insertArc(t,3,1);
    insertArc(t,4,3);
    insertArc(t,2,5);
    insertArc(t,3,6);
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
    depthFisrt(t);
//    map<int, int> mt;
//    mt.insert(make_pair(99,2));
//    mt.insert(make_pair(128,3));
//    auto fd = mt.find(59);
//    cout << (*fd).first;
}