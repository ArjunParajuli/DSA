 #include<bits/stdc++.h>
 using namespace std;


 // codehelp class 6

 /*
 
 DFS se 'more than one rotten oranges in grid' wala case mai nahi chalega
 so use BFS
 
 eg case :- grid=[[2 1 1], [1 1 1], [0 1 2]]

algo:
- initially insert all cells with rotten oranges(i.e. 2) in queue
- (bfs alog now) pop out from queue and update the time and also insert required coordinates. 

 */


 bool isFresh(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
            return true;
        }
        return false;
    }

    void bfs(vector<vector<int>>& grid, int &reqTime, queue<pair<pair<int, int>, int>> &q){
        
        while(!q.empty()){
            pair<pair<int, int>, int> front = q.front();
            q.pop();

            pair<int, int> frontCoordinates = front.first;
            int frontTime = front.second;
            int currx = frontCoordinates.first;
            int curry = frontCoordinates.second;

            int cx[]={-1, 0, 1, 0};
            int cy[]={0, 1, 0, -1};
            for(int k=0;k<4;k++){
                int newx = currx+cx[k];
                int newy = curry+cy[k];

                // update reqTime 
                if(isFresh(newx, newy, grid)){
                    q.push( {{newx, newy}, frontTime+1} );
                    reqTime = max(reqTime, frontTime+1);
                    grid[newx][newy] = 2;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int reqTime=0;

        // {coordinates, time}
        queue<pair<pair<int, int>, int>> q;

        // insert in queue all rotten
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    // initially time 0 for all rotten tomatoes
                    q.push({ {i, j}, 0 });
                }
            }
        }

        // bfs
        bfs(grid, reqTime, q);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return reqTime;
    }