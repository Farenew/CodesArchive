/* kruskal method to give minimum spanning tree.
 * ForenewHan 2018.1.11 at XMU
 *
 */
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>

using std::cout;
using std::endl;
using std::max;
using std::vector;
using std::set;
using std::sort;

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
void insertArc(vector<vector<int>>& Gmatrix, int u, int v, int w){
    Gmatrix[u][v] = w;
    //Gmatrix[v][u] = w;
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

// undirected edge with weight
struct edge{
    int u;
    int v;
    int w;
};
bool cmp(const edge e1, const edge e2){ return e1.w < e2.w; }

// kruskal method, using adj matrix as graph input, write minimum spanning tree back to vector tree
void kruskalMST(vector<vector<int>>& graph, vector<edge>& tree)
{
    // N equals to vertices number
    const int N = graph.size();
    vector<edge> edges;
    edge uv;
    // iterate through whole graph and store all edges into vector edges.
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(graph[i][j] != 0){
                uv.u = i;
                uv.v = j;
                uv.w = graph[i][j];
                edges.push_back(uv);
            }
        }
    }
    // sort the edges
    sort(edges.begin(), edges.end(), cmp);

    // make different vertices different value, to indicate if they are in same set
    int vertices[N];
    for(int i=0;i<N;i++){
        vertices[i] = i;
    }
    int u,v;
    int mark, toChange;
    // iterate through all edges, find edges not in same set
    for(auto i=edges.begin();i!=edges.end();i++){
        u = (*i).u;
        v = (*i).v;
        // if two vertex in different set, then union them,
        // here doing loop to make sure all vertex are properlly unioned.
        if(vertices[u]!=vertices[v]){
            mark = vertices[u];
            toChange = vertices[v];
            // using loop to find if vertex from same union
            for(int j=0;j<N;j++){
                if(vertices[j] == toChange)
                    vertices[j] = mark;
            }
            // add to minimum spanning tree
            tree.push_back(*i);
        }
    }

}

int main(){
    const int N = 9;
    vector<vector<int>> graph;
    for(int i=0;i<N;i++){
        insertVex(graph);
    }
    insertArc(graph, 0,1,8);
    insertArc(graph, 0,3,4);
    insertArc(graph, 0,6,11);
    insertArc(graph, 1,4,2);
    insertArc(graph, 1,2,7);
    insertArc(graph, 1,8,4);
    insertArc(graph, 2,5,9);
    insertArc(graph, 2,8,14);
    insertArc(graph, 3,6,8);
    insertArc(graph, 4,6,7);
    insertArc(graph, 4,7,6);
    insertArc(graph, 5,8,10);
    insertArc(graph, 6,7,1);
    insertArc(graph, 7,8,2);

    vector<edge> tree;
    kruskalMST(graph, tree);
    for(auto i:tree)
        printf("(%d %d) with %d\n",i.u, i.v, i.w);
}