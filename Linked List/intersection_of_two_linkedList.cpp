 int length(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) 
            return NULL;
        int lenA = length(headA);
        int lenB = length(headB);
        int diff = abs(lenA-lenB); 
        if(lenA > lenB){
            while(diff){
                headA = headA->next;
                diff--;
            }
        }else if(lenB > lenA){
            while(diff){
                headB = headB->next;
                diff--;
            }
        }
        while(headA && headB){
                if(headA == headB)
                    return headA;
                headB = headB->next;
                headA = headA->next;
            }
        return NULL;
    }