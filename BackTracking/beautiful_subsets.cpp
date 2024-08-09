#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
    algo:
    - include exclude pattern

*/

    int count;
    unordered_map<int, int> visited;

      void explore(vector<int>& nums, int k, int index) {
        if (index == nums.size()) {
            if(!visited.empty())
                count++;
            return;
        }

        int num = nums[index];

        // include (Note: abs(num-k) won't work bcoz eg: {4} in map & k=2 then if next elm is 2 then abs(2-2)=0 and we insert 2 but can't insert 2 bcoz 4 is already in map )
        if (visited.find(num - k) == visited.end() && visited.find(num + k) == visited.end()) {
            visited[num]++;
            explore(nums, k, index + 1);
            visited[num]--; // backtrack
            if (visited[num] == 0) {
                visited.erase(num);
            }
        }

        // exclude
        explore(nums, k, index + 1);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        count = 0;
        explore(nums, k, 0);
        return count; // Subtract 1 to exclude the empty subset
    }

  