/* DFS implemation with edge type to print
 * using 0 as first vertex, G.size()-1 as the last one.
 * insertVex, deleteVex, insertArc, deleteArc, DFS operations.
 * ------------------------------------------------
 * algorithm from CLRS
 * ------------------------------------------------
 * using depthFisrt to call DFS, within DFS, do recursive DFS_visit
 * ------------------------------------------------
 * we used adjacancy matrix to store the graph, in fact, we just need to
 * modify for loop about how we visit adj[u], we can use adjacancy list as well.
 * ------------------------------------------------
 * we put some common used stuff as global variable, including size N, time, color
 * and vexstate, since we are doing recursive visit, using structure like this
 * is helpful and easy to use.
 * ------------------------------------------------
 * ForenewHan 2018.1.6 at XMU
*/
#include <iostream>
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
using std::pair;

const int N = 6;            // vertices number for graph
int time;               // time is used to monitor vertex visit state
enum color {white, grey, black};    // vertex has 3 colors

struct vexState{
    color c;		// color of vertex
    int d;			// discover time of vertex
    int f;          // finish time of vertex
    int p;			// parent of vertex
}vexstate[N];       // using vexstate to store the state of vertex

// edge has four types
enum edgeState {tree_edge, forward_edge, back_edge, cross_edge};

// struct to store edge as well as it's state
struct edge{
    int start;
    int end;
    edgeState type;
};

// four different edges, delcared here so we can use them more times
edge treeEdge;
edge crossEdge;
edge forwardEdge;
edge backEdge;

// using vector to store the edge and it's type
vector<edge> edgeClass;

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

// DFS_visit, using this to recursively call visit, added edge type record.
void DFS_visit(vector<vector<int>>& Gmatrix, int u)
{
    time++;			// increase current timestamp
    vexstate[u].d = time;		// set the discover time as current time
    vexstate[u].c = grey;		// set the vertex to visit as color grey

    printf("%d\n",u);		// doing visit

    for(int i=0; i<Gmatrix.size(); i++){	// searching adj of vertex u, we can change to adj list structure here
        if(Gmatrix[u][i] == 1){
            if(vexstate[i].c == white){		// if vertex has never been visited before

                treeEdge.start = u;         // if v in <u,v> is white, then it must be treeEdge
                treeEdge.end = i;
                treeEdge.type = tree_edge;
                edgeClass.push_back(treeEdge);

                vexstate[i].p = u;		// set its parent
                DFS_visit(Gmatrix, i);
            }
            else if(vexstate[i].c == grey){     // if v in <u,v> is grey, then it must be backEdge
                backEdge.start = u;
                backEdge.end = i;
                backEdge.type = back_edge;
                edgeClass.push_back(backEdge);

            }
            else{
                if(vexstate[i].d < vexstate[u].d){      // if v in <u,v> is black, then it has two types, using discover time to judge
                    crossEdge.start = u;
                    crossEdge.end = i;
                    crossEdge.type = cross_edge;
                    edgeClass.push_back(crossEdge);
                }
                else{
                    forwardEdge.start = u;
                    forwardEdge.end = i;
                    forwardEdge.type = forward_edge;
                    edgeClass.push_back(forwardEdge);
                }
            }
        }

    }
    time++;		// after visit u, time should increase
    vexstate[u].f = time;		// u's finish time
    vexstate[u].c = black;		// u is fully visited, paint black
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
    insertArc(t,2,5);
    insertArc(t,3,1);
    insertArc(t,4,3);
    insertArc(t,5,5);
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

    const char* type[] = {"tree_edge", "forward_edge", "back_edge", "cross_edge"};
    for(auto i = edgeClass.begin();i!=edgeClass.end();i++){
        printf("<%d,%d> is %s\n",(*i).start,(*i).end, type[(*i).type]);
    }
}