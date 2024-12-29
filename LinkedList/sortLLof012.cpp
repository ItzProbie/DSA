class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        Node* dummyHead0 = new Node(-1);
        Node* dummyHead1 = new Node(-1);
        Node* dummyHead2 = new Node(-1);
    
        Node* it0 = dummyHead0;
        Node* it1 = dummyHead1;
        Node* it2 = dummyHead2;
        
        while(head){
            
            switch(head->data){
                case(0):{
                    it0->next = head;
                    it0 = it0->next;
                    break;
                }
                case(1):{
                    it1->next = head;
                    it1 = it1->next;
                    break;
                }
                default:{
                    it2->next = head;
                    it2 = it2->next;
                    break;
                }
            }
            
            head = head->next;
            
        }
        
        it2->next = NULL;
        
        it1->next = dummyHead2->next;
        it0->next = dummyHead1->next;
        
        Node* temp = dummyHead0->next;
        
        delete dummyHead0;
        delete dummyHead1;
        delete dummyHead2;
            
        return temp;
        
    }
};