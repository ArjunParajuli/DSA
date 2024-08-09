#include<bits/stdc++.h>
using namespace std;

/*

algo:
- if we traverse list backwards and maintain a suffix max and we remove those nodes which are smaller than the suffix max, we get our ans
- but here we have a linkedlist. So, we must first reverse the list & then we do the same & at the end we again reverse the list & return it

*/

ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * current = head;
        ListNode * nextnode = NULL;
        while(current != NULL){
            nextnode = current->next;
            current->next = prev;
            prev=current;
            current = nextnode;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        if(!head->next) return head;
        head = reverseList(head);
        ListNode * curr = head;
        ListNode* prev = NULL;
        int suffixMax = curr->val;
        while(curr){
            suffixMax = max(suffixMax, curr->val);
            if(curr->val < suffixMax){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        head = reverseList(head);
        return head; 
    }


int main(){

    return 0;
}