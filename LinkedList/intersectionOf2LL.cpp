class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_set<int>s;
        while(head2){
            s.insert(head2->data);
            head2 = head2->next;
        }
        
        Node* dummyHead = new Node(-1);
        Node* it = dummyHead;
        
        while(head1){
            
            if(s.find(head1->data) != s.end()){
                s.erase(head1->data);
                it->next = head1;
                it = it->next;
            }
            
            head1 = head1->next;
            
        }
        
        it->next = NULL;
        return dummyHead->next;
    }
};