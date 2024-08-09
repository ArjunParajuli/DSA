#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode * midNode(ListNode * head){
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast->next != NULL){
            fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* mergeList(ListNode* list1, ListNode* list2) {
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

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode * mid = midNode(head);

        // Divide the list into two halves
        ListNode * left = head;
        ListNode * right = mid->next;
        mid->next = NULL;
        
        // Recursively sort the left and right halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves using the mergeTwoSortedLinkedLists function
        ListNode * mergedList = mergeList(left, right);
        return mergedList;
    }