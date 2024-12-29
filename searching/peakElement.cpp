class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        
        int low = 0 , high = arr.size() - 1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            int curr = arr[mid];
            
            int left = (mid-1 < 0 ? INT_MIN : arr[mid-1]);
            int right = (mid+1 == arr.size() ? INT_MIN : arr[mid+1]);
            
            if(left < curr && right < curr)
                return mid;
                
            else if(right > curr){
                low = mid+1;
            }
            else
                high = mid-1;
            
        }
        
        return -1;
        
        
    }
};