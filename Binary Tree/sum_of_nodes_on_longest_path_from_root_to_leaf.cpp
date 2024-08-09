#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// time: O(n), space O(n)

// just modifying the height function and returning {height_upto_current_node, sum_upto_current_node}
pair<int, int> solve(Node *root){
    // base case
    if(root == NULL)
        return {0, 0};

    auto leftHeight = solve(root->left);
    auto rightHeight = solve(root->right);

    // find sum to be returned
    int sum;
        if(leftHeight.first == rightHeight.first){
            sum = max(leftHeight.second, rightHeight.second)+root->data;
        }else if(leftHeight.first > rightHeight.first){
            sum = leftHeight.second+root->data;
        }else{
            sum = rightHeight.second+root->data;
        }

    return { max(leftHeight.first, rightHeight.first)+1, sum }; // return max height betn left and right and sum upto curr node
}

int sumOfLongRootToLeafPath(Node *root){
    pair<int, int> ans;
    ans = solve(root);
    return ans.second;

}