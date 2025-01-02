class Solution {

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        
        int n = words.size();
        vector<int>pref(n , 0);

        if(isVowel(words[0][0]) && isVowel(words[0].back()))
            pref[0]++;

        for(int idx = 1 ; idx < n ; idx++){

            pref[idx] = (isVowel(words[idx][0]) && isVowel(words[idx].back()) ? 1 : 0) + pref[idx-1];

        }

        vector<int>ans(q.size());
        for(int i = 0 ; i < q.size() ; i++){
            int from = q[i][0] , to = q[i][1];

            ans[i] = pref[to] - (from == 0 ? 0 : pref[from-1]);

        }

        return ans;

    }
};