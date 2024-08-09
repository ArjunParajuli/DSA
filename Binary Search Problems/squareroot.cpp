#include<iostream>
using namespace std;

int sqrRoot(int x){
     if (x == 0 || x == 1)
            return x;

       int s=0, e=x;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s <= e){
            long sqr = (long)mid*mid;
            if((long)mid*mid == (long)x){
                return mid;
            }else if( sqr > x)
                e = mid-1;
            else{ // bcoz answer might not be found exact (eg: x=8 ans is 2)
                ans = mid;   
                s = mid+1;
            }                
                mid = s+(e-s)/2;
        }   
        return ans;
}

int main(){
    cout << sqrRoot(101);

    return 0;
}