#include<iostream>
#include<vector>
#include<map>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

/*
codehelp DP assignment

algo:
- 1 se n tak traverse karo
- for each i, create all of its possible left & right child combinations & store in two vectors
- now, for each i, create its node & attach all possible left & right child combinations & store each tree in ans 

*/

// 1. Recursion
    vector<TreeNode*> allPossibleBst(int start, int end){
        // base (dry run for n=2)
        if(start > end) return { NULL };
        if(start == end) return { new TreeNode(start) };

        vector<TreeNode*> ans;
        // solve one case i.e. 
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = allPossibleBst(start, i-1); // contains all bst of i's left elms
            vector<TreeNode*> right = allPossibleBst(i+1, end); // contains all bst of i's right elms

            // harek i ka node banawo and i node ke left & right mai all possible combinations of elms ko dalke ans mai push karo
            
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    // i ka node banawo
                    TreeNode * root = new TreeNode(i);
                    // i ke left & right child banawo & ans mai push karo
                    root->left = left[j];
                    root->right = right[k];

                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return allPossibleBst(1, n);
    }



// 2. Memoization
map<pair<int, int>, vector<TreeNode*>> dp; // for each {start, end} we store its corresponding ans 
    vector<TreeNode*> allPossibleBstMemoization(int start, int end){
        // base (dry run for n=2)
        if(start > end) return { NULL };
        if(start == end) return { new TreeNode(start) };

        if(dp.find({start, end}) != dp.end()){
            return dp[{start, end}];
        }

        vector<TreeNode*> ans;
        // solve one case i.e. 
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = allPossibleBstMemoization(start, i-1); // contains all bst of i's left elms
            vector<TreeNode*> right = allPossibleBstMemoization(i+1, end); // contains all bst of i's right elms

            // harek i ka node banawo and i node ke left & right mai all possible combinations of elms ko dalke ans mai push karo
            
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    // i ka node banawo
                    TreeNode * root = new TreeNode(i);
                    // i ke left & right child banawo & ans mai push karo
                    root->left = left[j];
                    root->right = right[k];

                    ans.push_back(root);
                }
            }
        }
        return dp[{start, end}] = ans;
    }

    vector<TreeNode*> generateTreesMemoization(int n) {
        return allPossibleBstMemoization(1, n);
    }


int main(){

    return 0;
}