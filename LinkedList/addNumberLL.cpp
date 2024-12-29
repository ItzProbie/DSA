class Solution {
    
    Node* handleLeadingZeros(Node* it){
        while(it && it->data == 0){
            it = it->next;
        }
        return it;
    }
    
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
    
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node* head1 = handleLeadingZeros(num1);
        Node* head2 = handleLeadingZeros(num2);
        
        if(!head1 && !head2)
            return new Node(0);
            
        if(!head1 || !head2){
            return (head1 ? head1 : head2);
        }
        
        //BOTH ARE VALID NUMBERS AND NOT ZERO
        
        Node* it1 = reverseLL(head1);
        Node* it2 = reverseLL(head2);
        
        Node* dummyHead = new Node(-1);
        Node* it = dummyHead;
        
        int carry = 0;
        
        while(it1 || it2 || carry != 0){
            
            if(it1){
                carry += it1->data;
                it1 = it1->next;
            }
            if(it2){
                carry += it2->data;
                it2 = it2->next;
            }
            
            it->next = new Node(carry%10);
            it = it->next;
            carry /= 10;
            
        }
        
        Node* ans = dummyHead->next;
        return reverseLL(ans);
        
    }
};