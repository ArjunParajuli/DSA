#include<bits/stdc++.h>
using namespace std;

    /*

    How did we identify it as graph problem?
    -> firstly seeing the dependency of second elm on first & also by observing the cycle betn the elms
    
    algo:
    - create a map of given array
    - find topological sort of the given array
    - if num of elm in topo sort is same as number of given courses then return true;
    
    */

    
    void topoSortBFS(unordered_map<int, list<int>> &adjList, int &cnt, int &numCourses){
        queue<int> q;
        unordered_map<int, int> indegree;


        // store indegree of each node
        for(auto elm : adjList){
            for(auto nbr : elm.second){
                indegree[nbr]++;
            }
        } 

        // insert nodes with indegree 0 
        for(int node=0;node<numCourses;node++){
            if(indegree[node] == 0)
                q.push(node);
        }

        // now bfs logic
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            // count number of elms in topological sort
            cnt++;

            // removed the frontnode so iske sarey neighbours ka indegree decrement karo
            for(auto nbr : adjList[front]){
                indegree[nbr]--;
                // insert all neighbours with indegree 0
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        cout << cnt;
        }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        int cnt=0;

        // create a graph for all elms of prerequisites
        for(auto elm : prerequisites){
            int u = elm[0];
            int v = elm[1];
            adjList[u].push_back(v);
        }
        topoSortBFS(adjList, cnt, numCourses);

        return cnt==numCourses;
    }



    // Course Schedule 2
    /*
    same as course schedule 1, just return the topoSort array here
    */
     void topoSortBFS(unordered_map<int, list<int>> &adjList, int &cnt, int &numCourses, vector<int> &topoSort){
        queue<int> q;
        unordered_map<int, int> indegree;


        // store indegree of each node
        for(auto elm : adjList){
            for(auto nbr : elm.second){
                indegree[nbr]++;
            }
        } 

        // insert nodes with indegree 0 
        for(int node=0;node<numCourses;node++){
            if(indegree[node] == 0)
                q.push(node);
        }

        // now bfs logic
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            // count number of elms in topological sort
            cnt++;
            topoSort.push_back(front);

            // removed the frontnode so iske sarey neighbours ka indegree decrement karo
            for(auto nbr : adjList[front]){
                indegree[nbr]--;
                // insert all neighbours with indegree 0
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        cout << cnt;
        }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;
        int cnt=0;

        // create a graph for all elms of prerequisites
        for(auto elm : prerequisites){
            int u = elm[0];
            int v = elm[1];
            adjList[v].push_back(u);
        }
        vector<int> topoSort;
        topoSortBFS(adjList, cnt, numCourses, topoSort);

        if(topoSort.size()==numCourses)
            return topoSort;
        else 
            return {};
    }