class Solution {
  public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node* del_node) {
        // Your code here
        del_node->data = del_node->next->data;
        del_node->next = del_node->next->next;
    }
};