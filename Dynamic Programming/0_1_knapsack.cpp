#include<iostream>
#include<vector>
using namespace std;

/*

2D DP:
Knapsack Problem:
codehelp: dp class 4

algo:
- ek baar curr elm ko include karke recursion call karo
- ek baar curr ko bina liye recursion call karo

*/

void printDPArray(vector<vector<int>> &dp){
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}


// 1. recursion
  int solve(int capacity, int wt[], int val[], int n, int index) {
       // base case
        if(index >= n){
            return 0;
        }
        
        int include = INT_MIN;
        // include
        if(wt[index] <= capacity) // condition bcoz including weight
           include = val[index] + solve(capacity-wt[index], wt, val, n, index+1); // knapsack mai current weight daldiya so decrment before sending capacity
        // exclude so no need to check
        int exclude = 0 + solve(capacity, wt, val, n, index+1);  // weight not included
        
        int maxm = max(include, exclude);
        return maxm; // return maxm of them
    }
    
    //Function to return max value that can be put in knapsack of capacity w.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       return solve(w, wt, val, n, 0);
    }


// 2. Memoization(capacity moving towards 0) [ dp[capacity][i] means particular capacity ka ith index, agar ispar already call jachuka hai toh firse call nakarna padey ]
     int solveMemo(int capacity, int wt[], int val[], int n, int index, vector<vector<int>> &dp) {
        // base case
        if(index >= n){
            return 0;
        }
        
        if(dp[capacity][index] != -1)
            return dp[capacity][index];
        
        int include = INT_MIN;
        if(wt[index] <= capacity)
           include = val[index] + solveMemo(capacity-wt[index], wt, val, n, index+1, dp);
        int exclude = 0 + solveMemo(capacity, wt, val, n, index+1, dp);
        
        dp[capacity][index] = max(include, exclude);
        return dp[capacity][index];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackMemoization(int capacity, int wt[], int val[], int n) 
    { 
       // 2d array bcoz capacity and i are changing
       // no.of rows: capacity+1, no.of cols: n+1
       vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1)); 
       int ans = solveMemo(capacity, wt, val, n, 0, dp);
    //    printDPArray(dp);
       return ans;
    }

// 3. Tabulation
    int knapSackTabulation(int capacity, int wt[], int val[], int n){
         vector<vector<int>> dp(capacity+1, vector<int>(n+1, -1));

         // base case analyse [each row ke nth index pe 0 rakho]
         for(int row=0;row<=capacity;row++){
            dp[row][n] = 0;
         }

         // capacity moving towards 0 in memoization so we move capacity in opposite direction in tabulation
         // two for loops bcoz two variables are changing
         for(int i=0;i<=capacity;i++){ // move from 0 to capacity (i denotes capacity here)
         // ans return kiya hai 0th col ka, means ans build hora hai last se 0th ki taraf (don't start from n bcoz nth index mai already 0 rakhdiya tha)
            for(int j=n-1;j>=0;j--){  // j denotes index here
                // recursive relation converted
                int include = INT_MIN;
                if(wt[j] <= i)
                    include = val[j] + dp[i-wt[j]][j+1];
                int exclude = 0 + dp[i][j+1];
                
                dp[i][j] = max(include, exclude);
            }
         }
         return dp[capacity][0]; // bcoz recursion mai capacity and index=0 pass kiya tha
    }

/*
 4. space optimization 
- basically dp[i][j] depends on dp[i-wt[j]][j+1] & dp[i][j+1] i.e. depends only on [j+1]th col, so we can do it using 1d array
- since we need only the (j+1)th and jth col, represent (j+1)th col with next and jth with curr
- move curr and next towards 0 (leftwards)

*/

int knapSackSpaceOptimized(int capacity, int wt[], int val[], int n){ // updated from tabulation
        // size must be of capacity+1 bcoz in tabulation, capacity represents no. of rows, hence each col must have capacity+1 fields (visualize by making table)
        vector<int> next(capacity+1, 0); // denotes last column initially & we know each last col has 0 
        vector<int> curr(capacity+1, -1); // deontes second last column(current) initially

// inner loop & outer loop interchange bcoz moving from end towards upwards
        for(int j=n-1;j>=0;j--){
         for(int i=0;i<=capacity;i++){   
                int include = INT_MIN;
                if(wt[j] <= i){
                    // tabulation ka (j+1)th col ka kam next vector karra hai, so replace dp[i-wt[j]][j+1] with next[i-wt[j]]
                    include = val[j] + next[i-wt[j]]; 
                }
                // replace dp[i][j+1] with next[i]
                int exclude = 0 + next[i];
                
                // replace dp[i][j] with curr[i] since jth(current) col is denoted by curr vector here
                curr[i] = max(include, exclude);
            }
            // shift leftwards
                next = curr;
         }
         return curr[capacity]; // bcoz recursion mai capacity and index=0 pass kiya tha 
    }

    int main(){
        int values[] = {1,2,3};
        int weight[] = {4,5,1};
        cout << knapSackMemoization(4, weight, values, 3);
        

        return 0;
    }