//BRUTEFORCE
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        
        unordered_map<Node* , Node*>oldToNew;
        oldToNew[NULL] = NULL;
        
        Node* it = head;
        while(it){
            oldToNew[it] = new Node(it->data);
            it = it->next;
        }
        
        it = head;
        while(it){
            
            oldToNew[it]->next = oldToNew[it->next];
            oldToNew[it]->random = oldToNew[it->random];
            it = it->next;
            
        }
        
        return  oldToNew[head];
        
    }
};

//OPTIMISED
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        
        Node* it = head;
        
        while(it){
            
            Node* temp = new Node(it->data);
            
            temp->next = it->next;
            it->next = temp;
            it = temp->next;
            
        }
        
        it = head;
        
        while(it){
            
            if(it->random == NULL){
                it = it->next->next;
                continue;
            }
            
            it->next->random = it->random->next;
            it = it->next->next;
            
        }
        
        Node* dummyHead = new Node(-1);
        Node* newIt = dummyHead;
        it = head;

//DONT OVERCOMPLICATE IT    
        while(it){
            
            newIt->next = it->next;
            newIt = newIt->next;
            it->next = it->next->next;
            it = it->next;
            
        }
        
        
        // while(it){
        //     cout<<it->data<<endl;
        //     it = it->next;
        // }
        
        return dummyHead->next;
        
    }
};