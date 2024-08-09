#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
codehelp dp class 5

algo:
- same as longest_increasing_subsequence just change the condition for include. i.e. replace (cuboids[curr] > cuboids[prev]) with function to check if 
    secondlast(prev index) cuboid can be put above the last(curr index) cuboid. 

*/


// kya prev cuboid ko curr cuboid k upar rakhsakte hai ki nai
    bool check(vector<int> &curr, vector<int> &prev){
        // curr denotes big cuboid & prev is small 
        if(curr[0] >= prev[0] && curr[1] >= prev[1] && curr[2] >= prev[2]){
            return true;
        } else
            return false;
    }


// Memoization soln (curr & prev respresent the row index of the 2d cuboids array)
int solveMemo(vector<vector<int>>& cuboids, int curr, int prev, vector<vector<int>> &dp){
        if(curr >= cuboids.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int include = 0;
        if(prev == -1 || check(cuboids[curr], cuboids[prev])){
            include = cuboids[curr][2] + solveMemo(cuboids, curr+1, curr, dp);
        }
        int exclude = 0 + solveMemo(cuboids, curr+1, prev,  dp);

        return dp[curr][prev+1] = max(include, exclude);
    }

    int lengthOfLISMemoization(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        // both prev & curr go upto last elm so size n+1
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int prev=-1, curr=0;
        return solveMemo(cuboids, curr, prev, dp);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid : cuboids){ // use '&' so that original array gets sorted, else copy will be created & sorted
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end()); // sorts accn to first elm bcoz we want maxm height
        return lengthOfLISMemoization(cuboids);
    }

    

    // Tabulation solution
    int lengthOfLISTabulation(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // base case analysis, so initialize all to 0

        for(int curr=n-1;curr>=0;curr--){  // curr denotes index of last cuboid
            for(int prev=curr-1;prev>=-1;prev--){ // prev denotes index of secondlast cuboid
                int include = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev])){
                    include = cuboids[curr][2] + dp[curr+1][curr+1];  // replace 1 with height bcoz we're calculating maxm height here
                }
                int exclude = 0 + dp[curr+1][prev+1]; 
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];  // dp[0][-1+1] shifting
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // we can rearrange the width, height, length according to our need
        // sort so that smallest ones appear first
        for(auto &cuboid : cuboids){ // use '&' so that original array gets sorted, else copy will be created & sorted
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end()); // sorts accn to first elm bcoz we want maxm height
        return lengthOfLISTabulation(cuboids);
    }
