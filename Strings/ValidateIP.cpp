class Solution {
    
    bool allChars(string& s){
        for(auto i : s){
            if(!(i >= '0' && i <= '9'))
                return false;
        }
        return true;
    }
    
  public:
    int isValid(string& s) {
        // code here
        stringstream ss(s);
        int cnt = 0;
        string curr = "";
        
        while(getline(ss , curr , '.')){
            cnt++;
            if(cnt > 4 || !allChars(curr) || curr == "")return false;
            int num = stoi(curr);
            if(num < 0 || num > 255 || curr.size() != (to_string(num)).size())return false;
        }
        
        return cnt == 4;
    }
};