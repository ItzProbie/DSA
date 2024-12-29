class Solution {
  public:
    Node* divide(Node* head) {
        // code here
        Node* evenDummyHead = new Node(-1);
        Node* oddDummyHead = new Node(-1);
    
        Node* evenIt = evenDummyHead;
        Node* oddIt = oddDummyHead;
        
        Node* it = head;
        
        while(it){
            
            if(it->data % 2 == 0){
                evenIt->next = it;
                evenIt = evenIt->next;
            }
            else{
                oddIt->next = it;
                oddIt = oddIt->next;
            }
            
            it = it->next;
            
        }
        
        oddIt->next = NULL;
        if(!evenDummyHead->next)
            return oddDummyHead->next;
            
        evenIt->next = oddDummyHead->next;
        
        return evenDummyHead->next;
        
    }
};