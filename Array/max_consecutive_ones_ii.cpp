#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// yt-pepcoding 

// max consecutive ones with only one flip allowed
int maxConsecOne(vector<int> &arr){
    int cnt0=0, currlen=0, maxlen=0, j=0;
        for(int i=0;i<arr.size();i++){
            // increase count of 0
            if(arr[i] == 0){
                cnt0++;
            }
            // when it exceeds 1, move j to the next 0 elm
            while(cnt0 > 1){
                if(arr[j] == 0){
                    cnt0--;
                }
                j++;
            }
            currlen = i-j+1;
            maxlen = max(maxlen, currlen);
        }
        return maxlen;
}

int main() {
    vector<int> arr = {1,1,0,1,0,0,1,1,0,1,1,0,1,1,1};
    cout << maxConsecOne(arr);

    return 0;
}