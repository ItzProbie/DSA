//Sol - 1
class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        unordered_map<string , int>m;
        unordered_map<int , vector<int>>ref;
        int it = 0;
        for(int idx = 0 ; idx < arr.size() ; idx++){
            
            string i = arr[idx];
            
            sort(i.begin() , i.end());
            if(m.find(i) == m.end()){
                m[i] = it++;
                ref[it-1].push_back(idx);
            }
            else
                ref[m[i]].push_back(idx);
            
            
        }
        
        vector<vector<string>>ans;
        
        for(auto i : m){
            
            vector<string>temp;
            for(auto idx : ref[i.second])
                temp.push_back(arr[idx]);
            ans.push_back(temp);
            
        }
        
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};

//Sol - 2
class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        unordered_map<string , vector<int>>m;
        for(int idx = 0 ; idx < arr.size() ; idx++){
            
            string i = arr[idx];
            
            sort(i.begin() , i.end());
            m[i].push_back(idx);
            
        }
        
        vector<vector<string>>ans;
        
        for(auto i : m){
            
            vector<string>temp;
            for(auto idx : i.second)
                temp.push_back(arr[idx]);
            ans.push_back(temp);
            
        }
        
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};