#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
codehelp: stack class 3 

algo:
- find nextSmallerIndex & prevSmallerIndex arrays.
- we need to maximize the area for each rectangle. so we need to maximize the width, height is the elm itself.
find maxm width: (next small elm index) - (prev small elm index) - 1 
*/

// same as nexttSmallerElm juss that here we store index in stack bcoz we need the next small index
vector<int> nextSmallerIndex(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    // go right to left bcoz we're find next smaller elm
    for(int i=arr.size()-1;i>=0;i--){
        int currIdx = i;
       while(st.top()!=-1 && arr[st.top()] >= arr[currIdx]){
        st.pop();
       }
       ans[i] = st.top();
       st.push(currIdx);
    }
    return ans;
}

// previous smaller elm 
vector<int> prevSmallerIndex(vector<int> arr){
    // same as above, its just that we go from left to right 
    int n = arr.size();
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int currIdx = i;
       while(st.top()!=-1 && arr[st.top()] >= arr[currIdx]){
        st.pop();
       }
       ans[i] = st.top();
       st.push(currIdx);
    }
    return ans;
}

 int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSmall = prevSmallerIndex(heights);
        vector<int> nextSmall = nextSmallerIndex(heights);
        // prevSmall elm's index can -1 bcoz agar usse koi chota elm nahi hai previously then sabse pehle index se agey ko mansakte hai i.e. -1
        // but nexSmall elm's index can't be -1 kyuki next small elm dhundrahe hai so index -1 toh previous index hoga sab elm k liye
        // hence we assume nextsmall elm nahi hai toh last index manlo
        for(int i=0;i<nextSmall.size();i++){  // eg: cases like [2, 4]
            if(nextSmall[i] == -1)
                nextSmall[i] = nextSmall.size();  // -1 ko last index se replace karo
        }  

        int maxm = INT_MIN;
        for(int i=0;i<heights.size();i++){
            int length = heights[i];
            int width = nextSmall[i] - prevSmall[i] - 1;
            int currArea = abs(length * width);
            cout << currArea << " ";
            maxm = max(maxm, currArea); 
        }
        cout << endl;
        return maxm;
    }

int main(){
    vector<int> arr={2,1,5,6,2,3};
    // vector<int> ans = nextSmallerIndex(arr);
    // for(auto itr : ans){
    //     cout << itr << " ";
    // }

    cout << largestRectangleArea(arr);

    return 0;
}