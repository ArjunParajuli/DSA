#include<bits/stdc++.h>
using namespace std;

// using adjacency list
class Graph{
    public:
    unordered_map<int, list<int>> adjList;  // node -> its neighbour nodes

    void addEdge(int u, int v, bool direction){
        // direction 0 means undirected edge
        // direction 1 means directed edge
        if(direction == 1){
            // u -> v (u se vi ki taraf ek edge hai)
            adjList[u].push_back(v);
        }else{
            // u - v (no direction so dono ko dalo)
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }


    void printList(){
        for(auto elm : adjList){
            int node = elm.first;
            auto neighbours = elm.second;
            cout << node << "-> { ";
            for(auto nbr : neighbours){
                cout << nbr << " ";
            }
            cout << "}" << endl;
        }
    }


    void DFS(unordered_map<int, int> &visited, int src){
        visited[src] = true;

        for(int nbr : adjList[src]){
            if(!visited[nbr]){
                DFS(visited, nbr);
            }
        }
    }

    /*
    algo:
    - for each node in adjList, if it is not visited, increment count & we call DFS for it, so that all its connected nodes will be visited 
    
    eg: 1 – 5, 0 – 2 – 4 and 3  are the components.
    adjList:
    0 -> 2, 4
    1 -> 5
    2 -> 0
    4 -> 0
    3 -> 
    5 -> 1

     Then we iterate over each node in adjList(i.e. 0, 1, 2, 4, 3, 5) & if its not visited then 
    increment count & call dfs for it

    */

    int countComponents(){
        int cnt=0;
        unordered_map<int, int> visited;
        for(auto elm : adjList){
            if(!visited[elm.first]){
                cnt++;
                DFS(visited, elm.first);
            }
        }
        return cnt;
    }
};

int main(){
    Graph g;
    g.addEdge(1, 5, 0);
    g.addEdge(0, 4, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(3, 3, 1);

    cout << g.countComponents();


    return 0;
}