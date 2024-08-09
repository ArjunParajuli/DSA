#include<iostream>
#include<stack>
#include<vector>
#include <list>
using namespace std;


 ListNode* reverseList(ListNode* head) {
         if(!head) return head;
         ListNode * prev = NULL;
        ListNode * current = head;
        ListNode * nextnode = head->next;
        while(current != NULL){
            current->next = prev;
            prev=current;
            current = nextnode;
            if(nextnode) nextnode = nextnode->next;
        }
        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
         head = reverseList(head);
         stack<int> st;
         st.push(head->val);
         vector<int> ans;
         ans.push_back(0);
         ListNode * t = head->next;
         while(t){
             while(!st.empty() && st.top() <= t->val){
                 st.pop();
             }
             if(!st.empty()){
                 ans.push_back(st.top());
                 st.push(t->val);
             }else{
                st.push(t->val);
                ans.push_back(0);
             }
             t = t->next;
         }
         reverse(ans.begin(), ans.end());
         return ans;
    }


    int main(){
        list<int> myLinkedList;
        myLinkedList.push_back(5);  // Add an element to the end
        myLinkedList.push_front(3);
        myLinkedList.push_front(4);
        myLinkedList.push_front(7);
        myLinkedList.push_front(2);
        list<int> head = myLinkedList.begin();
        vector<int> ans = nextLargerNodes(head);
        for(int itr:ans){
            cout << itr << " ";
        }

        return 0;
    }