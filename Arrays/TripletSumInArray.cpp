class Solution {
    
    bool f(int start , int target , vector<int>& arr){
        
        int end = arr.size() - 1;
        
        while(start < end){
            
            int curr = arr[start] + arr[end];
            
            if(curr == target)
                return true;
                
            else if(curr > target)
                end--;
            else
                start++;
            
        }
        
        return false;
        
    }
    
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        sort(arr.begin() , arr.end());
        
        int n = arr.size();
        
        for(int i = 0 ; i < n-2 ; i++){
            
            if(f(i+1 , target - arr[i] , arr))
                return true;
            
        }
        
        return false;
        
    }
};