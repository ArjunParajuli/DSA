#include<bits/stdc++.h>
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
- same as pre and inorder but here we start from end of postorder
- then we first make a right recursive call then left recursive call bcoz postorder-> left right node
*/

TreeNode* construct(vector<int>& postorder, vector<int>& inorder, int &postIndex, int inStart, int inEnd, unordered_map<int, int> &mp){
        if(postIndex < 0 || inStart > inEnd)
            return NULL;

        TreeNode * root = new TreeNode(postorder[postIndex]);
        int inPos = mp[postorder[postIndex]];
        postIndex--;
        root->right = construct(postorder, inorder, postIndex, inPos+1, inEnd, mp);
        root->left = construct(postorder, inorder, postIndex, inStart, inPos-1, mp);
      
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1, inStart = 0, inEnd = inorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){  
            mp[inorder[i]] = i;
        }
        return construct(postorder, inorder, postIndex, inStart, inEnd, mp);
    }