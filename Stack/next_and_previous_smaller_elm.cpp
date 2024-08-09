#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// next smaller elm
/*
algo:
- traverse right to left, find curr elm's next small elm by removing bigger elms from stack and at the end, insert each elm in stack 
*/
vector<int> nextSmaller(vector<int> arr){
    // here we go from right to left
    // if small elm found then update ans by that elm else update ans by -1
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    // go right to left bcoz we're find next smaller elm
    for(int i=arr.size()-1;i>=0;i--){
        int curr = arr[i];
        // so that top will have next smaller elm of curr [curr se badey elm hatado stack se taki curr se next smaller elm top mai rahe]
       while(st.top() >= curr){
        st.pop();
       }
       ans[i] = st.top(); // store next smaller elm 
       st.push(curr); // push curr bcoz curr vi koi aur elm ka next small elm hosakta hai
    }
    return ans;
}

// previous smaller elm 
vector<int> prevSmaller(vector<int> arr){
    // same as above, its just that we go from left to right 
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int curr = arr[i];
       while(st.top() >= curr){
        st.pop();
       }
       ans[i] = st.top();
       st.push(curr);
    }
    return ans;
}

 int main(){
    vector<int> arr={8,4,6,2,3};
    vector<int> ans = prevSmaller(arr);
    for(auto itr : ans){
        cout << itr << " ";
    }

    return 0;
  }
