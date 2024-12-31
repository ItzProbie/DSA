class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int>s(arr.begin() , arr.end());
        int ans = 1;
        for(auto i : s){
            
            if(s.find(i-1) != s.end())
                continue;
                
            int cnt = 1;
            int num = i + 1;
            while(s.find(num++) != s.end())
                cnt++;
                
            ans = max(ans , cnt);
            
        }
        
        return ans;
    }
};