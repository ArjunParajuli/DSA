#include <bits/stdc++.h>
using namespace std;

/*
codehelp DP assignments

recursive algo: harek day k liye 1 day pass, 7 day pass & 30 day pass lekar minm return karna hai 

*/

// Recursion Time: O(3^n) bcoz for each elm, we have 3 recursive calls forwarded & spcae O(n) bcoz at max n+1 recursive calls  
int solve(vector<int>& days, vector<int>& costs, int i){
        // base case 
        if(i >= days.size()){
            return 0;
        }

        // 1 day cost 
        // ek din ka cost & solve for next day bcoz one day pass works for single day only
        int costFor1Day = costs[0] + solve(days, costs, i+1); // pass ends after 1 day

        // 7 day cost
        int j=i;  // j denotes current day index
        int passEndDay = days[j] + 7 - 1;  // pass ends after 7 days
        // inside bound hona chahiye & curr day pass end day ke baad nahi hona chahiye
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int costFor7Day = costs[1] + solve(days, costs, j); // ab jth day par naya pass lena padega

        // 30 day cost (same as 7 day cost)
        j=i;
        passEndDay = days[j] + 30 - 1;  // pass ends after 30 days
        // inside bound hona chahiye & curr day pass end day ke baad nahi hona chahiye
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int costFor30Day = costs[2] + solve(days, costs, j); // ab jth day par naya pass lena padega

        return min(costFor1Day, min(costFor7Day, costFor30Day));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i=0;
        return solve(days, costs, i);
    }


// 2. Memoization, time:O(n^2) (overlapping subproblems seen so instead of calling recursive function again & again for same i, we store its value)
// (create dp arr, check if already present in dp arr, save in dp arr and return)
int solveMemo(vector<int>& days, vector<int>& costs, int i, vector<int> &dp){
        // base case 
        if(i >= days.size()){
            return 0;
        }

        if(dp[i] != -1)
            return dp[i];

        // 1 day cost 
        // ek din ka cost & solve for next day bcoz one day pass works for single day only
        int costFor1Day = costs[0] + solveMemo(days, costs, i+1, dp);

        // 7 day cost
        int j=i;
        int passEndDay = days[j] + 7 - 1;  // pass ends after 7 days
        // inside bound hona chahiye & curr day pass end day ke baad nahi hona chahiye
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int costFor7Day = costs[1] + solveMemo(days, costs, j, dp); // ab jth day par naya pass lena padega

        // 30 day cost (same as 7 day cost)
        j=i;
        passEndDay = days[j] + 30 - 1;  // pass ends after 7 days
        // inside bound hona chahiye & curr day pass end day ke baad nahi hona chahiye
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }
        int costFor30Day = costs[2] + solveMemo(days, costs, j, dp); // ab jth day par naya pass lena padega

        return dp[i] = min(costFor1Day, min(costFor7Day, costFor30Day));
    }

    int mincostTicketsMemoization(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        int i=0;
        return solveMemo(days, costs, i, dp);
    }


// 3. Tabulation, time: O(n^2) space: O(n)
int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        int n = days.size();

        // base case analyse
        dp[n] = 0;

        // move opposite direction than topdown  & convert recursive relation into dp array
        for(int i=n-1;i>=0;i--){
            int costFor1Day = costs[0] + dp[i+1];

            int j=i;
            int passEndDay = days[j] + 7 - 1;  
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int costFor7Day = costs[1] + dp[j]; 

            j=i;
            passEndDay = days[j] + 30 - 1;  
            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }
            int costFor30Day = costs[2] + dp[j]; 

            dp[i] = min(costFor1Day, min(costFor7Day, costFor30Day));
        } 
       
        return dp[0];
    }