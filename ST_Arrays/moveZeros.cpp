//tc - o(n)
//sc - o(1)
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            
            int nz = 0 , z = 0 , n = nums.size();
    
            while(z < n && nums[z] != 0)
                z++;
            nz = z + 1;
            while(nz < n && nums[nz] == 0)
                nz++;
    
            while(z < n && nz < n){
    
                swap(nums[z] , nums[nz]);
                while(z < n && nums[z] != 0)
                    z++;
                nz = z + 1;
                while(nz < n && nums[nz] == 0)
                    nz++;
    
            }
    
    
        }
    };