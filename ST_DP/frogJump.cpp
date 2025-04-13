//tc - o(n)
//sc - o(n + n)
class Solution {
    
    int f(int idx , vector<int>& height , vector<int>& dp){
        
        if(idx == 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
            
        //1back
        int ob = abs(height[idx] - height[idx-1]) + f(idx-1 , height , dp);
        
        //2back
        int tb = idx == 1 ? 1e9 : abs(height[idx] - height[idx-2]) + f(idx-2 , height , dp);
        
        return dp[idx] = min(ob , tb);
    }
    
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n , -1);
        return f(n-1 , height , dp);
    }
};

//tc - o(n)
//sc - o(n)
int minCost(vector<int>& height) {
    // Code here
    int n = height.size();
    vector<int>dp(n , 0);
    
    for(int idx = 1 ; idx < n ; idx++){
        
        //1back
        int ob = abs(height[idx] - height[idx-1]) + dp[idx-1];
        
        //2back
        int tb = idx == 1 ? 1e9 : abs(height[idx] - height[idx-2]) + dp[idx-2];
        
        dp[idx] = min(ob , tb);
        
    }
    
    return dp.back();
    
}

//tc - o(n)
//sc - o(1)
int minCost(vector<int>& height) {
    // Code here
    int n = height.size();
    int oneb = 0 , twob = 0;
    
    for(int idx = 1 ; idx < n ; idx++){
        
        //1back
        int ob = abs(height[idx] - height[idx-1]) + oneb;
        
        //2back
        int tb = idx == 1 ? 1e9 : abs(height[idx] - height[idx-2]) + twob;
        
        int curr = min(ob , tb);
        
        twob = oneb;
        oneb = curr;
        
    }
    
    return oneb;
    
}