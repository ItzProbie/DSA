class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        sort(arr.begin() , arr.end());
        int n = arr.size();
        if(n == 1)
            return {};
        vector<int>ans = {arr[0] , arr[1]};
        
        int start = 0 , end = n-1;
        while(start < end){
            
            int sum = arr[start]+arr[end];
            if(abs(target - ans[0] - ans[1]) > abs(target - arr[start] - arr[end])){
                ans = {arr[start] , arr[end]};
            }
            else if(abs(target - ans[0] - ans[1]) == abs(target - arr[start] - arr[end])){
                if(arr[end] - arr[start] > ans[1] - ans[0])
                    ans = {arr[start] , arr[end]};
            }
            if(sum == target)
                start++;
            else if(sum > target)
                end--;
            else
                start++;
            
        }
        return ans;
    }
};