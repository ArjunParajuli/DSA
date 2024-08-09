#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
algo:
- store 1 in ans arr
- start i from 2 to n, and iterate over each elm in ans and multiply each elm with i and insert in ans 
*/

/*
Time Complexity: O(N log (N!)), where O(N) is for loop and O(log N!) is for nested while loop
Auxiliary Space: O(max(digits in factorial))
*/

// If u forgot the logic, refer to lovebabbar video u idiot
vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        for(int i=2;i<=N;i++){
            // multiply each elm of ans with i and insert into ans 
            for(int j=0;j<ans.size();j++){
                int x = ans[j]*i+carry;
                ans[j] = x % 10;
                carry = x / 10;
            }
            // if carry is left after multiplying all elms of ans arr
            while(carry){  
                ans.push_back(carry%10);
                carry /= 10;
            }
        }
        // bcoz we get ans in revese order
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int main(){
        int N= 5;
        vector<int> ans;
        ans = factorial(N);
        for(int itr : ans){
            cout << itr <<" ";
        }

        return 0;
    }