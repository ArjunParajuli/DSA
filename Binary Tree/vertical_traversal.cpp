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

/*
use map bcoz it stores data in key-wise sorted order and multiset stores multiple same values with sorted order maintained
- maintain coordinates for each nodes and use level order traversal
*/

vector<vector<int>> verticalTraversal(TreeNode* root) {
   vector<vector<int>> ans;
    queue<pair<TreeNode*, pair<int, int>>> q; // Node, {row,col}
    q.push({root, {0,0}}); // insert root initially
    map <int , map<int, multiset<int>> > mp;  // col -> {row->values}
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        TreeNode*&node = front.first;  // take by reference bcoz takes a lot of time in copying
        auto coordinates = front.second;
        int row = coordinates.first;
        int col = coordinates.second;
        mp[col][row].insert(node->val);
        if(node->left)
            q.push({node->left, {row+1, col-1}}); // insert left child
        if(node->right)
            q.push({node->right, {row+1, col+1}}); // insert right child
    }
    for(auto outerMp : mp){
        auto&innerMp = outerMp.second;
        vector<int> temp;
        for(auto itr:innerMp){
            auto&mset = itr.second;
            temp.insert(temp.end(), mset.begin(), mset.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){

    return 0;
}