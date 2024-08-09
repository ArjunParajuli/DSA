#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

// love babbar
/*
make recursive tree for understanding
swap each char with each other
*/

void getPermutations(string s, vector<string> &ans, int i){ 
		    if(i >= s.size()){
		        ans.push_back(s);
		        return;
		    }
		    // j start from i to n
			// inside loop, first swap then increment i with func call
		    for(int j=i;j<s.size();j++){
		        swap(s[i], s[j]);
		        getPermutations(s, ans, i+1);
				// backtrack if s passed by ref
				// swap(s[i], s[j]);
		    }   
	    }
	
		vector<string> find_permutation(string s)
		{
		    vector<string> ans;
		    getPermutations(s, ans, 0);
		    return ans;
		}

int main(){
    vector<string> ans = find_permutation("abc");
    for(auto it : ans)
        cout << it << " ";

    return 0;
}