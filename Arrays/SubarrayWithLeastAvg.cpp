class Solution{
    typedef unsigned long long ull;
	public:
	int least_average(vector<int>nums, int k)
	{
	    // Code here
	    
	    int n = nums.size();
	    int start = 0 , end = 0;
	    ull curr = 0;
	    
	    pair<ull,int>ans = {LLONG_MAX , -1};
	    
	    while(end < n){
	        
	        curr += nums[end];
	        
	        if(end - start + 1 == k){
	            if(curr < ans.first){
	                ans = {curr , start};
	            }
	            curr -= nums[start];
	            start++;
	        }
	        
	        end++;
	    }
	    
	    return ans.second + 1;
	    
	}  
};