 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

 int firstRepeated(int arr[], int n) {
        // using hashing to store the occurances in map
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        // again iterate array and check the occurance of elm which is greater than 1
        for(int i=0;i<n;i++){
            if(m[arr[i]] > 1)
                return i+1;         // returns 1 based index
        }
        return -1;
    }

    int main(){
        int arr[] = {1,2,3,3,4};
        cout << firstRepeated(arr, 5);

        return 0;
    }