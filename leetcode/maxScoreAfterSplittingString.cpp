class Solution {

public:
    int maxScore(string s) {
        
        int n = s.size();
        vector<int>ztn(n , 0);
        vector<int>otn(n , 0);
        int prev = 0;
        int p = 0;
        for(int i = 0 ; i < n ; i++){
            ztn[i] = prev + (s[i] == '0' ? 1 : 0);
            prev = ztn[i];

            int j = n - 1 - i;
            otn[j] = p + (s[j] == '1' ? 1 : 0);
            p = otn[j];

        }

        int ans = 0;
        for(int i = 0 ; i < n-1 ; i++)
            ans = max(ans , ztn[i] + otn[i+1]);

        return ans;

    }
};