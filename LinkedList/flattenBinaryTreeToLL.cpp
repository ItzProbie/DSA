class Solution
{
    void flat(Node* curr , Node*& prev){
        
        if(!curr)
            return;
            
        if(curr->right)
            flat(curr->right , prev);
        
        if(curr->left)
            flat(curr->left , prev);


            
        if(!prev){
            prev = curr;
        }
        else{
            curr->right = prev;
            curr->left = NULL;
            prev = curr;
        }

        
    }
    
    public:
    void flatten(Node *root)
    {
        //code here
        Node* prev = NULL;
        flat(root , prev);
    }
};