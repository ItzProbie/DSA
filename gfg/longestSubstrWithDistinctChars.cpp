class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size() , start = 0 , end = 0;
        int ans = 1;
        int freq[26] = {0};
        
        while(end < n){
            
            int curr = s[end] -'a';
            freq[curr]++;
                
            while(freq[curr] > 1){
                
                freq[s[start] - 'a']--;
                start++;
                
            }
                
            ans = max(ans , end - start + 1);
            end++;
            
        }
        
        return ans;
        
    }
};
