class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int trappingWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>pm(n) , nm(n);
        pm[0] = arr[0];
        nm[n-1] = arr[n-1];
        for(int i = 1 ; i < n ; i++){
            pm[i] = max(arr[i] , pm[i-1]);
            nm[n-1-i] = max(arr[n-1-i] , nm[n-i]);
        }
        
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            cnt += max(0 , min(pm[i] , nm[i]) - arr[i]);
        }
        
        return cnt;
        
    }
};