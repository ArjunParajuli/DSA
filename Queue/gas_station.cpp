#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int currfuel = 0, reqfuel = 0;
       int ans = 0;
       int n = gas.size();
       for(int i=0;i<n;i++){
           currfuel = currfuel + gas[i] - cost[i];
           if(currfuel < 0){
               reqfuel = reqfuel + abs(currfuel);
               currfuel = 0;
               ans = i+1;
           } 
       }
       if(currfuel-reqfuel < 0){
           return -1;
       }else{
           return ans;
       }
    }

int main(){
    

    return 0;
}