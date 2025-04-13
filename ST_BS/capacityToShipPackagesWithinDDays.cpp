//tc - o(nlogn)
//sc - o(1)
class Solution {
    public:
        int shipWithinDays(vector<int>& wt, int days) {
            int n = wt.size();
            int low = *max_element(wt.begin() , wt.end()) , high = accumulate(wt.begin() , wt.end() , 0);
            int ans = -1;
            while(low <= high){
    
                int mid = low + (high - low)/2;
                int cnt = 1 , curr = 0;
                bool b  = true;
                for(auto i : wt){
                    curr += i;
                    if(curr > mid){
                        cnt++;
                        curr = i;
                    }
                    if(cnt > days){
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