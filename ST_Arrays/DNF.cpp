//tc - o(n)
//sc - o(1)
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            
            int n = nums.size();
    
            int low = 0 , mid = 0 , high = n-1;
    
            while(mid <= high){
    
                int curr = nums[mid];
    
                if(curr == 0){
                    swap(nums[mid] , nums[low]);
                    low++ , mid++;
                }
                else if(curr == 1){
                    mid++;
                }
                else{
                    swap(nums[mid] , nums[high]);
                    high--;
                }
    
            }
    
        }
    };
    
    //0 - low-1    : 0
    //low - mid-1  : 1
    //mid - high   : unsorted
    //high+1 - n-1 : 2 