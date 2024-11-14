#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// wont work using pre, in or post order traversal so we use level order traversal

/*
- we take vertical level here, root ka verLvl 0 hoga, left jatey waqt verLvl decrement karo, right jatey waqt increment
- harek verLvl par, uska top view elm rakho  

Note: use map instead of unordered_map bcoz sorted order is important in ans vector. The leftmost vertical level will be the samllest and will be stored at first place in map. 
*/
vector<int> topView(Node *root){
    vector<int> ans;

    // store vertical_level->top_elm  (for each vertical level, store top elm)
    map<int, int> mp;
    
    // store each Node* and its vertical level 
    queue<pair<Node*, int>> q;

    int verLvl = 0;
    q.push( {root, verLvl} );

    while(!q.empty()){
        pair<Node*, int> frontPair = q.front();
        Node * frontNode = frontPair.first;
        verLvl = frontPair.second;
        q.pop();

        // agar pehle se hai toh dobara mat dalna
        if(mp.find(verLvl) == mp.end()){
            mp[verLvl] = frontNode->data;
        }
        if(frontNode->left != NULL)
            q.push( {frontNode->left, verLvl-1} );
        if(frontNode->right != NULL)
            q.push( {frontNode->right, verLvl+1} );
    }

    for(auto itr:mp){
        ans.push_back(itr.second);
    }
    return ans; 
}

// the only diff is we insert in map without checking if it already exists
 vector <int> bottomView(Node *root) {
         vector<int> ans;

    // store vertical_level->top_elm  (for each vertical level, store top elm)
    map<int, int> mp;
    
    // store each Node* and its vertical level 
    queue<pair<Node*, int>> q;

    int verLvl = 0;
    q.push( {root, verLvl} );

    while(!q.empty()){
        pair<Node*, int> frontPair = q.front();
        Node * frontNode = frontPair.first;
        verLvl = frontPair.second;
        q.pop();

            // even if map mai already hai, dalte raho for all nodes
            mp[verLvl] = frontNode->data;
        
        if(frontNode->left != NULL)
            q.push( {frontNode->left, verLvl-1} );
        if(frontNode->right != NULL)
            q.push( {frontNode->right, verLvl+1} );
    }
    for(auto itr:mp){
        ans.push_back(itr.second);
    }
    return ans; 
    }

int main(){

    return 0;
}

