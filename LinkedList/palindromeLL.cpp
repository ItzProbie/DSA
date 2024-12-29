class Solution {
    
    Node* reverseLL(Node* curr){
        
        Node* prev = NULL , *nxt = NULL;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
        
    }
    
    bool areSame(Node* it1 , Node* it2){
        
        while(it1 && it2){
            if(it1->data != it2->data)
                return false;
            it1 = it1->next;
            it2 = it2->next;
        }
        
        return true;
        
    }
    
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        
        if(!head || !head->next)
            return true;
        
        Node* fast = head;
        Node* slow = head;
        
        while(fast && fast->next){
            
            slow = slow->next;
            fast = fast->next->next;
            
            
        }
        
        Node* center = slow;
        //ODD NUMBER OF NODES
        if(fast){
            center = center->next;
        }
        
        return areSame(head , reverseLL(center));
        
    }
};