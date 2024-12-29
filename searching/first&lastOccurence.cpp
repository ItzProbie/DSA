class Solution {
    
    int firstOcc(vector<int>& arr , int x){
        
        int low = 0 , high = arr.size()-1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            int curr = arr[mid];
            
            if(curr == x){
                ans = mid;
                high = mid-1;
            }
            else if(curr < x)
                low = mid+1;
            else
                high = mid-1;
            
        }
        
        return ans;
        
    }
    
    
    int lastOcc(vector<int>& arr , int x){
        
        int low = 0 , high = arr.size()-1;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            int curr = arr[mid];
            
            if(curr == x){
                ans = mid;
                low = mid+1;
            }
            else if(curr < x)
                low = mid+1;
            else
                high = mid-1;
            
        }
        
        return ans;
        
    }
    
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int fo = firstOcc(arr , x);
        if(fo == -1)
            return {-1,-1};
        return {fo , lastOcc(arr , x)};
    }
};