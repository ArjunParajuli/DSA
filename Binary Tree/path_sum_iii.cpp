#include <bits/stdc++.h>
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
at each node, find the number of path sums
*/

    int ans = 0;
    // gets number of ans from current node
    void noOfAns(TreeNode* root, long long sum){
        if(root == NULL) return;

        if(sum == root->val){ // path sum found
            ans++;
        }
        noOfAns(root->left, sum-root->val); // decrementing targetsum so that no need to use extra sum variable
        noOfAns(root->right, sum-root->val); 
    
    }


    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
            noOfAns(root, targetSum); // call for current node
            pathSum(root->left, targetSum); // call same func for left
            pathSum(root->right, targetSum);
        }
        return ans;
    }


 int main(){

    return 0;
 }