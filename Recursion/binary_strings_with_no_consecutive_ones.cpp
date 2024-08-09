#include<iostream>
using namespace std;
    
    int countStrings(int n) {
	    // base case for n=1
	    int ending0 = 1;
	    int ending1 = 1;
	    int ans = ending0+ending1;
	    if(n == 1)
	        return ans;
	   
	    for(int i=2;i<=n;i++){
	       ending1 = ending0%1000000007;
	       ending0 = ans%1000000007;
	       ans = ending0+ending1%1000000007;
	   }
	   return ans%1000000007;
	}

    int main(){
        cout << countStrings(3);
        return 0;
    }