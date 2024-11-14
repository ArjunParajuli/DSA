#include<bits/stdc++.h>
using namespace std;

/*

Graph: It is a type of non-linear data structure which consisits of edges and nodes. Practical Application: google maps, facebook, etc.
- Node: contains data
- Edge: connects nodes. Types: directional(has arrow) & undirectional edges. Edges can also have weights.

Cyclic graph: there exists at least one cycle, meaning a path that starts and ends at the same vertex, not necessary to visit all nodes.

- Degree:
i. For an undirected graph, the degree of a vertex is simply the number of edges connected to it.
ii. For a directed graph, there are two types of degrees:
In-degree: The number of edges coming into a vertex.
Out-degree: The number of edges going out from a vertex.

- Path:  route that moves from one vertex to another without repeating any vertex.

- Disconnected graph: graph in which there are two or more vertices that are not connected by any edges.
 disconnected graph can be split into two or more separate subgraphs, each of which is called a connected component.

 - Each tree is a graph but each graph is not a tree.

### VIMP Ques: clone a graph.

*/

/*

Two ways to represent a graph:
- Adjacency matrix (we have an edgelist(contains all connected node mappings eg: node1 connected to node 2 then 1->2 is in edgelist) & we insert each mapping in an adjacency matrix)
- Adjacency List (each node is mapped to a list of nodes to which it is connected) 

List data structure: list(implemented as a doubly-linked list) is a container that allows for fast insertion and deletion in O(1) anywhere within the sequence. 
*/

// using adjacency list
/*
space using adjacency list: 
Directed Graph: Each of the 𝐸 edges is stored once, so the space required is O(V+E)
Undirected Graph: Each of the 𝐸 edges is stored twice (once in each direction), so the space required is O(V+2E)

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
            for(auto nbr : neighbours){
                cout << nbr << " ";
            }
            cout << "}" << endl;
        }
    }
};


int main(){
    Graph g;
    // g.addEdge(0, 1, 1);  // node 0 se node 1 par directed edge
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 1);
    // g.addEdge(2, 3, 1);

    g.addEdge(0, 1, 0);  // node 0 se node 1 par undirected edge
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 3, 0);

    g.printList();

    return 0;
}