#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
simple 2 ptr wont work for -ve elms case, so we must use map
striver yt. 
algo:
- suppose at current index sum=currsum and if there exists sum (currsum-k) anywhere before the curr idx then we can get the longest range with sum as k 
(currsum-k sum waley index ke baad se curr index tak ka range longest range hoga)  
- at each index store sum upto it with its index
- at each index check if (currsum-k) exists in map, if yes update maxlen 
*/

int lenOfLongSubarr(int arr[], int n, int k) 
    { 
        unordered_map<int, int> mp; // keep (sum upto curr index and its index)
        int currsum = 0, maxlen=0;
        for(int i=0;i<n;i++){
            currsum += arr[i];
            // found subarr
            if(currsum == k){
                maxlen = max(maxlen, i+1);
            }
            int remaining = currsum-k;
            // (potential ans found i.e subarray with sum k found)
            if(mp.find(remaining) != mp.end()){
                int currlen = i-mp[remaining];  // curr subarr len
                maxlen = max(maxlen, currlen);
            }
            // if same currsum already found then keep its leftmost index as we need the longest subarray eg: 2 0 0 3, k=3 (dry run for this)
            if(mp.find(currsum) == mp.end()){  // tabhi map mai dalo agar wo already nahi hai
                mp[currsum] = i;
            }
        }
        return maxlen;
    } 

    int main(){
        int arr[] = {-5, 8, -14, 2, 4, 12};
        int k = -5;
        cout << lenOfLongSubarr(arr, 6, k);

        return 0;
    }