#include<iostream>
#include<stack>
#include<vector>
using namespace std;

 vector<int> finalPrices(vector<int>& prices) {
     int n = prices.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            int currElm = prices[i];
            while(!st.empty() && currElm < st.top()){
                st.pop();
            }
            // when stack has no elm, just push the currElm
            if(st.empty()){
                ans[i]=currElm;
                st.push(currElm);
            }else{
                // if elm present, then push discounted elm
                ans[i]=currElm-st.top();
                st.push(currElm);
            }
        }
        return ans; 
 }

  int main(){
    vector<int> prices={8,4,6,2,3};
    vector<int> ans = finalPrices(prices);
    for(auto itr : ans){
        cout << itr << " ";
    }

    return 0;
  }