class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int,int>freq;
        for(auto i : arr)
            freq[i]++;
        vector<int>ans;
        for(auto i : freq){
            if(i.second > 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};