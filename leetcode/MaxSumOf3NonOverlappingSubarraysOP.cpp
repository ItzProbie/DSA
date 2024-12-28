//MENTOS Monotonic Solution but wont work for greater optodo value
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int size = n-k+1;

        vector<int>ksum(size);
        int curr = 0 , end = 0 , start = 0;

        while(end < n){

            curr += nums[end];

            if(end - start + 1 == k){

                ksum[start++] = curr;
                if(start == size)
                    break;

                curr -= nums[start-1];

            }

            end++;

        }

        vector<int>fl(size) , fr(size);

        fl[0] = 0 , fr[size-1] = size-1;

        for(int i = 1 ; i < size ; i++){
            fl[i] = ksum[i] > ksum[fl[i-1]] ? i : fl[i-1];
            // fr[size-i-1] = ksum[size-i-1] > ksum[fr[size-i]] ? size-i-1 : fr[size-i];
        }

        for(int i = size-2; i >= 0; i--) {
            fr[i] = ksum[i] >= ksum[fr[i+1]] ? i : fr[i+1];
        }

        int maxi = INT_MIN;
        vector<int>ans(3);

        for(int i = k ; i < size-k ; i++){

            int curr = ksum[i] + ksum[fl[i-k]] + ksum[fr[i+k]];
            if(curr > maxi){
                maxi = curr;
                ans = {fl[i-k] , i , fr[i+k]};
            }

        } 

        return ans;

    }
};

/*Standard DP Solution
class Solution {
    vector<int> createPrefixSum(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return prefix;
    }
    
    int getMax(int pos, int count, int k, vector<int>& prefix, vector<vector<int>>& dp) {
        if(count == 3) return 0;
        if(pos > prefix.size() - 1 - k) return 0;
        
        if(dp[pos][count] != -1) return dp[pos][count];
        
        // Don't start here
        int dont_start = getMax(pos + 1, count, k, prefix, dp);
        
        // Start here - use prefix sum to get window sum
        int window_sum = prefix[pos + k] - prefix[pos];
        int start_here = window_sum + getMax(pos + k, count + 1, k, prefix, dp);
        
        return dp[pos][count] = max(dont_start, start_here);
    }
    
    void getPath(vector<vector<int>>& dp, vector<int>& prefix, int k, int pos, int count, vector<int>& path) {
        if(count == 3) return;
        if(pos > prefix.size() - 1 - k) return;
        
        // Don't start here
        int dont_start = getMax(pos + 1, count, k, prefix, dp);
        
        // Start here
        int window_sum = prefix[pos + k] - prefix[pos];
        int start_here = window_sum + getMax(pos + k, count + 1, k, prefix, dp);
        
        if(start_here >= dont_start) {
            path.push_back(pos);
            getPath(dp, prefix, k, pos + k, count + 1, path);
        } else {
            getPath(dp, prefix, k, pos + 1, count, path);
        }
    }
    
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> prefix = createPrefixSum(nums);
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        
        getMax(0, 0, k, prefix, dp);
        
        vector<int> path;
        getPath(dp, prefix, k, 0, 0, path);
        
        return path;
    }
};*/