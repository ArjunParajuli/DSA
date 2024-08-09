#include <iostream>
using namespace std;

/*  the number which is a power of two has always compulsoryily 1 true bit.
bit representation of 7  -> 0111
bit representation of 8  -> 1000
bitwise AND of 7 and 8 -> 0000

so use this property bcoz AND n(of power of 2) with n-1 is always 0 

time: O(1)
*/

 bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int calc = n & (n-1); 
        return (calc == 0);
    }

int main(){
    cout << isPowerOfTwo(5);

    return 0;
}