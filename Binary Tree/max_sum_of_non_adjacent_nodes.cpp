#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


// intuition is very similar to subset problem of recursion where we include curr elm once and exclude curr elm once
// time: O(n)
// space :O(height of tree)
pair<int, int> solve(Node * root){
      if(root == NULL)
        return {0, 0};
        
      pair<int, int> leftAns = solve(root->left);
      pair<int, int> rightAns = solve(root->right);
      
      // sum including curr node, so don't include its child nodes
      int s1 = root->data + leftAns.second + rightAns.second;
      
      // sum excluding curr node, so take sum of maxm elm from left and right 
      int s2 = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
      
      return {s1, s2};
  }
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }