#include<bits/stdc++.h>
using namespace std;

/*

Weighted Graph:

*/

/*
BFS algo: 
TIME: for each node(vertex), we're visiting all its neighbours. so average: O(v+e) vertices+edges & worst: O(v^2)
SPACE: map & queue takes space O(v) & adjacency list takes space O(v+e) bcoz each vertex is stored once & each edge is stored once in the adjacency list.

(similar to BFS in tree, but here we also maintain adjacencylist and visited map) 
- initially push a node in queue, 
- print the front node, pop it & push all its adjacent unvisited nodes & mark them visited.

*/

/*
DFS algo (using recursion):

- print curr node 
- mark it visited
- recursive call for unvisited child nodes

*/



template <typename T>  // using template so that our graph can store any type of node values like int, char, string.

class Graph{
    public:
    
    unordered_map<T, list<pair<T, T>>> adjList;  // source_node -> { { destination_node, weight }, { }, { } }

    void addEdge(T u, T v, int wt, bool direction){  // weight is integer
        if(direction == 1){  // directed edge
            adjList[u].push_back({v, wt});
        }else{  // undirected edge
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void printList(){
        for(auto elm : adjList){ 
            cout << elm.first << " ->{ "; // elm.first is the source node
            for(pair<T, int> p : elm.second){  // elm.second is a list of pairs
                    cout << "{" << p.first << ", " << p.second << "} ";   // printing each pair
            }
            cout << " }";
            cout << endl;
        }
    }




// BFS traversal (fails in case of disconnected graph, we have to call BFS func for each node inorder to run for disconnected graph)
    void BFSGraph(T src, unordered_map<T, bool> &visited){  // source node & visited map in parameter
        // we already have adjacency list
        // visited map (node -> bool_val)

        queue<T> q;

        // initially push src node & mark it visited
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            // print front & pop it
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            // push all unvisited neighbours of front node & mark them visited
            for(pair<T, int> neighbour : adjList[frontNode]){  // traversing over the list containing all neighbours of front node
                T neighbourData = neighbour.first;  
                if( !visited[neighbourData] ){
                    q.push(neighbourData);
                    visited[neighbourData] = true;
                }
            } 
        }
    }



// Implementation of Iterative DFS: It is similar to BFS, the only difference is queue is replaced by stack.
// REcursive DFS Traversal
    void DFSGraph(T src, unordered_map<T, bool> &visited){
        // print & mark visited
        cout << src << " ";
        visited[src] = true;

        // do same for all unvisited child nodes
        for(auto neighbour : adjList[src]){
            T neighbourData = neighbour.first;
            if( !visited[neighbourData] ){
                DFSGraph(neighbourData, visited);
            }
        }
    }

};


int main(){
    Graph<char> g;   // specify the typename T as char i.e. all T will be taken as char now

    unordered_map<char, bool> visited;
 
// BFS check for connected graph
    // g.addEdge('a', 'b', 5, 0);
    // g.addEdge('a', 'c', 10, 0);
    // g.addEdge('b', 'd', 20, 0);
    // g.addEdge('c', 'e', 20, 0);
    // g.addEdge('c', 'f', 20, 0);

    // cout << "BFS: ";
    // g.BFSGraph('a', visited);

    // g.printList();



/* 
// BFS check for disconnected graph
    g.addEdge('a', 'b', 5, 0);
    g.addEdge('b', 'c', 10, 0);

    g.addEdge('d', 'e', 20, 0);
    
    g.addEdge('f', 'f', 20, 0);


    // call BFS for all node incase of disconnected graph
    for(char c='a';c<='f';c++){
        if(!visited[c]){
            g.BFSGraph(c, visited);
        }
    }

*/



// DFS check for connected graph

    // g.addEdge('a', 'b', 5, 0);
    // g.addEdge('a', 'c', 10, 0);
    // g.addEdge('c', 'd', 20, 0);
    // g.addEdge('c', 'e', 20, 0);
    // g.addEdge('d', 'e', 20, 0);
    // g.addEdge('e', 'f', 20, 0);

    g.addEdge('a', 'b', 5, 0);
    g.addEdge('a', 'c', 10, 0);
    g.addEdge('b', 'd', 20, 0);
    g.addEdge('c', 'e', 20, 0);
    g.addEdge('c', 'f', 20, 0);

     g.DFSGraph('a', visited);


// call DFS for all node incase of disconnected graph
    // g.addEdge('a', 'b', 5, 0);
    // g.addEdge('b', 'c', 10, 0);

    // g.addEdge('d', 'e', 20, 0);
    
    // // g.addEdge('f', 'f', 20, 0);


    // for(char c='a';c<='f';c++){
    //     if(!visited[c]){
    //         g.DFSGraph(c, visited);
    //     }
    // }


    return 0;
}