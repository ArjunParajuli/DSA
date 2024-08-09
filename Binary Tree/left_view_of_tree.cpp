#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// pass ans by ref to reflect changes made in curr call to another call and pass level by value 

// at each level check if size of arr equals the level, if yes then push that elm
void solve(Node * root, vector<int> &ans, int level){
    if(root == NULL) 
        return;
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}

void solveRightView(Node* root, vector<int> &ans, int level){
        if(root == NULL) return;

        if(level == ans.size()){
            ans.push_back(root->data);
        }
    // first go to right
        solveRightView(root->right, ans, level+1);
        solveRightView(root->left, ans, level+1);
    }

    vector<int> rightSideView(Node* root) {
        vector<int> ans;
        solveRightView(root, ans, 0);
        return ans;
    }

    int main(){

        return 0;
    }