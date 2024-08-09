#include<iostream>
#include<cmath>
using namespace std;

// pow function returns a floating type so double curr is used.
int NthRoot(int n, int m)
	{ 
	    int s = 1, e = m;
	    while(s <= e){
	        int mid = s+(e-s)/2;
	        double curr = pow(mid, n);
	        if(curr == m)
	            return mid;
	       else if(curr > m)
	            e = mid-1;
	       else
	            s = mid+1;
	    }
	    return -1;
	}

    int main(){
        cout << NthRoot(2, 9);
        return 0;
    }