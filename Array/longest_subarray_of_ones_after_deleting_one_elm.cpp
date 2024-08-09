#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// same as max consecutive ones with only one flip allowed just diff is do -1 and return;


// Return the size of the longest non-empty subarray containing only 1's in array, you can delete one element from it.
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
        // -1 bcoz we calculated max ones with one elm flip allowed but htis ques says delete one elm instead of flip
        return maxlen-1;
}

int main() {
    vector<int> arr = {1,1,0,1,0,0,1,1,0,1,1,0,1,1,1};
    cout << maxConsecOne(arr);

    return 0;
}