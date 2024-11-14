 #include<bits/stdc++.h>
 using namespace std;

  // Function to check if Kth bit is set or not.
    /*
    Shift the kth bit to the rightmost position then & with 1 to see if that bit is set or not.  
    */
    bool checkKthBit(int n, int k) {
        if( (n>>k)&1 ) return true;
        else return false;
    }


// 1 ko k times left shift karlo
// then usko n k sath or kardo to get ans
    int setKthBit(int n, int k)
    {
        int one = 1;
        one = one << k;
        
        return n | one;
    }
    
/*
left shift 1 by k positions and then negate it
now do and of above obtd num and n

*/
int clearKthBit(int n, int k)
    {
        int one = 1;
        one = one << k;
        one = ~one; // ~ is bitwise not operator, It inverts the bits of its operand. it is diff from !

        return n & one;
    }

// follow same steps as above & just xor it
int toggleKthBit(int n, int k)
    {
        int one = 1;
        one = one << k;

        return n ^ one;
    }

// works bcoz eg: 15-> 1111. so we and 15 with 14 then 1111 & 1110 gives us number after removing rightmost set bit. 
// eg, we can get 15 after subtracting 1 from 16
int removeRightmostSetBit(int n)
    {
        return n & n-1;
    }

// 16 & 15 -> 10000 & 01111 = 00000, number with power of 2 will have single 1 in it. so just & it with its previous number to find out 
 bool isPowerOfTwo(int n) {
        return ((n & n-1) == 0);
    }

// (n & n-1) will turn off the rightmost set bit
// so we do this until n is 0
int countSetBits(int n){
    int cnt=0;
    while(n != 0){
        n = n & n-1;
        cnt++;
    }
    return cnt;
}


int main(){
    cout << removeRightmostSetBit(9);

    return 0;
}