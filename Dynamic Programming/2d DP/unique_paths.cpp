    #include<bits/stdc++.h>
    using namespace std;
    

    /*
    
    Striver YT


    
    */
    
    // recursive
    int solve(int m, int n, int i, int j){
        // base
        if(i == m-1 && j == n-1)
            return 1;

        int cnt = 0;
        // right
        if(j+1 < n){
            cnt += solve(m, n, i, j+1); 
        }

        // down
        if(i+1 < m){
            cnt += solve(m, n, i+1, j); 
        }
        return cnt;
    }

    int uniquePaths(int m, int n) {
        return solve(m, n, 0, 0);
    }


    // memoization
        int solve(int m, int n, int i, int j, vector<vector<int>> &dp){
        // base
        if(i == m-1 && j == n-1)
            return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int cnt = 0;
        // right
        if(j+1 < n){
            cnt += solve(m, n, i, j+1, dp); 
        }

        // down
        if(i+1 < m){
            cnt += solve(m, n, i+1, j, dp); 
        }
        return dp[i][j]=cnt;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp);
    }

    // tabulation
 int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if (i == m-1 && j == n-1) {
                    dp[i][j] = 1;
                    continue; // Skip the rest of the loop and continue with the next iteration.
                }
                int cnt = 0;
                if(j+1 < n){
                    cnt += dp[i][j+1]; 
                }

                if(i+1 < m){
                    cnt += dp[i+1][j]; 
                }
                dp[i][j]=cnt;
            }
        }

        return dp[0][0];
    }

    // space optimized
    // If there is a previous row and previous column, then we can space optimize it
    // dp[i][j+1] can be denoted by curr[j+1] & dp[i+1][j] can be denoted by next[j] 

  int uniquePaths(int m, int n) {
        // using row size
        vector<int> next(n+1, 0);

        for(int i=m-1;i>=0;i--){
            vector<int> curr(n+1, 0);
            for(int j=n-1;j>=0;j--){
                if (i == m-1 && j == n-1) {
                    curr[j] = 1;
                    continue; // Skip the rest of the loop and continue with the next iteration.
                }
                int cnt = 0;
                if(j+1 < n){
                    cnt += curr[j+1]; 
                }

                if(i+1 < m){
                    cnt += next[j]; 
                }
                curr[j]=cnt;
            }
            next = curr;
        }

        return next[0];
    }