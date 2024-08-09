// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// Algo:
// move fast two steps and slow one step until they meet


// why does this algo work?
// bcoz they're moving one step and two step at a time so, if theres a cycle then they're bound to meet at one point(destined to meet)

bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow)
                return true;
        }
        return false;
    }