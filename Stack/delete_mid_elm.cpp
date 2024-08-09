#include<iostream>
#include<stack>
using namespace std;

 void findAns(stack<int>&s, int mid){
        if(mid == 0)
            return;
        // store top elm
        int elm = s.top();
        // remove top elm 
        s.pop();
        // recursive call 
        findAns(s, mid-1);
        // backtracking (inserting other than mid elm after removing mid elm)
        if(mid != 1)
            s.push(elm);
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int size)
    {
        int mid = (size/2) +1;
        findAns(s, mid);
    }

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    deleteMid(st, 4);
   while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
   }

    return 0;
}
