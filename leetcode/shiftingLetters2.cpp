class Solution {

    char change(char c , int del){
        del = (del % 26);
        int curr = c - 'a' + 26;
        curr += del;
        return static_cast<char>(curr % 26 + 'a');
    }

public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n = s.size();
        vector<int>pref(n , 0);
        for(auto i : shifts){

            if(i[2] == 1){
                pref[i[0]]++;
                if(i[1]+1 != n)pref[i[1]+1]--;
            }
            else{
                pref[i[0]]--;
                if(i[1]+1 != n)pref[i[1]+1]++;
            }

        }
        s[0] = change(s[0] , pref[0]);
        for(int i = 1 ; i < n ; i++){
            pref[i] += pref[i-1];
            s[i] = change(s[i] , pref[i]);
        }
        return s;

       
    }
};