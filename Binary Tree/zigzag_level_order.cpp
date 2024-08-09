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

 // time: O(n) 

 /*
  same as level order just that maintain a boolean for left to right direction and accordingly push into the vector
 */

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root); // push root initially
        bool leftToRightDirection = true;
        while(!q.empty()){
            int len = q.size();
            vector<int> lvl(len); // create a vector of each level's size so that we can insert from end also 
            for(int i=0;i<len;i++){
                TreeNode * node = q.front(); q.pop();
                int index = leftToRightDirection ? i : len-i-1; // according to direction, insert at start or end
                lvl[index] = node->val;
                if(node->left){
                    q.push(node->left);
                }        
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(lvl);
            leftToRightDirection = !leftToRightDirection; // toggle direction
        }
        return ans;
    }