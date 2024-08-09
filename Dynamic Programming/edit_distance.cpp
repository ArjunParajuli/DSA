#include<iostream>
#include<vector>
using namespace std;

/*
codehelp dp 4
# VVIMP ques

algo:
- two cases might arise
1. if chars match, go forward & check other chars
2. if chars don't match, three operations can be done
    - insertion
    - deletion
    - replace
3. return min answer between the three oprn

*/

// 1. Recursion
 int solve(string &word1, int i, string &word2, int j){
        // base case
        if(i >= word1.size()){ // eg: w1=hor, w2=horse 
            // means len of word2 might be greater than length of word1
            return word2.size()-j; // w1 ke sarey chars process hogaye & w1 ko w2 banane k liye w2 mai bache huye chars ko insert karna padega
        }
        if(j >= word2.size()){ // eg: w1=horse, w2=hor 
             // means len of word1 might be greater than length of word2
            return word1.size()-i; // w2 ke sarey chars process hogaye & w1 banchuka hai w2 mai so ab w1 mai bache huye chars ko remove karna padega
        }


        int ans = INT_MAX;
        // chars match, so no operation needed hence 0 add karo
        if(word1[i] == word2[j]){
            ans = 0 + solve(word1, i+1, word2, j+1);
        }else{
            // chars don't match, so operation needed so 1 add karo
            int insert = 1 + solve(word1, i, word2, j+1);
            int remove = 1 + solve(word1, i+1, word2, j);
            int replace = 1 + solve(word1, i+1, word2, j+1);

            // return minm operations
            ans = min(insert, min(remove, replace));
        }

        return ans;
    }

    int minDistance(string word1, string word2) {
        int i=0, j=0;
        return solve(word1, i, word2, j);
    }



// 2. Memoization
 int solveMemo(string &word1, int i, string &word2, int j, vector<vector<int>> &dp){
        // base case
        if(i >= word1.size()){
            // means len of word2 might be greater than length of word1
            return word2.size()-j;
        }
        if(j >= word2.size()){
             // means len of word1 might be greater than length of word2
            return word1.size()-i;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        if(word1[i] == word2[j]){
            ans = 0 + solveMemo(word1, i+1, word2, j+1, dp);
        }else{
            int insert = 1 + solveMemo(word1, i, word2, j+1, dp);
            int remove = 1 + solveMemo(word1, i+1, word2, j, dp);
            int replace = 1 + solveMemo(word1, i+1, word2, j+1, dp);

            ans = min(insert, min(remove, replace));
        }

        return dp[i][j] = ans;
    }

    int minDistanceMemoization(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1)); // i depends on w1 size and j depends on w2 size
        int i=0, j=0;
        return solveMemo(word1, i, word2, j, dp);
    }


// 3. Tabulation [ base case analyse and convert recursive solution in dp array ]
int minDistanceTabulation(string word1, string word2) {
        vector<vector<int>> dp((word1.size())+1, vector<int>((word2.size())+1, -1));

        // base case analyse( matrix ka last col and last row fill karo )  [i denotes row, j denotes col]
        // for row equal to w1.size(), insert w2.size()-col in all cells [last row ka harek col mai]
        for(int col=0;col<=word2.size();col++){ // iss row ke sarey places mai dalna hai so we must traverse in column
            dp[word1.size()][col] = word2.size()-col;
        }

        // for col equal to w2.size(), insert w1.size()-row in all cells [last col ka harek row mai]
        for(int row=0;row<=word1.size();row++){ // iss col ke sarey places mai dalna hai so we must traverse in row
            dp[row][word2.size()] = word1.size()-row;
        }

        // memoization se ulta chalna hai
        for(int i=word1.size()-1;i>=0;i--){
            for(int j=word2.size()-1;j>=0;j--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = 0 + dp[i+1][j+1];
                }else{
                    int insert = 1 +dp[i][j+1];
                    int remove = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];

                    ans = min(insert, min(remove, replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];  // jo recursive call mai pass kiya tha, wohi return karna hai
    }


// 4. space optimized ( dp[i][j] is depending on dp[i][j+1], dp[i+1][j] & dp[i+1][j+1] )
// i.e. dp[i][j] khudke col pe and next col pe depend karra hai, so 1d array se kam hojayega

int minDistanceSpaceOptimized(string word1, string word2) {
        // arr size must be no. of rows i.e. word1.size() here
        vector<int> next(word1.size()+1, -1);
        vector<int> curr(word1.size()+1, -1);

        // curr and next represent columns in the matrix, so rows mai nai dalsakte kyuki rows hamamre pass available hi nahi hai
        // for(int col=0;col<=word2.size();col++){ 
        //     dp[word1.size()][col] = word2.size()-col;
        // }
        // instead of this loop, harek col ka last cell mai fill karna hoga

        // next arr repr last col, so fill it
        for(int row=0;row<=word1.size();row++){ // last col ke sarey places mai dalna hai so we must traverse in row
            next[row] = word1.size()-row;
        }

        // col wise chalna hai, so interchange loop
        for(int j=word2.size()-1;j>=0;j--){ // ye wala loop harek col k liye sarey row pe jata hai using inner loop
        // harek naye col ka last cell mai ans insert karo
            curr[word1.size()] = word2.size()-j;   // ##
            for(int i=word1.size()-1;i>=0;i--){
                int ans = 0;
                if(word1[i] == word2[j]){
                    ans = 0 + next[i+1];
                }else{
                    int insert = 1 + next[i];  // [j+1] means next col, so use next arr
                    int remove = 1 + curr[i+1]; // [i+1] means next row of curr col, so use curr arr
                    int replace = 1 + next[i+1]; // [i+1][j+1] means next row of next col, so use next[i+1]

                    ans = min(insert, min(remove, replace));
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return next[0];  // jo recursive call mai pass kiya tha, wohi return karna hai
    }
