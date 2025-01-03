class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        
        int curr = 0;
        unordered_map<int,int>m;
        m[0]++;
        long ans = 0;
        
        for(auto i : arr){
            
            curr ^= i;
            
            //curr = req ^ k
            
            int req = curr ^ k;
            ans += m[req];
            m[curr]++;
            
        }
        
        return ans;
        
    }
};