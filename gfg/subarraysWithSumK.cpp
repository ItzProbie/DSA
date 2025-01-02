// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int>m;
        int currSum = 0;
        m[0] = 1;
        
        int cnt = 0;
        
        for(auto num : arr){
            
            // num - req = k
            currSum += num;
            int req = currSum - k;
            
            if(m.find(req) != m.end()){
                cnt += m[req];
            }
            
            m[currSum]++;
            
        }
        
        return cnt;
        
    }
};