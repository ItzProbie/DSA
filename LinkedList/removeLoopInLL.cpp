class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        Node* slow = head;
        Node* fast = head;
        
        bool loop = false;
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                loop = true;
                break;
            }
            
        }
        
        if(!loop)
            return;
            
        fast = head;
        while(slow != fast){
            fast = fast->next;
            slow = slow->next;
        }
        
        while(slow->next != fast)
            slow = slow->next;
            
        slow->next = NULL;
        
    }
};