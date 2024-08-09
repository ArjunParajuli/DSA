 #include<bits/stdc++.h>
 using namespace std;

 /*
 codehelp class 6

 */
 


 // Using BFS
// time: (n^2) space: (n^2) for visited and queue

 bool isSafe(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1' && !vis[{i, j}])
            return true;
        return false;
    }

    void bfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[{i, j}] = true;
        while (!q.empty())
        {
            auto frontNode = q.front();
            q.pop();
            int tempX = frontNode.first;
            int tempY = frontNode.second;
            
            // new positions
            // up, right, down, left 
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++)
            {
                int newX = tempX + dx[k];
                int newY = tempY + dy[k];
                if (isSafe(newX, newY, grid, vis))
                {
                    q.push({newX, newY});
                    vis[{newX, newY}] = true;
                }
            }
        }
    }

    // algo: if land('1') found in grid, uss component ko pura visit karneke baad increment count of islands 
    // using bfs i.e. push all univisted neighbours of current comp and pop one by one and again push their corresponding neighbors. ye karnese ek component pura queue mai jata hai
    // and queue empty honeke baad wo component pura visit hogaya hai  

    int numIslands(vector<vector<char>> &grid)
    {
        map<pair<int, int>, bool> vis; // {x-cordinate, y-cordinate} -> bool
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[{i, j}] && grid[i][j] == '1')
                {
                    bfs(i, j, grid, vis);
                    // queue empty so visited all possible nodes for current connected component i.e. one island found
                    count++;
                }
            }
        }
        return count;
    }


    // dfs (same way just using dfs instead of bfs)
    bool isSafe(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1' && !vis[{i, j}])
            return true;
        return false;
    }

    void dfs(int i, int j, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int k = 0; k < 4; k++)
            {
                int newX = i + dx[k];
                int newY = j + dy[k];
                if (isSafe(newX, newY, grid, vis))
                {
                    vis[{newX, newY}] = true;
                    dfs(newX, newY, grid, vis);
                }
            }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        map<pair<int, int>, bool> vis;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[{i, j}] && grid[i][j] == '1')
                {
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }