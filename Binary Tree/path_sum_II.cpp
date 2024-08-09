#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

/**
 * Definition for a binary tree node.  */
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 // same as pathsum but we are pushing elms here. temp not taken by reference to avoid doing pop_back() conditions. 
 // sum must be passed by value bcoz at each node it should have sum upto current node after returning from a call.  
 
 void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum){
        if(root == NULL) return;

        sum += root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(targetSum == sum)
                ans.push_back(temp);
            
            return;
        }

        solve(root->left, targetSum, ans, temp, sum);
        solve(root->right, targetSum, ans, temp, sum);
    }

// dry run this code for understanding properly
void solveTempRef(TreeNode* root, int targetSum, int sum, vector<int> &temp, vector<vector<int>> &ans){
     if(root == NULL) return;

        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(temp);
            }
            temp.pop_back(); // backtrack
            return;
        }

        solveTempRef(root->left, targetSum, sum, temp, ans);
        solveTempRef(root->right, targetSum, sum, temp, ans);
        temp.pop_back(); // backtrack after returning from right call
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> ans;
         vector<int> temp;
         int sum = 0;
         solve(root, targetSum, ans, temp, sum);
         return ans;
    }