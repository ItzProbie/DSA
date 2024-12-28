class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>>ans;
        int n = arr.size();
        
        for(int i = 0 ; i < n-2 ; i++){
            
            int curr = arr[i];
            unordered_map<int,vector<int>>m;
            for(int j = i + 1 ; j < n ; j++){
                
                //curr + arr[j] + req = 0
                //req = - (curr + arr[j])
                
                int req = -1 * (curr + arr[j]);
                
                if(m.find(req) != m.end()){
                    
                    for(auto num : m[req]){
                        ans.push_back({i , num , j});
                    }
                    
                }
                
                m[arr[j]].push_back(j);
                
                
            }
            
        }
        
        return ans;
        
    }
};