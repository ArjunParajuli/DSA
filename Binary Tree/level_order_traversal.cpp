#include <iostream>
#include<queue>
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
- We go level by level and when we complete one level we insert all the elements of that level in ans.
- Firstly we have root in our queue and suppose it was level 0.
- When we completely traverse the level 0, all the elements of level 1 are pushed in queue and all elements of level 0 are in our vector currRow.
- so insert currRow in ans and start traversing for next level

Time complexity:
O(n)

Space complexity:
O(n)

*/

 vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        // push root node
        q.push(root);
        while(!q.empty()){
            // update row length for each level
            int rowLen=q.size();
            // vector for each row level elms
            vector<int> currRow;
            for(int i=0;i<rowLen;i++){
                // pop from queue
                TreeNode * front = q.front();
                q.pop();
                // push to row vector
                currRow.push_back(front->val);
                // push children of front node
                if(front->left != NULL)
                    q.push(front->left);
                if(front->right != NULL)
                    q.push(front->right); 
            } 
            // push current level vector to ans
            ans.push_back(currRow);
        }
        return ans;
    }

    int main(){

        return 0;
    }