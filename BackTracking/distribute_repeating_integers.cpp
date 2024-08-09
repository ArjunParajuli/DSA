#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

       // currCustomer iterates in count arr
    bool solve(int currCustomer, vector<int>& count, vector<int>& quantity){
        // currCustomer exceeds all elms in count
        if(currCustomer == quantity.size()){
            return true;
        }

        // for each elm in quantity, we check if any elm in count can satisfy condition
        for(int i=0;i<count.size(); i++){
            // check if current is satisfied
            if(count[i] >= quantity[currCustomer]){
                count[i] -= quantity[currCustomer];
                // check for others
                if(solve(currCustomer+1, count, quantity)){
                    return true;
                }
                // backtrack
                count[i] += quantity[currCustomer];
            }
        }
        return false;
    }

     bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> mp;
        // save frequency of integers of nums
        for(auto itr:nums){
            mp[itr]++;
        }
        // store all frequencies in count arr
        vector<int> count;
        for(auto itr : mp){
            count.push_back(itr.second);
        }
        // sort in desc so that highest quantity ko pehle hi check kare 
        // agar highest quantity ko satisfy nahi karpayega toh return so that jaldi false condition detect ho
        sort(quantity.rbegin(), quantity.rend());
       return solve(0, count, quantity);
    }

    int main(){
        vector<int> nums = {1,1,2,2,2,2,3,3};
        vector<int> quantity = {2,2,3};

        cout << canDistribute(nums, quantity);

        return 0;
    }