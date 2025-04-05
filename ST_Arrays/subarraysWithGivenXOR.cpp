//tc - o(n)
//sc - o(1)
int Solution::solve(vector<int> &nums, int target) {
    
    //[a] ^ [b] = [c]
    //[c] ^ [a] = [b]
    
    unordered_map<int,int>m;
    m[0] = 1;
    
    int currXOR = 0 , cnt = 0;
    
    for(int i = 0 ; i < nums.size() ; i++){
        
        currXOR ^= nums[i];
        
        //prevSubarrXOR ^ targetSubarrXOR = currXOR
        //prevSubarrXOR = currXOR ^ targetSubarrXOR
        
        cnt += m[currXOR ^ target];
        m[currXOR]++;
        
    }
    
    return cnt;
    
}
