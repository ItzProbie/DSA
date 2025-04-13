//tc - o(nlogn)
//sc - o(n)
class Solution {
    public:
        int smallestDivisor(vector<int>& nums, int th) {
            int low = 1 , high = *max_element(nums.begin() , nums.end());
            int ans = -1;
            while(low <= high){
    
                int mid = low + (high - low)/2;
                bool b = true;
                int cnt = 0;
                for(auto i : nums){
                    cnt += i/mid + (i%mid!=0);
                    if(cnt > th){
                        b = false;
                        break;
                    }
                }
    
                if(b){
                    ans = mid;
                    high = mid-1;
                }
                else
                    low = mid+1;
    
            }
    
            return ans;
        }
    };