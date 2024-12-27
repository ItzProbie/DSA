class Solution {
public:
    string longestPrefix(string s) {
        
        int n = s.size();
        if(n == 1)return "";
        vector<int>lps(n);

        lps[0] = 0;

        int it = 1 , length = 0;
        while(it < n){

            if(s[it] == s[length]){
                length++;
                lps[it] = length;
                it++;
            }
            else{
                if(length == 0){
                    lps[it] = 0;
                    it++;
                }
                else{
                    length = lps[length - 1];
                }
            }

        }

        // for(auto i : lps)cout<<i<<" ";

        return lps.back() == 0 ? "" : s.substr(0 , lps.back());

    }
};