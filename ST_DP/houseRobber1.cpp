//tc - o(n)
//sc - o(1)
int rob(vector<int>& nums) {
        
    int n = nums.size();

    if(n < 3)
        return n == 1 ? nums.back() : max(nums[0] , nums[1]);

    int ob = max(nums[0] , nums[1]);
    int tb = nums[0];

    for(int idx = 2 ; idx < n ; idx++){

        int curr = max(ob , nums[idx] + tb);
        tb = ob;
        ob = curr;

    }

    return ob;

}