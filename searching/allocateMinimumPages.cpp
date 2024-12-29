class Solution {
    
    bool isPossible(vector<int>& arr , int maxi , int k){
        
        int personDone = 0;
        int curr = 0;
        for(auto i : arr){
            if(i > maxi)
                return false;
                
            if(curr + i <= maxi){
                curr += i;
            }
            else{
                curr = i;
                personDone++;
            }
            
            if(personDone == k)return false;
        }
        return true;
    }
    
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n)return -1;
        if(k == n)return *max_element(arr.begin() , arr.end());
        int low = *max_element(arr.begin() , arr.end()) , high = accumulate(arr.begin() , arr.end() , 0);
        
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(isPossible(arr , mid , k)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
            
        }
        return ans;
    }
};