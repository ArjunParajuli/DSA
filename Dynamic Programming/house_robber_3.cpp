#include <iostream>
#include<unordered_map>
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
  - two cases: 
  i. rob current node, so can't rob its children i.e. recursive call for grandchildren
  ii. didn't rob current node, so rob its children i.e. recursive call for children
  
  */


// 1. Recursion time: exponential
     int solve(TreeNode* root){
        if(!root) return 0;

        int rob=0, dontRob = 0;
        // rob current node
        rob += root->val;
        if(root->left)
            rob += solve(root->left->left) + solve(root->left->right);
        if(root->right)
            rob += solve(root->right->left) + solve(root->right->right);

        // dont rob current node
         dontRob += solve(root->left) + solve(root->right);

        return max(rob, dontRob);
    }

    int rob(TreeNode* root) {
        return solve(root);
    }


// 2. Memoization (use non contiguous data structure bcoz tree is also a non contiguous data structure, so can't use array)
// time: O(n) & space O(n)
    int solveMemoization(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(!root) return 0;

        if(dp[root])
            return dp[root];

        int rob=0, dontRob = 0;
        // rob current node
        rob += root->val;
        if(root->left)
            rob += solveMemoization(root->left->left, dp) + solveMemoization(root->left->right, dp);
        if(root->right)
            rob += solveMemoization(root->right->left, dp) + solveMemoization(root->right->right, dp);

        // dont rob current node
         dontRob += solveMemoization(root->left, dp) + solveMemoization(root->right, dp);

        return dp[root] = max(rob, dontRob);
    }

    int robMemoization(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solveMemoization(root, dp);
    }


// Cant use bottomup bcoz tree itself is a top down data structure & we must go downwards first to do bottomup