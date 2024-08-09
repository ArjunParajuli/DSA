#include<bits/stdc++.h>
using namespace std;


/*

Bellman ford: 
- single source shortest path finding algo. 
- Finds -ve cycle. Doesn't work for -ve cycle.
- performs relaxation n-1 times.
relaxation is the updation step(Relaxation is the process of updating the shortest path estimate for a vertex.) similar to the updation step used in dijkstra algo.
i.e. 

if(topDist + nbrWt < distance[nbrNode]){
 // updation
}

Although Bellman-Ford is slower than Dijkstra’s algorithm, it is capable of handling graphs with negative edge weights,
which makes it more versatile. The shortest path cannot be found if there exists a negative cycle in the graph.

Q) Why n-1 times relaxation?
-> suppose graph A->B->C->D
After first relaxation, A se shortest path banne waley path miljatey hai and after second relaxation, B se shortest path banne waley miljatey hai and so on.

By iterating 𝑛−1 times, the algorithm ensures that all shortest paths with up to 𝑛−1 edges are considered.
After each iteration, the algorithm ensures that the shortest path to each vertex is correctly calculated.

Q) Why not Fewer than 𝑛−1 Relaxations?
->If you perform fewer than n−1 relaxations, you might miss the shortest paths that involve all the edges.

Q) Why not more than n−1 Relaxations?
-> Performing more than n−1 relaxations is unnecessary for finding shortest paths in a graph without negative-weight cycles.
 All shortest paths will already be found within n−1 iterations.
If the algorithm is run for 𝑛 relaxations and any distance is still updated, 
it indicates the presence of a negative-weight cycle, which makes it impossible to find a shortest path.

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
    
    void bellmanFord(int n, int src){
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // n-1 times relaxation 
        // for all edges
        for(int i=0;i<n-1;i++){
            for(auto itr : adjList){
            char u = itr.first - 'A'; // to get correct index in distance array
            auto edgeList = itr.second;
            for(auto elm : edgeList){
                char v = elm.first - 'A';
                int wt = elm.second;
                if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){ // ( dist[u] -> distn from src to u node ) & ( wt -> dist betn u & v )
                    dist[v] = dist[u]+wt;
                }
            }
         }
        }

        //yaha tak shortest distance ready h 
		//check for -ve cycle 
		//1 time relaxation 
        bool anyUpdate = false;
        for(auto itr : adjList){
            char u = itr.first - 'A'; // to get correct index in distance array
            auto edgeList = itr.second;
            for(auto elm : edgeList){
                char v = elm.first - 'A';
                int wt = elm.second;
                if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
                    anyUpdate = true;
                    break;
                    dist[v] = dist[u]+wt;
                }
            }
         }


        if(anyUpdate == true) {
			cout << "Negative Cycle Present" << endl;
		}
		else {
			cout << "No Negative Cycle in Graph " << endl;
			cout << "Printing Distance Array: " ;
			for(auto i: dist) {
				cout << i << ", ";
			}cout << endl;
		}
    }
};


int main(){
    Graph<char> g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('A', 'E', 4, 1);
    g.addEdge('B', 'E', 3, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('B', 'C', 2, 1);
    g.addEdge('C', 'D', -3, 1);
    g.addEdge('D', 'E', 5, 1);
    g.addEdge('D', 'B', 1, 1);

    g.print();
    g.bellmanFord(5, 0);

    return 0;
}