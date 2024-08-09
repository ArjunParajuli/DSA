Node * mergeRecursive(Node * l1, Node * l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    Node * ptr = NULL;
    if(l1->data <= l2->data){
        ptr = l1;
        l1->bottom = mergeRecursive(l1->bottom, l2);
    }else{
        ptr = l2;
        l2->bottom = mergeRecursive(l1, l2->bottom);
    }
    return ptr;
}
    
Node *flatten(Node *root)
{
   if(root == NULL)
    return root;
    
    return mergeRecursive(root, flatten(root->next));
}