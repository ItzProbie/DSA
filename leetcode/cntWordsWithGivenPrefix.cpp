class Solution {

    bool f(string& c , string& p){
        int nc = c.size() , np = p.size();
        if(np < nc)return false;
        return p.substr(0 , nc) == c;
    }

public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto& i : words){
            if(f(pref , i))
                cnt++;
        }
        return cnt;
    }
};