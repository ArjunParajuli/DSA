 #include<bits/stdc++.h>
 using namespace std;

 /*
 YT-codestorywithMIK

 algo:
 basically, we need to find the subarr whose xor is 0 then we can get the num of triplets = k-i for that subarr
 
 
 */


// better approach algo: store prefixxor for each posn 
 int countTriplets(vector<int>& arr) {
        int cnt=0, n=arr.size();
        vector<int> prefixXor;
        prefixXor.push_back(0);

        int x=0;
        for(int i=0;i<n;i++){
            x = x ^ arr[i];
            prefixXor.push_back(x); 
        }

        for(int i=0;i<prefixXor.size();i++){
            for(int k=i+1;k<prefixXor.size();k++){
                if(prefixXor[i] == prefixXor[k])   
                    cnt += k-i-1;
            }
        }

        
        return cnt;
    }