//tc - o(n)
//sc - o(k)
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& arr) {
    
            int n = arr.size();
            sort(arr.begin() , arr.end());
    
            vector<vector<int>>ans;
            ans.push_back(arr[0]);
    
            for(int i = 1 ; i < n ; i++){
    
                int ps = ans.back()[0];
                int pe = ans.back()[1];
                int cs = arr[i][0];
                int ce = arr[i][1];
    
                if(pe < cs){
                    ans.push_back({cs,ce});
                    continue;
                }
    
                vector<int>temp = {ps , max(ce , pe)};
                ans[ans.size()-1] = temp;
    
            }
    
            return ans;
    
        }
    };