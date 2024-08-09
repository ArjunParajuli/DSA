 #include<bits/stdc++.h>
 using namespace std;

 
 ListNode* recursiveReverse(ListNode* prev, ListNode * current){
        if(current == NULL){
            return prev;    // previous is the head node at the last step
        }
        ListNode * nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;

        return recursiveReverse(prev, current);
    }

    ListNode* reverseList(ListNode* head) {
        ListNode * prev = NULL;
        ListNode * current = head;
        return recursiveReverse(prev, current);
    }