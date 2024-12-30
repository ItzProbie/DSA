class Solution {
    
    void fillSet(vector<int>& arr , unordered_set<int>& s){
        for(auto i : arr)
            s.insert(i);
    }
    
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>s;
        fillSet(a , s);
        fillSet(b , s);
        return s.size();
    }
};