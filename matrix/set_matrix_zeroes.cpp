#include <bits/stdc++.h>
using namespace std;

// striver YT: watch it again

// better approach: use two arrays to keep track of 0 elm's row index & col index 
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n=matrix[0].size();
    vector<int> row(m,0); 
    vector<int> col(n,0); 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                // curr elm is 0 so mark its row & col index as 1
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if curr row or col was marked 1 then mark the current cell as 0
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    }


// optimal: constane space i.e. use the first row & first col as the two arrays for marking 0 elm's indexes
/*
algo: instead of using two extra matrices row and col, we will use the 1st row and 1st column of the given matrix to keep a track of the cells that need to be marked
 with 0. But here comes a problem. If we try to use the 1st row and 1st column to serve the purpose, the cell matrix[0][0] is taken twice. 
 To solve this problem we will take an extra variable col0 initialized with 1. Now the entire 1st row of the matrix will serve the purpose of the row array.
  And the 1st column from (0,1) to (0,m-1) with the col0 variable will serve the purpose of the col array

*/

 void setZeroes(vector<vector<int>>& a) {
        int col0=1;
        int m = a.size(), n = a[0].size();
        // store 0 elm's row index & col index
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && a[0][j]==0) 
                    a[0][0] = 0;
                if(j==0 && a[i][0]==0)
                    col0=0;
                
                if(j!=0 && a[i][j] == 0){  // except when j==0
                    a[0][j]=0;
                    a[i][0]=0;
                }
            }
        }

    // set 0 from (1,1) to (m,n)
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(a[i][0] == 0 || a[0][j]==0){
                    a[i][j]=0;
                }
            }
        }

    // process for first row & first col

        if(a[0][0] == 0){
            for(int i=0;i<n;i++){
                a[0][i] = 0;
            }
        }

        if(col0 == 0){
            for(int i=0;i<m;i++){
                a[i][0] = 0;
            }
        }

    }
