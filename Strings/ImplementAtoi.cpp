class Solution {
    
    bool isNum(char c){
        return c >= '0' && c <= '9';
    }
    
  public:
    int myAtoi(char *s) {
        // Your code here
        string str = s;
        
        int start = 0;
        int n = str.size();
        
        // unsigned long long ans;
        while(start < n && (str[start] == '0' || str[start] == ' '))
            start++;
            
        if(start == n)return 0;
        
        if(start == n-1){
            return (isNum(str[start])) ? static_cast<int>(str[start] - '0') : 0;
        }
        
        bool isNeg = str[start] == '-';
        if(isNeg)
            start++;
            
        if(!isNum(str[start]))return 0;
        
        long long ans = 0;
        int ret = 0;
        
        for(start ; start < n ; start++){
            if(isNum(str[start])){
                ans *= 10;
                if( isNeg ? -1*ans < INT_MIN : ans > INT_MAX )return isNeg ? INT_MIN : INT_MAX;
                ans += static_cast<int>(str[start] - '0');
                ret = ans;
            }
            else
                break;
        }
        
        return isNeg ? -1*ret : ret;
        
    }
};