class Solution {
  public:
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        stack<Node*>st;
        for(auto i : arr)
            st.push(i);
    
        while(st.size() > 1){
            
            Node* it1 = st.top();
            st.pop();
            Node* it2 = st.top();
            st.pop();
            
            Node* dummyHead = new Node(-1);
            Node* it = dummyHead;
            
            while(it1 && it2){
                
                if(it1->data <= it2->data){
                    it->next = it1;
                    it1 = it1->next;
                }
                else{
                    it->next = it2;
                    it2 = it2->next;
                }
                
                it = it->next;
                
            }
            
            if(it1)
                it->next = it1;
            if(it2)
                it->next = it2;
            
            st.push(dummyHead->next);
            
        }
        
        return st.top();
        
    }
};