#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/*
- traverse to target node
- store mapping of each node with its parent in a map
- from targetnode, go on burning its adjacent nodes
*/


// finds targetNode and creates child to parent mapping 
    // using level order traversal algo for mapping all nodes with their parent
 void childTOParentMapping(Node* root, int &target, Node * &targetNode, unordered_map<Node*, Node*> &parentMap){
        queue<Node*> q;
        q.push(root);
        parentMap[root] = NULL; // bcoz root's parent is none
        while(!q.empty()){
            Node * front = q.front(); // take out elm from queue
            q.pop();
            if(front->data == target) // find targetnode
                targetNode = front;
                
            if(front->left){
                q.push(front->left);
                parentMap[front->left] = front; // map leftchild with its parent
            }
            if(front->right){
                q.push(front->right);
                parentMap[front->right] = front;  // map leftchild with its parent
            }
        }
    }
    
    int minTimeToBurn(Node* targetNode, unordered_map <Node*, Node*> &parentMap){
        if (!targetNode) return 0;
        unordered_map <Node*, bool> isBurnt; // keeps track of which nodes are burnt
        queue<Node*> q; 
        q.push(targetNode);
        isBurnt[targetNode] = true;
        int t=0;
        while(!q.empty()){
            int len = q.size();
            bool fireSpread = false;
            for(int i=0;i<len;i++){
                Node * front = q.front();
                q.pop();
                if(front->left && !isBurnt[front->left]){  // left child exists, and not burnt yet then burn it
                    q.push(front->left);
                    isBurnt[front->left] = true;
                    fireSpread = true;
                }
                if(front->right && !isBurnt[front->right]){  // right child exists, and not burnt yet then burn it
                    q.push(front->right);
                    isBurnt[front->right] = true;
                    fireSpread = true;
                }
                if(parentMap[front] && !isBurnt[parentMap[front]]){  // parent exists, then burn it
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = true;
                    fireSpread = true;
                }
            }
            if(fireSpread) // if firespread, time increased
                    t+=1;
        }
        return t;
    }
  
    int minTime(Node* root, int target) 
    {
        unordered_map <Node*, Node*> parentMap;
        Node * targetNode = NULL;
        childTOParentMapping(root, target, targetNode, parentMap);
        return minTimeToBurn(targetNode, parentMap);
    }