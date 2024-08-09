#include<bits/stdc++.h>
using namespace std;

/*
codehelp Graph class 3

topological sort: a linear ordering of vertices such that for every edge u->v, u comes before v in that ordering. 
Topological sort can only be applied to a directed acyclic graph.

Application of topological ordering: eg: 0->1->2->3 then we can find the dependenceies of each node i.e. the first node is independent, second is dependent on first
and the last node has the most dependency among these nodes 


/*
algo using dfs:
- dfs traverse starting from first src node,
- visit src and explore all unvisited neighbours of src through recursive call and after all nodes are visited, 
- before returning from recursive calls(backtracking), we insert that node in stack.
- finally pop all elms from stack to get the topological sort order


algo using bfs: (first node is independent of others & the dependency gradually increases)
Logic: jiski indegree 0 hai wo independent node hai & independent node comes first in topological sort.
- store indegree of all nodes
- insert in queue the node whose indegree is 0 


Q) Why Topological Sort is not possible for graphs with undirected edges?
This is due to the fact that undirected edge between two vertices u and v means, there is an edge from u to v as well as from v to u. 
Because of this both the nodes u and v depend upon each other and none of them can appear before the other in the topological ordering
without creating a contradiction. Topo sort follows, for every edge u->v, u comes before v in that ordering. 

*/

class Graph{
    public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool directed){
        if(directed){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto elm : adjList){
            int node = elm.first;
            cout << node << "-> { ";
            for(auto nbr : adjList[node]){
                cout << nbr << ", ";
            }
            cout << " }" << endl;
        }
    }

// Using DFS    
    void topologicalSortDFS(int src, unordered_map<int, int> &visited, stack<int> &st){
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                topologicalSortDFS(nbr, visited, st);
            }
        }
        // backtracking 
        st.push(src);
    }


// Using BFS
   void topologicalSortBFS(){ // we don't need src bcoz node with indegree 0 is our curr src
        queue<int> q;
        unordered_map<int, int> indegree;


        // store indegree of each node
        for(auto elm : adjList){
            for(auto nbr : elm.second){
                indegree[nbr]++;
            }
        } 

        // insert nodes with indegree 0 
        for(int node=0;node<adjList.size();node++){
            if(indegree[node] == 0)
                q.push(node);
        }

        // now bfs logic
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            cout << front << " ";
            // removed the frontnode so iske sarey neighbours ka indegree decrement karo
            for(auto nbr : adjList[front]){
                indegree[nbr]--;
                // insert all neighbours with indegree 0
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

};



// GFG submitted soln (using DFS)
//using stack bcoz we're getting ans in correct order while popping. If used vector, we have to reverse ans
	void topologicalSort(int src, unordered_map<int, int> &visited, stack<int> &st, vector<int> adjList[]){
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                topologicalSort(nbr, visited, st, adjList);
            }
        }
         // backtracking (before returning from recursive call, push curr src node in stack)
        st.push(src);
    }
	
	vector<int> topoSortDFS(int V, vector<int> adjList[]) 
	{
	    vector<int> ans;
	    unordered_map<int, int> visited;
        stack<int> st;
        // fo handling disconnected graphs
	    for(int i=0;i<V;i++){
	        if(!visited[i])
      	        topologicalSort(i, visited, st, adjList);
	    }
        // take out ans
	    while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}



// GFG submitted soln using BFS
	vector<int> topologicalSortBFS(int V, vector<int> adjList[]){ // we don't need src bcoz node with indegree 0 is our curr src
        queue<int> q;
        unordered_map<int, int> indegree;

        vector<int> ans;

        // store indegree of each node
        for(int node=0;node<V;node++){
            for(int nbr : adjList[node]){
                indegree[nbr]++;
            }
        } 

        // insert nodes with indegree 0 
        for(int node=0;node<V;node++){
            if(indegree[node] == 0)
                q.push(node);
        }

        // now bfs logic
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            ans.push_back(front);
            
            // removed the frontnode so iske sarey neighbours ka indegree decrement karo
            for(auto nbr : adjList[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        return ans;
    }
	
	// Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adjList[]) 
	{
	    vector<int> ans;
	    return topologicalSortBFS(V, adjList);
         
	}




int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);

    // g.printGraph();

    // topo sort
    unordered_map<int, int> visited;
    stack<int> st;
    // g.topologicalSortDFS(0, visited, st);
    // vector<int> ans;
    // while(!st.empty()){
    //     ans.push_back(st.top());
    //     st.pop();
    // }

    // for(int i : ans)
    //     cout << i << " ";


    g.topologicalSortBFS();

    return 0;
}