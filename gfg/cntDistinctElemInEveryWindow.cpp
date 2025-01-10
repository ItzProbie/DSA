class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int , int>m;
        int n = arr.size() , start = 0 , end = 0 , x = 0;
        vector<int>ans;
        
        while(end < n){
            
            m[arr[end]]++;
            if(m[arr[end]] == 1)
                x++;
                
            if(end - start + 1 == k){
                
                ans.push_back(x);
                m[arr[start]]--;
                if(m[arr[start]] == 0)
                    x--;
                start++;
                
            }
            
            end++;
            
        }
        
        return ans;
    }
};