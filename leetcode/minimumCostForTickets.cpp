//MEMOISATION
class Solution {

    int f(int idx , vector<bool>& day , int final , vector<int>& cost , vector<int>& dp){

        if(idx > final)
            return 0;

        if(!day[idx])
            return f(idx+1 , day , final , cost , dp);

        if(dp[idx] != -1)
            return dp[idx];

        return dp[idx] = min({cost[0] + f(idx+1 , day , final , cost , dp) , cost[1] + f(idx+7 , day , final , cost , dp) , cost[2] + f(idx+30 , day , final , cost , dp)});

    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int final = days.back();
        final;
        vector<bool>day(final + 1 , false);
        vector<int>dp(final + 1 , -1);

        for(auto i : days)
            day[i] = true;

        return f(1 , day , final , costs , dp);

    }
};

//TABULATION
class Solution {

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int final = days.back();
        vector<bool>day(final + 1 , false);
        // vector<int>dp(final + 1 , -1);
        vector<int>dp(final + 1 , 0);

        for(auto i : days)
            day[i] = true;

        // return f(1 , day , final , costs , dp);

        for(int idx = days.back() ; idx > 0 ; idx--){

            if(!day[idx]){
                dp[idx] = dp[idx+1];
                continue;
            }
                

            dp[idx] = min({costs[0] + (idx+1 >= dp.size() ? 0 : dp[idx+1]) ,
                           costs[1] + (idx+7 >= dp.size() ? 0 : dp[idx+7]) ,
                           costs[2] + (idx+30 >= dp.size() ? 0 : dp[idx+30])});

        }

        return dp[1];

    }
};