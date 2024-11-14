#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode * next;

    ListNode(int data){
        this->val = data;
        this->next = NULL;
    }
};

/*
logic very similar to merge k sorted arrays

Time Complexity: O(n * k * log k) For simplicity of analysis, we assume that every list is of same size n. In general we can say, the time complexity is O(N log k) where N is the total numbers of nodes in all the lists.
Auxiliary Space: O(k)

*/

    class Compare{
        public:
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };

// each elm in the lists array contains the head of each list
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode * ans = new ListNode(-1);
        ListNode * temp = ans;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(int i=0;i<lists.size();i++){
            if (lists[i] != nullptr) {  // handle case where first linkedlist is empty but second lisnkedlist is not empty
                pq.push(lists[i]);
            }
        }

        while(!pq.empty()){
            ListNode * topHead = pq.top();
            pq.pop();

            temp->next = topHead;
            temp = temp->next;
            if(temp && topHead->next){
                pq.push(topHead->next);
            }
        }
        return ans->next;
    }