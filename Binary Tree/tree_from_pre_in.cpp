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
Note: unordered_map uses a hashing function to store a key-value pair, due to which the average time complexity for 
searching a key-value pair becomes O(1).
But incase of map is O(log n)

Note: preorderIndex must be passed by reference bcoz we want to traverse preorder array only once. 
  If passed by value, its value goes back to previous val after returning from recursive call
  
*/


/* in this approach, searching for each elm takes o(n) time so we can optimize it
 
    int findPos(vector<int>& inorder, int target){   // returns the index of elm in inorder arr
        for(int i=0;i<inorder.size();i++){
            if(target == inorder[i])
                return i;
        }
        return -1;
    }
 
    TreeNode * construct(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd){
        // base case
        if(preIndex >= preorder.size() || inStart > inEnd)
            return NULL;

        // solve one case
        TreeNode * root = new TreeNode(preorder[preIndex]);
        int inPos = findPos(inorder, preorder[preIndex]);
        preIndex++;
        // recursion
        root->left = construct(preorder, inorder, preIndex, inStart, inPos-1);
        root->right = construct(preorder, inorder, preIndex, inPos+1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, inStart = 0, inEnd = inorder.size()-1;
        return construct(preorder, inorder, preIndex, inStart, inEnd);
    }
*/

// using unordered_map to reduce searching time to O(1) for each elm
 TreeNode * construct(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd, unordered_map<int, int> &mp){
        // base case
        if(preIndex >= preorder.size() || inStart > inEnd)
            return NULL;

        // solve one case(construct a node and find its posn in inorder arr)
        TreeNode * root = new TreeNode(preorder[preIndex]);
        int inPos = mp[preorder[preIndex]];  // optimized searching using unordered_map
        preIndex++;

        // recursion
        root->left = construct(preorder, inorder, preIndex, inStart, inPos-1, mp);
        root->right = construct(preorder, inorder, preIndex, inPos+1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0, inStart = 0, inEnd = inorder.size()-1;
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){  // map-[elm->elm's index] bcoz we need to access the index of elm in inorder arr
            mp[inorder[i]] = i;
        }
        return construct(preorder, inorder, preIndex, inStart, inEnd, mp);
    }


int main(){

    return 0;
}