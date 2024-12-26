class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int ans = arr[0];
        int curr = 0;
        for(auto i : arr){
            curr += i;
            ans = max(ans , curr);
            curr = max(curr , 0);
        }
        return ans;
    }
};