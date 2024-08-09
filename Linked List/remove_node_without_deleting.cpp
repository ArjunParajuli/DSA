#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

 /*
 Q) Delete the given node. Note that by deleting the node, we do not mean removing it from memory. 
 -> here node is the node to be removed from list. we copy node's next elm in or node and point node to node->next->next. 
  first copy the next one and remove the next one. 
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // copy next val
        node->next = node->next->next; // remove next one
    }
};