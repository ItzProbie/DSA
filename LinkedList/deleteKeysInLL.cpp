Node* deleteAllOccurances(Node *head,int x)
{
    //Your code here
    
    Node* dummyHead = new Node(-1);
    Node* it = dummyHead;
    
    while(head){
        
        if(head->data != x){
            it->next = head;
            it = it->next;
        }
        
        head = head->next;
        
    }
    
    it->next = NULL;
    
    return dummyHead->next;
    
}