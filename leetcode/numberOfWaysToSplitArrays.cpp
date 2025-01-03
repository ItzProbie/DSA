//SOL - 1
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();        
        vector<long long>pref(n) , suff(n);
        pref[0] = nums[0] , suff[n-1] = nums[n-1];

        for(int i = 1 ; i < n ; i++){
            int j = n - 1 - i;
            pref[i] = pref[i-1] + nums[i];
            suff[j] = suff[j+1] + nums[j];
        }

        int cnt = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(pref[i] >= suff[i+1])
                cnt++;
        }
        
        return cnt;

    }
};

//SOL - 2
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = accumulate(nums.begin() , nums.end() , 0L);

        long long currSum = 0;
        int cnt = 0;
        for(int k = 0 ; k < nums.size() - 1 ; k++){

            int i = nums[k];

            total -= i;
            currSum += i;

            if(currSum >= total)
                cnt++;

        }

        return cnt;

    }
};

