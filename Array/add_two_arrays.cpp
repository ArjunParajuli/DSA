#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string calc_Sum(int *a,int n,int *b,int m){
        int i=n-1, j=m-1;
        string res="";
        int carry = 0;
        int rem = 0;
        while(i>=0 && j>=0){
            int add = a[i] + b[j] + carry;
            rem = add % 10;
            carry = add / 10;
            res.push_back(rem + '0'); // converting to string
            i--,j--;
        }
        while(i >= 0){
            int add = a[i] + carry;
            rem = add % 10;
            carry = add / 10;
            res.push_back(rem + '0');
            i--;
        }
        while(j >= 0){
            int add = b[j] + carry;
            rem = add % 10;
            carry = add / 10;
            res.push_back(rem + '0');
            j--;
        }
        if(carry != 0){ // if carry remains at end
            res.push_back(carry+'0');
        }
        // our ans is stored in reverse order 
        // while reversing we get the end's 0 at first place 
        // so remove the first place's 0
        while(res[res.size()-1] == '0'){
            res.pop_back();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }

    int main(){
         int A[] = {9, 5, 4, 9}, B[] = {2, 1, 4} ;
        cout << calc_Sum(A, 4, B, 3);

        return 0;
    }