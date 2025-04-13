//tc - o(logn)
//sc - o(1)
class Solution {
    public:
        int findMin(vector<int>& nums) {
            
            int n = nums.size();
            if(nums[0] <= nums.back())
                return nums[0];
    
            int low = 0 , high = n-1;
    
            while(low <= high){
    
                int mid = low + (high - low)/2;
    
                if(mid != 0 && nums[mid] < nums[mid-1])
                    return nums[mid];
    
                if(nums[mid] >= nums[0])
                    low = mid+1;
                else
                    high = mid-1;
    
            }
    
            return -1;
    
        }
    };

//if duplicatea are present problem can be solved at best in o(n) worst case complexity
//e.g - [4 4 4 4 3 4 4 4] -> find 3