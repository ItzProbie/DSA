class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int ans = 1;
        int low = 1 , high = n/2;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(n == mid*mid)
                return mid;
            
            else if(mid*mid > n)
                high = mid-1;
                
            else{
                ans = mid;
                low = mid+1;
            }
            
        }
        
        return ans;
        
    }
};