#include<iostream>
#include<stack>
#include<vector>
using namespace std;

 //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
        // push all person in stack
        for(int i=0;i<n;i++){
            st.push(i);
        }
        int p1, p2;
        while(st.size() != 1){ // bcoz single elm remaining in stack at the end might be celebrity
        // compare top two elms and check if they know each other
            p1 = st.top();
            st.pop();
            if(!st.empty())
                p2 = st.top();
            st.pop();
            
            // if person1 knows person2
            if(m[p1][p2] == 1){
                // person1 is definitely not celebrity but person2 might be so push person2
                st.push(p2);
            // if person2 is celebrity
            }else if(m[p2][p1] == 1){
                // person2 is definitely not celebrity but person1 might be so push person1
                st.push(p1);
            }
        }
        
        // now check the remaining elm of stack if he is a celebrity
        int cel = st.top();
        // check rowwise(all elms in celebrity's row must be zero)
        for(int i=0;i<n;i++){
            if(m[cel][i] != 0)
                return -1;
        }
        // check col wise(celebrity's all column other than diagonal elm must be one)
        for(int i=0;i<n;i++){
            // if diagonal just ignore
            if(cel == i){
                continue;
            }else{
                // check all col is 1 or not
                if(m[i][cel] != 1)
                    return -1;
            }
        }
        return cel;
    }


int main(){
    vector<vector<int>> mat =   {{0, 0, 0},
                                {1, 0, 0},
                                {1, 0, 0}};
    // here, 0th person doesn't know 1st and 2nd person but 1st and 2nd person know 0th person  so, 0th is celebrity.
    cout << celebrity(mat, 3);
 
    return 0;
}