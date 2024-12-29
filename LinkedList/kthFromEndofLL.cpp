class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node* fast = head;
        Node* slow = head;
        
        for(int i = 1 ; i < k ; i++){
            if(!fast || !fast->next)
                return -1;
            fast = fast->next;
        }
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow->data;
        
    }
};