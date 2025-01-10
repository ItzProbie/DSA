class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>freq(26 , 0);
        unordered_set<string>s(words2.begin() , words2.end());
        for(auto i : s){
            vector<int>temp(26 , 0);
            for(auto c : i){
                temp[c - 'a']++;
            }
            for(int i1 = 0 ; i1 < 26 ; i1++)
                freq[i1] = max(freq[i1] , temp[i1]);
        }
        vector<string>ans;
        for(auto i : words1){
            vector<int>temp(26 , 0);

            for(auto c : i){
                temp[c - 'a']++;
            }
            bool b = true;
            for(int j = 0 ; j < 26 && b ; j++){
                if(freq[j] > temp[j])
                    b = false;
            }
            if(b)ans.push_back(i);
        }
        return ans;
    }
};