#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

// for each node, if it has a left child, push it to queue, and go to right child.
// after right child finished, take out elm from queue and repeat same steps
// time O(n)
vector<int> diagonal(Node *root)
{
   vector<int> ans;
   queue<Node *> q;
   Node * temp;
   q.push(root);
   while(!q.empty()){
       temp = q.front();
        q.pop();
        while(temp){
            ans.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            temp = temp->right;
        }
   }
   return ans;
}