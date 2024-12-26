class Solution {
    
    void f(int idx , string& s , unordered_set<string>& ans){
        
        if(idx == s.size()){
            ans.insert(s);
            return;
        }
        
        for(int i = idx ; i < s.size() ; i++){
            
            if(i != idx && s[i] == s[idx])
                continue;
                
            swap(s[i] , s[idx]);
            f(idx+1 , s , ans);
            swap(s[i] , s[idx]);
            
        }
        
    }
    
    
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        // sort(s.begin() , s.end());
        // vector<string>ans = {s};
        
        // while(next_permutation(s.begin() , s.end())){
        //     ans.push_back(s);
        // }
        
        // return ans;
        unordered_set<string>st;
        f(0 , s , st);
        vector<string>ans(st.begin() , st.end());
        return ans;
        
    }
};