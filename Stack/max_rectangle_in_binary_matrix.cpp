#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*

codehelp stack assignments

algo:
- using the question largest area in a histogram.
- for first row, we calculate max area in a histogram.
- and for each next rows, we add the curr row's elm with previous rows elms, and then find the maximum area in a histogram.
    eg: previous row: [1,0,1,0,0] & curr row: [1,0,1,1,1] 
    then after adding, the curr row is [2, 0, 2, 1, 1] & find maximum area in histogram for this.
- do the same for all the rows.


# optimized way through DP 

*/

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


// code for max rectangle in binary matrix

 int maximalRectangle(vector<vector<char>>& matrix) {
       // input mamtrix contains elms in char, so convert to int
       vector<vector<int>> matrixInt(matrix.size(), vector<int>(matrix[0].size(), -1));
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            int intVal = matrix[i][j]-'0';
            matrixInt[i][j] = intVal;
        }
       }

        // get maxm area for the first row
       int area = largestRectangleArea(matrixInt[0]);
       // now find maxm area after updating each row (adding curr row with prev row)
       for(int i=1;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrixInt[i][j] == 0){ // bcoz current elm is 0 means histogram can't be formed
                matrixInt[i][j] = 0;
            }else{ // add with prev row
                matrixInt[i][j] += matrixInt[i-1][j];
            }
        }
        // added current and prev row, so find maxm area
        area = max(area, largestRectangleArea(matrixInt[i])); 
       }
       return area;
    }