//MEMOIZATION
class Solution {

    int mod = 1e9 + 7;

    //idx -> currIdx , i.e currSize = idx;
    unsigned long long f(int idx , int zero , int one , int low , int high , vector<unsigned long long>& dp){

        if(idx > high)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        //stophere
        unsigned long long stophere = (idx >= low && idx <= high ? 1 : 0);

        //pick1
        unsigned long long pick1 = f(idx+one , zero , one , low , high , dp);

        //pick0
        unsigned long long pick0 = f(idx+zero , zero , one , low , high , dp);

        return dp[idx] = (stophere + pick1 + pick0)%mod;

    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<unsigned long long>dp(high+1 , -1);
        return f(0 , zero , one , low , high , dp);

    }
};

//TABULATION
class Solution {

    int mod = 1e9 + 7;

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        // vector<unsigned long long>dp(high+1 , -1);
        // return f(0 , zero , one , low , high , dp);
        vector<unsigned long long>dp(high+1 , 0);

        for(int idx = high ; idx >= 0 ; idx--){

             //stophere
            unsigned long long stophere = (idx >= low && idx <= high ? 1 : 0);
            //pick1
            unsigned long long pick1 = (idx + one > high) ? 0 : dp[idx+one];
            //pick0
            unsigned long long pick0 = (idx + zero > high) ? 0 : dp[idx+zero];

            dp[idx] = (stophere + pick1 + pick0)%mod;

        }

        return dp[0];

    }
};