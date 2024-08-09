#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*

codehelp class 4

QUE: Shortest path in directed weighted graph. Also called single sorce shortest path.

can't use BFS here bcoz weights are given and BFS gives the path containing less number of nodes. 

DFS used bcoz as we need the shortest path, we must explore all posiible paths & all possibilities means recursion.

topological sort is used bcoz we're choosing the node which is independent(i.e. jiski indegree is 0), so that we get minm distance


algo:
- find topological ordering
- now pop elm from stack and fill up the distance array


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




    void topologicalSortDFS(int src, unordered_map<int, int> &visited, stack<int> &st){
        visited[src] = true;
        for(auto nbr : adjList[src]){
            int nbrNode = nbr.first;
            if(!visited[nbrNode]){
                topologicalSortDFS(nbrNode, visited, st);
            }
        }
        // backtrack
        st.push(src);
    }


    void shortestPathFinder(stack<int> &st){
        vector<int> shortDist(adjList.size(), INT_MAX);
        
        // intital source
        int src = st.top();
        st.pop(); // remove top elm bcoz top elm is src node initially
        shortDist[src] = 0; // distance of src to src is 0 (i.e. 0 to 0 distance is 0)

        // update neighbour distance for source node
        for(auto nbrPair : adjList[src]){
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            // agar curr src tak ka dist + (distn betn currsrc & currnbr) < previously stored shortest distance
           if(shortDist[src] + nbrDist < shortDist[nbrNode])
                shortDist[nbrNode] = shortDist[src]+nbrDist; // take minm of prev distance & newDistance from this src node
        }

        // apply same logic until stack goes empty
        while(!st.empty()){
            int src = st.top();
            st.pop();

        // update neighbour distance for curr source node
        for(auto nbrPair : adjList[src]){
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if(shortDist[src] + nbrDist < shortDist[nbrNode])
                shortDist[nbrNode] = shortDist[src]+nbrDist; // take minm of prev distance & newDistance from this src node
        }
        }

        // printing distance array
        for(auto it : shortDist)
            cout << it << " ";
        cout << endl;
    }

    
    // Main Func (find topologicalSort and fill the distance arr)
    // shortest distn in directed weighted graph using DFS
    void shortestDistance(int src){
        vector<int> distance;

        stack<int> st;
        unordered_map<int, int> visited;

        // find topological sort ordering
        topologicalSortDFS(src, visited, st);

        // fill distance array
        shortestPathFinder(st);
        
    }

};



int main(){
    Graph g;
    g.addEdge(0, 1, 1, 5);
    g.addEdge(0, 2, 1, 3);
    g.addEdge(1, 3, 1, 3);
    g.addEdge(2, 1, 1, 2);
    g.addEdge(2, 3, 1, 5);
    g.addEdge(2, 4, 1, 6);
    g.addEdge(4, 3, 1, 1);

    g.shortestDistance(0);

    return 0;
}