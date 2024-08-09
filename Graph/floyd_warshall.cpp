#include<bits/stdc++.h>
using namespace std;

#define INF 9999

/*

Multiple source shortest path: finds shortest path from all possible nodes to all possible nodes in a weighted graph. 
Idea: src to dst ke sarey path explore karlo and select the shortest one.

Distance array will be 2d & fill all diagonal elms as 0. (bcoz distn from a to a is 0) 
see notion notes for dryrun graph

algo:
- initially insert given weights of graph in distance array
- Update the 2d array distance using the helper nodes(intermidiatory nodes betn all possible src and dst) 

time: O(n^3), n->number of nodes


*/


template <typename T>
class Graph{
    public:
    unordered_map<T, list<pair<T, int>>> adjList; // { u, [{v1, wt}, {v2, wt}, ...] }

    void addEdge(T u, T v, int wt, bool direction){
        if(direction == 0){ // undirected
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }else{ // directed
            adjList[u].push_back({v, wt});
        }
    }

    void print(){
        for(auto itr : adjList){
            T u = itr.first;
            auto ls = itr.second;
            cout << u << "-> { ";
            for(auto elm : ls){
                cout << "{ " << elm.first << ", " << elm.second << "}, ";
            }
            cout << endl;
        }
    }


    void floydWarshall(int n){
        // dont use INT_MAX bcoz it'll get overflowed while updating 
        vector<vector<int>> distance(n, vector<int>(n, INF));

        // fill diagonal as 0
        for(int i=0;i<n;i++){
            distance[i][i] = 0;
        }

        // fill graph's weights in distance array
        for(auto itr : adjList){
            int u = itr.first;
            for(auto elm : itr.second){
                int v = elm.first;
                int wt = elm.second;
                distance[u][v] = wt;
            }
        }

        // find shortest distance using helper nodes
        for(int helper=0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int dst=0;dst<n;dst++){
                    // if curr distance is less than distance betn src to helper and helper to dst 
                    if(distance[src][dst] > distance[src][helper]+distance[helper][dst])
                        distance[src][dst] = distance[src][helper]+distance[helper][dst];
                }
            }
        }

        // print shortest distances
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << distance[i][j] << " ";
            }
            cout << endl;
        }
    }


};

int main(){
    Graph<int> g;
    g.addEdge(0, 1, 3, 1);
	g.addEdge(1, 0, 2, 1);
	g.addEdge(0, 3, 5, 1);
	g.addEdge(1, 3, 4, 1);
	g.addEdge(3, 2, 2, 1);
	g.addEdge(2, 1, 1, 1);
    g.floydWarshall(4);
    
    return 0;
}