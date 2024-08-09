#include<iostream>
#include<vector>
using namespace std;

/*
codehelp: dp class 4

#imp ques
recursive solution algo:
1. if both strings chars match, ans = 1+recursivecall(next index of both str)
2. if chars don't match, two cases arise:
  i. once call recursion by excluding curr char of 1st string
  ii. once call recursion by excluding curr char of 2nd string
  - now take the maxm ans from these two cases
3. return maxm ans betn steps 1 and 2   

*/

// 1. recursion
int solve(string text1, int i, string text2, int j){
    // base case, when no char left, length is 0
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        int ans; 
        // either string chars match or they don't match  
        if(text1[i] == text2[j]){
            ans = 1+solve(text1, i+1, text2, j+1);
        }else{ // chars don't match so exclude char from each string once
            int excludeStr1 = 0+solve(text1, i+1, text2, j);
            int excludeStr2 = 0+solve(text1, i, text2, j+1);

            // take the maxm one as we need longest
            ans = max(excludeStr1, excludeStr2);
        }
         return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, 0, text2, 0);
    }

    // 2. memoization  [ NOTE: if memoization mai vi TLE marra hai then pass parameters by reference ]
     int solveMemo(string &text1, int i, string &text2, int j, vector<vector<int>> &dp){
        if(i >= text1.size() || j >= text2.size()){
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans;
        if(text1[i] == text2[j]){
            ans = 1+solveMemo(text1, i+1, text2, j+1, dp);
        }else{
            int excludeStr1 = 0+solveMemo(text1, i+1, text2, j, dp);
            int excludeStr2 = 0+solveMemo(text1, i, text2, j+1, dp);

            ans = max(excludeStr1, excludeStr2);
        }
         return dp[i][j] = ans;
    }

    int longestCommonSubsequenceMemoization(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1)); 
        int i=0, j=0;
        return solveMemo(text1, i, text2, j, dp);
    }

// 3. Tabulation [ base case analyse & replace recursive relation with dp array ]

int longestCommonSubsequenceTabulation(string text1, string text2){
    // base case analysis ( each last col must have 0, so just initialize all dp arr with 0 )
     vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0)); 
        
        // bottom up approach so do opp. of memoization, so we go from end to start
        for(int i=text1.size()-1;i>=0;i--){ // start from n-1 index bcoz last col is 0
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    int excludeStr1 = 0+dp[i+1][j];
                    int excludeStr2 = 0+dp[i][j+1];

                    dp[i][j] = max(excludeStr1, excludeStr2);
                }
            }
        }

        return dp[0][0]; // NOTE: jo recursive call mai pass kiya hai wahi index par milega ans
}

// 4. space optimization, NOTE: for 2d dp, space optimize to 1d array first and then to using 3 variables if possible  
// ( dp[i][j] depends on dp[i+1][j+1], dp[i+1][j] and dp[i][j+1] hence we can do it using 1d array bcoz we just need next col array and curr col array )

int longestCommonSubsequenceSpaceOptimized(string text1, string text2){ // (O(n^2) space optimized to 2*O(n))
    // take size of both arr text1.size() bcoz we're moving colwise & no. of cells in each col = number of rows of the matrix
    // so, no. of rows k size ka hona chahiye both arrays and no. of rows ko text1.size() se denote kiya hai
     vector<int> nextCol(text1.size()+1, 0); // denotes last column initially & we know each cell in last col has 0 
     vector<int> currCol(text1.size()+1, 0); // deontes second last column(current) initially
        
// inner loop & outer loop interchange bcoz we're moving column wise [previously we were moving rowwise]
// (i.e. next repr last col and curr repr secondlast col initially, & we shift them towards first col)

        for(int j=text2.size()-1;j>=0;j--){
            for(int i=text1.size()-1;i>=0;i--){ // start from n-1 index bcoz last col is already set to 0
                if(text1[i] == text2[j]){
                    // j+1 matlab next wali col, so replace dp[i+1][j+1] with next[i+1] & replace dp[i][j] with curr[i] bcoz same col ko curr repr karta hai
                    currCol[i] = 1+nextCol[i+1];
                }else{
                    int excludeStr1 = 0+currCol[i+1]; // replace dp[i+1][j] with curr[i+1] bcoz j means same col which is reapresented by curr 
                    int excludeStr2 = 0+nextCol[i]; // replace dp[i][j+1] with next[i]

                    currCol[i] = max(excludeStr1, excludeStr2);
                }
            }
            nextCol = currCol;
        }

        return currCol[0]; 

}


// without loop change ( every problem can be done without loop change also )
// take size of both arr text2.size() bcoz we're moving rowwise & no. of cells in each row = number of cols of the matrix
// so, no. of cols ke size ka hona chahiye both arrays and no. of cols ko text2.size() se denote kiya hai

int longestCommonSubsequenceTabulationSpaceOptimizedNoLoopChange(string text1, string text2){ 
    vector<int> nextRow(text2.size()+1, 0); // denotes last row initially & we know each cell in last row has 0 
    vector<int> currRow(text2.size()+1, 0); // deontes second last row(current) initially
        
    
        for(int i=text1.size()-1;i>=0;i--){ // start from n-1 index bcoz last row is 0
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    currRow[j] = 1+nextRow[j+1];
                }else{
                    int excludeStr1 = 0+nextRow[j];
                    int excludeStr2 = 0+currRow[j+1];

                    currRow[j] = max(excludeStr1, excludeStr2);
                }
            }
            nextRow = currRow;
        }

        return currRow[0]; // NOTE: jo recursive call mai pass kiya hai wahi index par milega ans
}

