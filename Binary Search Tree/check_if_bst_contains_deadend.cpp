#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

/*
use preorder traversal bcoz we first insert the nodes and check for leaf node if (root->data)-1 & (root->data)+1 both already exists in map
if already exists then we have a dead end in bst
*/

 void solve(Node * root, bool &ans, unordered_map<int, int> &mp){
      if(root == NULL) return;

      // insert
      mp[root->data] = 1;
      // leaf node, so check for dead end
      if( root->left==NULL && root->right==NULL ){
          int dataPlus1 = root->data+1;
          int dataMinus1 = (root->data)-1 == 0 ? root->data : root->data-1; // also handled for when leaf node is 1
          if( mp.find(dataPlus1)!=mp.end() && mp.find(dataMinus1)!=mp.end() ){  // if they already exist in map then dead end found
              ans = true;
          }
      }
      solve(root->left, ans, mp);
      solve(root->right, ans, mp);
      
  }
  
    bool isDeadEnd(Node *root)
    {
        bool ans = false;
        unordered_map<int, int> mp;
        solve(root, ans, mp);
        return ans;
    }