class Solution {
    
    
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        // code here
        // return head of reversed list
        
        if(!head || !head->next)return head;
        
        struct Node* prev = NULL;
        struct Node* nxt = NULL;
        struct Node* curr = head;
        
        while(curr){
            
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        return prev;
        
        
    }
};