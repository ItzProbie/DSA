//tc - o(n cube)
//sc - o(k)
class Solution {

    typedef long long ll;

    vector<vector<int>> twoSum(int start , int end , ll target , vector<int>& nums){

        vector<vector<int>>ans;
        while(start < end){

            ll currSum = nums[start] + nums[end];

            if(currSum == target){
                ans.push_back({nums[start] , nums[end]});
                int temp = nums[start];
                while(start < end && nums[start] == temp)
                    start++;
                temp = nums[end];
                while(end > start && nums[end] == temp)
                    end--;
            }
            
            else if(currSum < target)
                start++;

            else
                end--;

        }

        return ans;

    }

    vector<vector<int>> threeSum(int start , int end , ll target , vector<int>& nums){

        vector<vector<int>>ans;
        for(int i = start ; i < end-1 ; i++){

            if(i != start && nums[i] == nums[i-1])
                continue;

            vector<vector<int>>temp = twoSum(i+1 , end , target - nums[i] , nums);
            for(auto& i1 : temp){
                i1.push_back(nums[i]);
                ans.push_back(i1);
            }

        }

        return ans;

    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector<vector<int>>ans;

        for(int i = 0 ; i < n-3 ; i++){

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            vector<vector<int>>temp = threeSum(i+1 , n-1 , (ll)target - nums[i] , nums);
            for(auto& i1 : temp){
                i1.push_back(nums[i]);
                ans.push_back(i1);
            }

        }

        return ans;

    }
};