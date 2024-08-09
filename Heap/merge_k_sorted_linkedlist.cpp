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
*/

    class Compare{
        public:
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };

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