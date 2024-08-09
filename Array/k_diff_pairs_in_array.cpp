#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// time: O(nlogn) space:O(1)
 int findPairs(vector<int>& nums, int k) {  // two pointers
        sort(nums.begin(), nums.end()); 
        int i=0, j=1;
        int cnt = 0, n = nums.size();
        while(j<n){
            int d = nums[j]-nums[i];
            if(d == k){
                cnt++;
                int n1=nums[i], n2=nums[j];
                // ignore same pairs
                while(i<n && n1 == nums[i]) 
                    i++;
                while(j<n && n2 == nums[j])
                    j++;
            }
            else if(d > k)
                i++;
            else 
                j++;

            if( i==j ) j++; // for cases like nums = [1,3,1,5,4], k = 0 , when j and i both points to arr[i] == arr[j] == 3 
        }
        return cnt;
    }


    // time: O(n), spcae:O(n)
    int findPairsLessTime(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans=0;
        for(auto itr : nums){ // store elm with their frequency in map
            mp[itr]++;
        }
        for(auto itr : mp){
            int elm = itr.first, freq=itr.second;
            // pair found bcoz (elm+k) is present in mp 
            if(k!=0 && mp.find(elm+k) != mp.end()){ // when k!=0
                ans++;
            }
             if(k==0){  // when k=0, eg: {3,1,4,1,5} and k=0
                if(freq>1){
                    ans++;
                }
            }
        }
        return ans;
    }

    int main(){
        vector<int> v = {3,1,4,1,5};

        
            cout << findPairs(v,2);
        

        return 0; 
    }