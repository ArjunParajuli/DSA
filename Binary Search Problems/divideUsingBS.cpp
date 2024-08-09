
#include <iostream>

using namespace std;

int divide(int dividend, int divisor){
    int s = 0, e = dividend, ans=-1;
    int mid = s + (e-s)/2;
    int rem = dividend%divisor;
    while(s <= e){
        if((divisor*mid+rem) == dividend)
            return mid;
        if((divisor*mid + rem) < dividend){
            // possible answer so store it and go towards right
            ans = mid;
            s = mid+1;
        }else
            e = mid-1; 
            
        mid = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    cout << divide(7, 7);

    return 0;
}
