class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int sum = 0;
        int n = arr.size();
        int start = 0 , end = 0;
        while(end < n){
            sum += arr[end];
            while(sum > target){
                sum-=arr[start];
                start++;
            }
            if(sum == target)
                return {start+1 , end+1};
            end++;
        }
        return {-1};
    }
};