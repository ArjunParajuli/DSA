#include<iostream>
#include<stack>
using namespace std;

void findAns(stack<int> &st, int &x){
    // base case
        if(st.size() == 0){
            st.push(x);
            return;
        } 

        // solve one case     
        int temp = st.top();
        st.pop();
        // recursive call
        findAns(st, x);
        // backtracking
        st.push(temp);
    } 

    stack<int> insertAtBottom(stack<int> st,int x)
    {
        findAns(st, x);
        return st;
    }

    void printStack(stack<int> st){
        if(st.empty())
            return;
        
        int temp = st.top();
        st.pop();
        printStack(st);
        st.push(temp);
        cout << st.top() << " ";
    }

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st = insertAtBottom(st, 0);
    printStack(st);
 

    return 0;
}