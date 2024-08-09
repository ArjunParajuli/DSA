#include<bits/stdc++.h>
using namespace std;

/*
codehelp Graph class 4
see notion graph notes for dryrun graph

Dijkstra is a greedy algo(focuses on present best sol and not on long term best soln). 
We will use set/minheap here. (set is implemented thr Red-Black Tree, a kind of self-balancing BST. Insertion in O(logn) in set & O(1) avg in unordered_set) We can get minm elm in O(1) in both these data structures.


Limitations of Dijkstra:
- Doesnt work for negative weights.
- Doesnt work for negative cycles(cycle banri hai and uss cycle ka weight ka sum -ve hai).
- Doesnt work for unreachable nodes(disconnected graph so ofc no path u idiot).


algo:
- initially insert src node's distance in set ({0, src})
- until set is empty, pop out first elm & update its nbr distance in both distance arr & set


Q) Why dijkstra doesnt work for -ve weights/cycle?
-> Bcoz it'll keep updating the neighbours distance in set and go into infinite loop.(bcoz adding -ve values will give lesser -ve values and gets updated in set for ever and ever)

Bellman Ford works for -ve weights. But not for -ve cycle. It only detects -ve cycle.

*/


class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int direction, int wt){
        if(direction == 1){
            adjList[u].push_back({v, wt});
        }else{
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }


    void print(){
        for(auto elm : adjList){
            cout << elm.first << " -> { ";
            for(auto nbr : elm.second){
                cout << "{ " << nbr.first << ", " << nbr.second << " }";
            }
            cout << " }" << endl;
        }
    }


/*

The set in our implementation will store elements according to the first element of the pair, which is the distance. 
This is because the default comparison for std::pair in C++ compares the first element first, and if they are equal, 
then it compares the second element.

*/


    // Dijkstra algo
    void dijkstraAlgo(int src, int dst, int n){
        set<pair<int, int>> st;
        vector<int> distance(n+1, INT_MAX);

        // initial state in set, (0, src) i.e. (dist from src, src) 
        st.insert({0, src});
        distance[src] = 0; // dist from src to src is 0

        while(!st.empty()){
            auto topElement = st.begin();
			pair<int, int> topPair = *topElement;
			int topDist = topPair.first;
			int topNode = topPair.second;
            // remove first elm from set
            st.erase(st.begin());

            // update neighbour distance array & set with minm distance
            for(pair<int, int> nbr : adjList[topNode]){
                int nbrNode = nbr.first;
                int nbrWt = nbr.second;

                // (top node ka dist + distance from top to its nbr) < previously stored distance  
                if(topDist + nbrWt < distance[nbrNode]){
                    // find & delete previously stored entry for this nbrNode 
                    auto prevEntry = st.find({distance[nbrNode], nbrNode});
                    if(prevEntry != st.end()){
                        st.erase(prevEntry);
                    }

                    // new minm dist found so update both distance array & set
                    distance[nbrNode] = topDist+nbrWt; // update min distance array

                    st.insert({topDist+nbrWt, nbrNode}); // insert updated distane in set
                }
            }
        }


        // print min distance
        for(auto i : distance)
            cout << i << " ";
        cout << endl;
    }


};


int main(){
    Graph g;
    g.addEdge(1, 6, 0, 14);
    g.addEdge(1, 3, 0, 9);
    g.addEdge(1, 2, 0, 7);
    g.addEdge(2, 3, 0, 10);
    g.addEdge(2, 4, 0, 15);
    g.addEdge(3, 4, 0, 11);
    g.addEdge(6, 3, 0, 2);
    g.addEdge(6, 5, 0, 9);
    g.addEdge(5, 4, 0, 6);

    

    g.dijkstraAlgo(6, 4, 6);


    return 0;
}