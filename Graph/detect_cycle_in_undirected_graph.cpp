#include<bits/stdc++.h>
using namespace std;

/*
codehelp graph class 2

algo (using BFS algo): (cycle present agar koi node par uske parent k alawa kisi aur node se vi pohochsakte hai toh)
- maintain parent for each node
- pop front node & push each of its unvisited adjacent nodes & mark them visited & also store their parent node as front node
- for each curr node, check all its adj nodes, we know harek adj node se curr node mai pohochsakte hai 
  so, that adj node must be curr node's parent, agar parent nai hai matlab parent k alawa koi aur node se vi curr node mai jasakte hai i.e. cycle found 


eg graph: o -- 1 ( 1 pe sirf 0 se pohoch parahe hai & 0 hi 1 ka parent hai so no cycle )


NOTE: visited map is used in graph to avoid infinite loop eg: 0-1 then it'll loop betn 0 and 1 without visited map
*/

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
            for(auto itr : neighbours){
                cout << itr << " ";
            }
            cout << "}" << endl;
        }
    }


    // cycle detection  (very similar to bfs just that parent is added here)
    bool hasCycle(int src){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        queue<int> q;
        
        // push src initially
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            // take out curr node
            int frontNode = q.front();
            q.pop();

            // check for all neighbours of curr node
            for(int neighbour : adjList[frontNode]){
                // agar curr neighbour visited hai & wo curr node ka parent nahi hai, matlab curr node par parent k alawa iss neighbour se vi pohoch sakte hai
                if( visited[neighbour] && neighbour != parent[frontNode] ){
                    return true;
                }else if( !visited[neighbour] ){  // agar neighbour visited nahi hai then queue mai dalke visit karo & parent vi set kardo
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
    }
};

// GFG soln ans
// for disconnected graph cases also
 bool solve(int src, unordered_map<int, bool> &visited, vector<int> adjList[]){
        unordered_map<int, int> parent;
        queue<int> q;
        
        // push src initially
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty()){
            // take out curr node
            int frontNode = q.front();
            q.pop();

            // check for all neighbours of curr node
            for(int neighbour : adjList[frontNode]){
                // agar curr neighbour visited hai & wo curr node ka parent nahi hai, matlab curr node par parent k alawa iss neighbour se vi pohoch sakte hai
                if( visited[neighbour] && neighbour != parent[frontNode] ){
                    return true;
                }else if( !visited[neighbour] ){  // agar neighbour visited nahi hai then queue mai dalke visit karo & parent vi set kardo
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
  }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adjList[]) {
        unordered_map<int, bool> visited;
        bool ans = false;
        // to handle cases of disconnected graph
        for(int i=0;i<V;i++){
            if(!visited[i])
                ans = solve(i, visited, adjList);
            if(ans)
                return true;
        }
        return false;
    }




// 2. DFS solution(for each node, check all its neighbour nodes for the reqd condition)
 bool solve(int src, unordered_map<int, bool> &visited, vector<int> adjList[], int parent){
        // visit current
        visited[src] = true;
        
        // check for each neighbour of src
        for(int nbr : adjList[src]){
            if(nbr == parent) // curr neighbour is the parent of src node, so no need to check for cycle
                continue;
            // if curr neighbour isn't visited, recursive call to visit it
            if(!visited[nbr]){
                bool ans = solve(nbr, visited, adjList, src); // current neighbour's parent is src
                if(ans) return true;
            }else if(visited[nbr] && nbr != parent){ 
                // curr neighbr is visited but its not equal to src node's parent(matlab src node mai uske parent k alawa koi aur node se vi jasakte ho)
                return true;
            }
        }
        return false;
  }
  
    bool isCycle(int V, vector<int> adjList[]) {
        unordered_map<int, bool> visited;
        int parent = -1; // no need for parent map bcoz in each call, we create new copy of current parent
        // to handle cases of disconnected graph
        for(int i=0;i<V;i++){
            bool ans = false;
            if(!visited[i])
                ans = solve(i, visited, adjList, parent);
            if(ans)
                return true;
        }
        return false;
    }



int main(){
    Graph g;
    g.addEdge(0, 1, 0);  // node 0 se node 1 par undirected edge
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(3, 4, 0);
    // g.printList();

    cout << g.hasCycle(0);

    return 0;
}