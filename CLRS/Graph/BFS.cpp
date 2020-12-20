/* BFS and shortest path implemation
 * using 0 as first vertex, G.size()-1 as the last one.
 * insertVex, deleteVex, insertArc, deleteArc BFS, shortest_path operations.
 * algorithm from MIT 6.006 Erik
 * ForenewHan 2018.1.3 at XMU
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

// find shortest path from sourceVex to destVex, sourceVex should be the one just did BFS, output is reversed
void findShortestPath(map<int, int> parent, int soureceVex, int destVex)
{
    if(parent.find(destVex) != parent.end()){       // if destVex is unreachable in parent, then return
        auto currentVex = parent.find(destVex);
        int father = (*currentVex).second;      // the father vertex of currentVex

        printf("%d\n", destVex);    // path end point, from here back to sourceVex

        while(father != soureceVex){    // while father has not reached sourceVex, keep going
            printf("%d\n", father);
            currentVex = parent.find(father);
            father = (*currentVex).second;
        }

        printf("%d\n", soureceVex);
    }
}

// BFS 
void breadthFirst(vector<vector<int>>& Gmatrix)
{
    if(Gmatrix.empty()){    // fisrt of all, judge if Gmatrix is empty
        return;
    }

    const int startVex = 0;		// start vertex, from here to start BFS

    map<int, int> level;    // level stores the levels for all vertices(shortest distance to startVex)
    level.insert(make_pair(startVex,0));   // start vertex with level 0

    map<int, int> parent;   // parent stores the parents for all vertices
    parent.insert(make_pair(startVex,-1));     // start vertex with parent -1

    int i = 1;      // i is used to indicate current level

    queue<int> frontier, next;      // frontier stores current level to visit, next stores next level
    queue<int> emptyQ;      // emptyQ is used to initialize next.

    frontier.push(startVex);    // push startVex into frontier, start visit
    while(!frontier.empty()){
        next = emptyQ;      // initialize next, so every adj vertex of frontier would be pushed into next
        for(int u = frontier.front();!frontier.empty();frontier.pop()){     // while frontier is not empty, pop one out
            u = frontier.front();   // take one in frontier

            //printf("%d\n", u);  // visit current vertex

            for(int v=0;v<Gmatrix.size();v++){      // find adj vertex of current u, if there is an edge from u to v, then add vertex to next list
                if(Gmatrix[u][v] == 1) {
                    if (level.find(v) == level.end()) {     // if not find, map would return map.end()
                        level.insert(make_pair(v, i));      // record v's level, level is stored in pair.second
                        parent.insert(make_pair(v, u));     // record v's parent, parent is stored in pair.second
                        next.push(v);       // push v to next, for next level visit
                    }
                }
            }
        }
        frontier = next;    // frontier is visited, make it equal to next
        i+=1;       // current level increase
    }

    //findShortestPath(parent,startVex,4);
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
//    insertArc(t,0,4);
//    insertArc(t,4,0);
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