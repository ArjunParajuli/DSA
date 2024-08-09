#include<bits/stdc++.h>
using namespace std;

/*

Strongly connencted component: Component in which we can reach any other vertex from any vertex.

Q) Why Strongly Connected Components (SCCs) are Important?
Real life example: Delhi metro.
Applications:
Network Analysis: Finding groups of closely related nodes.
Web Crawling: Identifying linked parts of the web graph for efficient crawling.
Dependency Resolution: Understanding which software modules depend on each other.

Types of Question for SCC: Count SCC in graph, print all SCC


algo: used dfs algo in step 1 & 3
1. get the ordering in stack (similar to topo sort ordering but don't say this in interview bcoz toposort works only for directed graph)
2. reverse the edges
3. traverse using ordering and count components

ordering makes sure that either u'll keep visiting the current strongly connected component or u'll go to the other SCC that's already visited.
so this will always give us correct count of SCC.

Time: O(v+e) for each step

*/

template <typename T>
class Graph{
    public:
    unordered_map<T, list<int>> adjList; 

    void addEdge(T u, T v, bool direction){
        if(direction == 0){ // undirected
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }else{ // directed
            adjList[u].push_back(v);
        }
    }

    void print(){
        for(auto itr : adjList){
            T u = itr.first;
            auto ls = itr.second;
            cout << u << "-> { ";
            for(auto elm : ls){
                cout << " " << elm ;
            }
            cout << endl;
        }
    }

    void dfs1(int src, unordered_map<int, int> &visited, stack<int> &ordering){
          visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                dfs1(nbr, visited, ordering);
            }
        }
        // backtracking 
        ordering.push(src);
    }

    void dfs2(int src, unordered_map<int, int> &visited2, unordered_map<int, list<int>> &revAdjList){
          visited2[src] = true;
          cout << src << ", ";
        for(auto nbr:revAdjList[src]){
            if(!visited2[nbr]){
                dfs2(nbr, visited2, revAdjList);
            }
        }
        
    }


    // Kosaraju algo
    int getSCC(int n){
        // step1: get ordering
        unordered_map<int, int> visited;
        stack<int> ordering;
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs1(i, visited, ordering);
        }

        // step 2: reverse edges
        unordered_map<int, list<int>> revAdjList;
        for(auto itr : adjList){
            int u = itr.first;
            for(auto v : itr.second){
                revAdjList[v].push_back(u);
            }
        }

        // step3: traverse using ordering and count components
        int cnt = 0;
        unordered_map<int, int> visited2;
        while(!ordering.empty()){
            int top = ordering.top();
            ordering.pop();
            if(!visited2[top]){
                cnt++;
                dfs2(top, visited2, revAdjList);
                cout << endl;
            }
        }

        return cnt;
    }



};


int main(){
    Graph<int> g;
    g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 0, 1);

	g.addEdge(2, 4, 1);

	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 4, 1);

	g.addEdge(6, 7, 1);
	int n = 8;
    
    cout << g.getSCC(n);

    return 0;
}