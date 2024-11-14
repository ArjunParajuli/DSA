    #include<bits/stdc++.h>
    using namespace std;

// recursion
/*
- at each step call recursion for right and down 
time: O(2^(m+n)) bcoz depth of the tree is m + n - 2 (the number of moves to reach the bottom-right corner).
*/
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i == m-1 && j == n-1) return grid[i][j];

        int d = INT_MAX;
        if(i+1 < m){
            d = grid[i][j] + solve(grid, i+1, j, m, n);
        }

        int r = INT_MAX;
        if(j+1 < n){
            r = grid[i][j] + solve(grid, i, j+1, m, n);
        }

        return min(r, d);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        return solve(grid, 0, 0, m, n);
    }

// memoized
       int solve(vector<vector<int>>& grid, vector<vector<int>> &dp, int i, int j, int m, int n){
        if(i == m-1 && j == n-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int d = INT_MAX;
        if(i+1 < m){
            d = grid[i][j] + solve(grid, dp, i+1, j, m, n);
        }

        int r = INT_MAX;
        if(j+1 < n){
            r = grid[i][j] + solve(grid, dp, i, j+1, m, n);
        }

        return dp[i][j]=min(r, d);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(grid, dp, 0, 0, m, n);
    }

    // tabulation
        int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                // base case handle inside loop bcoz if we start loop from m-2 and n-2 then we'll miss filling some boxes on the m-1 row and n-1 col
                if(i == m-1 && j == n-1){
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int d = INT_MAX;
                if(i+1 < m){
                    d = grid[i][j] + dp[i+1][j];
                }

                int r = INT_MAX;
                if(j+1 < n){
                    r = grid[i][j] + dp[i][j+1];
                }

                dp[i][j]=min(r, d);
            }
        }

        return dp[0][0];
    }

    // space optimized (bcoz its about next row and curr row, we can spacec optimize) We see that we only need the next row and column, in order to calculate dp[i][j]. Therefore we can space optimize it.
    // replace dp[i+1][j] with next[j] arr as it represents next row 
    // replace dp[i][l+1] with curr[j+1] as it represents next col
    // and ofc, dp[i][j] with curr[j] as we're filling up the curr row & dont forget to do next = curr before going for filling next row 
        int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> next(n+1, 0);

        for(int i=m-1;i>=0;i--){
            vector<int> curr(n+1, 0);
            for(int j=n-1;j>=0;j--){
                if(i == m-1 && j == n-1){
                    curr[j] = grid[i][j];
                    continue;
                }

                int d = INT_MAX;
                if(i+1 < m){
                    d = grid[i][j] + next[j];
                }

                int r = INT_MAX;
                if(j+1 < n){
                    r = grid[i][j] + curr[j+1];
                }

                curr[j]=min(r, d);
            }
            next = curr;
        }

        return next[0];
    }