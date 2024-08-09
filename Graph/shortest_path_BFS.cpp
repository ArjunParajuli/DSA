#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

/*

Shortest path in undirected graph Using BFS: destination node pe jo bhi node pehle pohochta hai wahi node ka path shortest path hai

*/

class Graph{
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction){
        if(direction == 1){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(auto elm : adjList){
            int node = elm.first;
            cout << node << " -> { ";
            for(int nbr : elm.second){
                cout << nbr << " ";
            }
            cout << " }" << endl;
        }
    }

    /*
    dry run here, src=0, dst=5, shortest path is {0,3,5}

             0
           / | \
          6  3  4
          |  |  |
          2  |  1
           \ | /
             5
    
    */


    // shortest path using BFS
    /*
    - first bfs traverse and store parent of each node
    - then push the parent of dest node & that node's parent & so on, until we reach the src node
    */
   
    void shortestPath(int src, int dest){
        queue<int> q;
        unordered_map<int, int> parent;
        unordered_map<int, bool> visited;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            // store parent of all nodes
            for(int nbr : adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
            }
        }

        // now we have parent of all nodes
        // find the shortest path
        vector<int> shortestPath;
        shortestPath.push_back(dest); 
        while(dest != src){
            shortestPath.push_back(parent[dest]);
            dest = parent[dest];
        }
        reverse(shortestPath.begin(), shortestPath.end()); 
        
        // print shortest path:
        for(auto it : shortestPath)
            cout << it << " ";
        cout << endl;

    }
};


int main(){
    Graph g;
    g.addEdge(0, 4, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(6, 2, 0);
    g.addEdge(1, 5, 0);
    g.addEdge(2, 5, 0);

    g.shortestPath(0, 5);

    return 0;
}

