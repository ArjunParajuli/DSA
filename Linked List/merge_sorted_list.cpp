// same as merge two sorted array

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // first create an ans node and ansPtr points to this node 
    // then start linking the nodes
        ListNode * ans = new ListNode(-1);
        ListNode * ansPtr = ans;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                ansPtr->next = list1;
                list1 = list1->next;
            }else{
                ansPtr->next = list2;
                list2 = list2->next;
            }
            ansPtr=ansPtr->next;
        }
        if(list1 != NULL){
           ansPtr->next = list1;
        }
        if(list2 != NULL){
           ansPtr->next = list2;
        }
        return ans->next;
    }