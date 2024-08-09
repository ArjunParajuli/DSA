	#include<bits/stdc++.h>
    using namespace std;
    
    // This function defines the criteria for comparing two strings a and b in order to determine their relative order in the sorted sequence.
    // The function returns true if a+b should come before b+a in the sorted sequence, and false otherwise.
    // If a+b is greater than b+a, it means that a should be placed before b in the sorted sequence. 
    static bool customcmp(string a, string b){
        //this will automatically sort the value after conactenation (checks for each string and makes the larger one appear first)
	    return a+b > b+a;
	}
    
    string printLargest(int n, vector<string> &arr) {
       sort(arr.begin(), arr.end(), customcmp);
       string ans = "";
       for(int i=0;i<n;i++){
           ans += arr[i];
       }
       return ans;
    }

    //  Time Complexity: O(n*log(n) ), space: O(n)

    int main(){
        vector<string> arr = {"3", "30", "34", "5", "9"};
        cout << printLargest(5, arr);

        return 0;
    }