#include<bits/stdc++.h>
using namespace std;

static bool comp(string a, string b){
        // for a=3, b=30 cases, 
        string s1 = a+b;  // s1=330
        string s2 = b+a;  // s2=303
        return s1>s2;   // returns bigger one first
    }

    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string> str;
        // copy the nums integer vector into string vector 
        for(auto itr : nums){
            str.push_back(to_string(itr));
        }
        // string sorting occurs in lexicographical order
        sort(str.begin(), str.end(), comp);
        for(auto itr : str){
            ans += itr;
        }
        // for case [0,0,...,0]
        if(ans[0] == '0')
            return "0";

        return ans;
    }

int main(){
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums);

    return 0; 
}