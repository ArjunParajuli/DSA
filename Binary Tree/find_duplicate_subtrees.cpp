#include<iostream>
#include<unordered_map>
#include<vector>
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
    brute force: find all subtrees and store them and check for duplicates

    optimized: 
    - store preorder traversal(in string form) for each node in a map and if count for any node becomes > 1 then that is duplicate subtree
  */

 string preOrder(TreeNode* root, vector<TreeNode*> &ans, unordered_map<string, int> &mp){
        if(root == NULL) 
            return "N";

        string currNode = to_string(root->val); 
        string leftPreOrder = preOrder(root->left, ans, mp); 
        string rightPreOrder = preOrder(root->right, ans, mp); 
        string currNodePreOrder = currNode+","+leftPreOrder+","+rightPreOrder; // preorder -> node left right

        if(mp.find(currNodePreOrder) != mp.end()){  // already present in map
            // means it was present once already and when found 3rd time it wont push into ans 
            if(mp[currNodePreOrder] == 1){  
                ans.push_back(root);
            }
            mp[currNodePreOrder]++; // increment count
        }else{
            mp[currNodePreOrder]++;
        }

        return currNodePreOrder;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> mp;
        preOrder(root, ans, mp);
        return ans;
    }