
//MEMOIZATION
class Solution {

    int f(int idx1 , int idx2 , vector<string>& words , string& target , vector<vector<int>>& dp , vector<vector<int>>& cnt){

        int mod = 1e9 + 7;

        if(idx2 == 0){
            return 1;
        }
        if(idx1 == 0)
            return 0;

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        int ans = 0;

        int currCharCnt = cnt[idx1-1][static_cast<int>(target[idx2-1] - 'a')];
        //pick
        ans = currCharCnt == 0 ? 0 : ((unsigned long long)(ans + f(idx1-1 , idx2-1 , words , target , dp , cnt)) * currCharCnt)%mod;

        //skip
        ans = (ans + f(idx1-1 , idx2 , words , target , dp , cnt))%mod;


        return dp[idx1][idx2] = ans%mod;
    }

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();

        int nt = target.size();
        vector<vector<int>>cnt(n , vector<int>(26 , 0));
        
        for(auto i : words){

            for(int idx = 0 ; idx < n ; idx++){

                char c = i[idx];
                cnt[idx][static_cast<int>(c - 'a')]++;

            }

        }

        vector<vector<int>>dp(n+1 , vector<int>(nt+1 , -1));
        return f(n , nt , words , target , dp , cnt);

    }
};

//TABULATION
class Solution {

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int mod = 1e9 + 7;
        int nt = target.size();
        vector<vector<int>>cnt(n , vector<int>(26 , 0));
        
        for(auto i : words){

            for(int idx = 0 ; idx < n ; idx++){

                char c = i[idx];
                cnt[idx][static_cast<int>(c - 'a')]++;

            }

        }

        // vector<vector<int>>dp(n+1 , vector<int>(nt+1 , -1));
        // return f(n , nt , words , target , dp , cnt);

        vector<vector<int>>dp(n+1 , vector<int>(nt+1 , 0));

        for(int idx1 = 0 ; idx1 <= n ; idx1++)
            dp[idx1][0] = 1;

        for(int idx1 = 1 ; idx1 <= n ; idx1++){
            for(int idx2 = 1 ; idx2 <= nt ; idx2++){

                int ans = 0;

                int currCharCnt = cnt[idx1-1][static_cast<int>(target[idx2-1] - 'a')];
                //pick
                ans = currCharCnt == 0 ? 0 : ((unsigned long long)(ans + dp[idx1-1][idx2-1]) * currCharCnt)%mod;

                //skip
                ans = (ans + dp[idx1-1][idx2])%mod;


                dp[idx1][idx2] = ans%mod;

            }
        }

        return dp[n][nt];

    }
};

//SPACE OPTIMIZED TABULATION - 1
class Solution {

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int mod = 1e9 + 7;
        int nt = target.size();
        vector<vector<int>>cnt(n , vector<int>(26 , 0));
        
        for(auto i : words){

            for(int idx = 0 ; idx < n ; idx++){

                char c = i[idx];
                cnt[idx][static_cast<int>(c - 'a')]++;

            }

        }

        // vector<vector<int>>dp(n+1 , vector<int>(nt+1 , -1));
        // return f(n , nt , words , target , dp , cnt);

        // vector<vector<int>>dp(n+1 , vector<int>(nt+1 , 0));

        vector<int>prev(nt+1 , 0) , curr(nt+1 , 0);

        for(int idx1 = 0 ; idx1 <= n ; idx1++)
            prev[0] = curr[0] = 1;

        for(int idx1 = 1 ; idx1 <= n ; idx1++){
            for(int idx2 = 1 ; idx2 <= nt ; idx2++){

                int ans = 0;

                int currCharCnt = cnt[idx1-1][static_cast<int>(target[idx2-1] - 'a')];
                //pick
                ans = currCharCnt == 0 ? 0 : ((unsigned long long)(ans + prev[idx2-1]) * currCharCnt)%mod;

                //skip
                ans = (ans + prev[idx2])%mod;


                curr[idx2] = ans%mod;

            }
            prev = curr;
        }

        return prev[nt];

    }
};

//SPACE OPTIMIZED TABULATION - 2
class Solution {

public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int mod = 1e9 + 7;
        int nt = target.size();
        vector<vector<int>>cnt(n , vector<int>(26 , 0));
        
        for(auto i : words){

            for(int idx = 0 ; idx < n ; idx++){

                char c = i[idx];
                cnt[idx][static_cast<int>(c - 'a')]++;

            }

        }

        // vector<vector<int>>dp(n+1 , vector<int>(nt+1 , -1));
        // return f(n , nt , words , target , dp , cnt);

        // vector<vector<int>>dp(n+1 , vector<int>(nt+1 , 0));

        vector<int>prev(nt+1 , 0);

        for(int idx1 = 0 ; idx1 <= n ; idx1++)
            prev[0] = 1;

        for(int idx1 = 1 ; idx1 <= n ; idx1++){
            for(int idx2 = nt ; idx2 >= 1 ; idx2--){

                int ans = 0;

                int currCharCnt = cnt[idx1-1][static_cast<int>(target[idx2-1] - 'a')];
                //pick
                ans = currCharCnt == 0 ? 0 : ((unsigned long long)(ans + prev[idx2-1]) * currCharCnt)%mod;

                //skip
                ans = (ans + prev[idx2])%mod;


                prev[idx2] = ans%mod;

            }
            // prev = curr;
        }

        return prev[nt];

    }
};