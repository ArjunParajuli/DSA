    #include<bits/stdc++.h>
    using namespace std;

// almost same as unique paths 
        int solve(vector<vector<int>>& mat, int i, int j, int m, int n){
        if(i==m-1 && j==n-1) return 1;

        int cnt=0;
        // down
        if(i+1 < m && mat[i+1][j] == 0){
            cnt += solve(mat, i+1, j, m, n);
        }

        //right
        if(j+1 < n && mat[i][j+1] == 0){
            cnt += solve(mat, i, j+1, m, n);
        }

        return cnt;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        if(mat[0][0] == 1) return 0;
        return solve(mat, 0, 0, mat.size(), mat[0].size());
    }

        int solve(vector<vector<int>>& mat, vector<vector<int>> &dp, int i, int j, int m, int n){
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int cnt=0;
        // down
        if(i+1 < m && mat[i+1][j] == 0){
            cnt += solve(mat, dp, i+1, j, m, n);
        }

        //right
        if(j+1 < n && mat[i][j+1] == 0){
            cnt += solve(mat, dp, i, j+1, m, n);
        }

        return dp[i][j]=cnt;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        if(mat[0][0] == 1) return 0;
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(mat, dp, 0, 0, m, n);
    }