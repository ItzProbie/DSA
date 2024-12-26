class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
    bool isRotated(string& s1, string& s2) {
        // Your code here
        int n = s1.size();
        if(n != s2.size())return false;
        
        if(n == 1)return false;
        
        if(s1[0] == s2[n-2] && s1[1] == s2[n-1]){
            bool b = true;
            for(int i = 2 ; i < n && b ; i++){
                if(s1[i] != s2[i-2])
                    b = false;
            }
            if(b)return true;
        }
        
        if(s1[n-2] == s2[0] && s1[n-1] == s2[1]){
            bool b = true;
            for(int i = 2 ; i < n-2 && b ; i++){
                if(s1[i] != s2[i+2])
                    b = false;
            }
            if(b)return true;
        }
        
        return false;
    }
};