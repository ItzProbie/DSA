class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>s(a.begin() , a.end());
        vector<int>ans;
        for(auto i : b){
            if(s.find(i) != s.end()){
                ans.push_back(i);
                s.erase(i);
            }
        }
        return ans;
    }
};