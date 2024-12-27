class Solution {
    
    vector<int> getLPS(string& pat){
        
        int n = pat.size();
        vector<int>lps(n);
        
        lps[0] = 0;
        
        int length = 0;
        
        int it = 1;
        while(it < n){
            
            if(pat[it] == pat[length]){
                length++;
                lps[it] = length;
                it++;
            }
            else{
                if(length == 0){
                    lps[it] = 0;
                    it++;
                }
                else{
                    length = lps[length-1];
                }
            }
            
        }
        
        return lps;
        
    }
    
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
        
        int np = pat.size() , nt = txt.size();
        
        vector<int>lps = getLPS(pat);
        
        int i = 0 , j = 0;
        //i -> text
        //j -> pattern
        
        vector<int>ans;
        
        while(i < nt){
            
            if(pat[j] == txt[i]){
                i++ , j++;
            }
            
            if(j == np){
                ans.push_back(i - np);
                j = lps[j-1];
            }
            else if(i < nt && pat[j] != txt[i]){
                
                if(j == 0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
                
            }
            
            
        }
        
        return ans;
    }
};