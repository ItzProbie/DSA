class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        
        int low = 0 , high = arr.size() - 1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            int curr = arr[mid];
            
            if(curr == key)
                return mid;
                
            else if(arr[low] <= arr[mid]){
                
                if(key >= arr[low] && key < arr[mid])
                    high = mid-1;
                else
                    low = mid+1;
                
            }
            
            else{
                
                if(key > arr[mid] && key <= arr[high])
                    low = mid+1;
                else
                    high = mid-1;
                
            }
            
        }
        
        return -1;
        
    }
};




