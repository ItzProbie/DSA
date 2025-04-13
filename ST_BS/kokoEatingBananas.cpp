//tc - o(nlogn)
//sc - o(1)
class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int n = piles.size();
            int low = 1 , high = *max_element(piles.begin() , piles.end()) , ans = -1;
            while(low <= high){
    
                int mid = low + (high - low)/2;
                bool b = true;
                int cnt = 0;
                for(auto i : piles){
                    cnt += (i <= mid ? 1 : (i/mid + (i%mid!=0)));
                    if(cnt > h){
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