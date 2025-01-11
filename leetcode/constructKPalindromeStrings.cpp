class Solution {
public:
    bool canConstruct(string s, int k) {

        if(k > s.size())
            return false;

        int freq[26] = {0};
        int cntOdd = 0;
        for(auto i : s){
            int curr = i - 'a';
            freq[curr]++;
            if(freq[curr] % 2 != 0)
                cntOdd++;
            else
                cntOdd--;
        }


        return cntOdd <= k;

    }
};