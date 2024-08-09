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
  Intuition:
 First thought must be after seeing tree questions are bfs or dfs .Then as we have to check a strictly increasing or decreasing order
 in levels so breadth first search would be a good approach to start .After that make an approach and implement it.
  */

  bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool oddlvl = false;
        while(!q.empty()){
            int lvlsize = q.size();
            int prevForOdd = INT_MAX, prevForEven = INT_MIN;
            // loop runs for each level, checks if condiotions follow else returns false 
            for(int i=0;i<lvlsize;i++){
                TreeNode * front = q.front(); 
                q.pop();
                // odd level
                if(oddlvl){
                    // data decreasing, prev ko update karte raho to check in next iteration 
                    if(front->val < prevForOdd && front->val%2 == 0){
                        prevForOdd = front->val;
                    }else
                        return false;
                }else{ // even level so use maxm value prevForEven
                    if(front->val > prevForEven && front->val%2 == 1){
                        prevForEven = front->val;
                    }else
                        return false;
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            // toggle oddlvl after each level
            oddlvl = !oddlvl;
        }
        return true; 
    }