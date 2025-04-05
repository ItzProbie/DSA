//tc - o(n)
//sc - o(1)
//!!! x1 != x2
class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            
            int n = nums.size();
            int cnt1 = 0 , cnt2 = 0;
            int x1 , x2;
    
            for(int i = 0 ; i < n ; i++){
    
                int curr = nums[i];
    
                //if a cnt exist for this curr
                if(cnt1 > 0 && x1 == curr){
                    cnt1++;
                }
                else if(cnt2 > 0 && x2 == curr){
                    cnt2++;
                }
    
                //check if any cnts is zero?
                else if(cnt1 == 0){
                    x1 = curr;
                    cnt1++;
                }
                else if(cnt2 == 0){
                    x2 = curr;
                    cnt2++;
                }
    
                else{
                    cnt1--;
                    cnt2--;
                }
    
            }
    
            vector<int>ans;
            if(count(nums.begin() , nums.end() , x1) > n/3)
                ans.push_back(x1);
            if(x1 != x2 && count(nums.begin() , nums.end() , x2) > n/3)
                ans.push_back(x2);
    
            return ans;
    
        }
    };