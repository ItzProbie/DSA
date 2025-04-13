//tc - o(n)
//sc - o(1)
class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            int low = 0 , high = n-1;
            while(low <= high){
    
                int mid = low + (high - low)/2;
    
                int prev = mid == 0 ? true : nums[mid-1] < nums[mid];
                int next = mid == n-1 ? true : nums[mid+1] < nums[mid];
    
                if(prev && next)
                    return mid;
    
                if(mid+1 != n && nums[mid] < nums[mid+1])
                    low = mid+1;
                else
                    high = mid-1;
    
            }
    
            return -1;
        }
    };