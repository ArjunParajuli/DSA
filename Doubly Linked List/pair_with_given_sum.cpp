 #include<iostream>
 #include<pair>
using namespace std;

 struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 
 
 Node * findEnd(Node *head){
        Node * end = head;
        while(end->next != NULL){
            end = end->next;
        }
        return end;
    }

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> ans;
        if(head == NULL) return ans;
        Node * front = head;
        Node * end = findEnd(head);
        while(front->data < end->data){
            int sum = front->data+end->data;
            if(sum == target){
                int first = front->data;
                int second = end->data;
                ans.push_back({first, second});
                end = end->prev;
                front = front->next;
            }else if(sum > target){
                end = end->prev;
            }else{
                front = front->next;
            }
        }
        return ans;
    }