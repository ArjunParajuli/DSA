 ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* dummy = new ListNode();
dummy->next = head;
ListNode* fast = dummy;
ListNode* slow = dummy;
while(n){
	fast = fast->next;
	n--;
}
while(fast->next){
	fast = fast->next;
	slow = slow->next;
}
slow->next = slow->next->next;
	return dummy->next;
    }