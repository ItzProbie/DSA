class Solution {

    vector<int> createLPS(string& child){

        int n = child.size();
        vector<int>lps(n);
        lps[0] = 0;
        int idx = 1;
        int len = 0;

        while(idx < n){

            if(child[idx] == child[len]){
                len++;
                lps[idx] = len;
                idx++;
            }
            else{
                if(len == 0){
                    lps[idx] = 0;
                    idx++;
                }
                else{
                    len = lps[len-1];
                }
            }

        }

        return lps;
    }

    bool kmp(string& parent , string& child , vector<int>& lps){
    
        int np = parent.size();
        int nc = child.size();

        if(np < nc)
            return false;
    
        int idxc = 0 , idxp = 0;

        while(idxp < np){

            if(child[idxc] == parent[idxp]){
                idxc++ , idxp++;
            }

            if(idxc == nc)
                return true;

            else if(idxp < np && child[idxc] != parent[idxp]){
                if(idxc == 0)
                    idxp++;
                else
                    idxc = lps[idxc-1];
            }
            

        }

        return false;
    
    }

public:
    vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>>lps(n);
        for(int i = 0 ; i < n ; i++)
            lps[i] = createLPS(words[i]);

        vector<string>ans;
        for(int i = 0 ; i < n ; i++){
            bool found = false;
            for(int j = 0 ; j < n && !found ; j++){
                if(i == j)continue;
                if(kmp(words[j] , words[i] , lps[i])){
                    found = true;
                    ans.push_back(words[i]);
                }
            }
        }
        return ans;
    }
};