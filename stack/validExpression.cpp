class Solution {
    
  public:
    bool valid(string &s) {
        // code here
        
        stack<char>st;
        for(auto i : s){
            
            if(i == '(' || i == '[' || i == '{')
                st.push(i);
                
            else{
                if(st.empty())
                    return false;
                    
                char c = st.top();
                if(i == ')'){
                    if(c != '(')return false;
                    st.pop();

                }
                else if(i == ']'){
                    if(c != '[')return false;
                    st.pop();

                }
                else{
                    if(c != '{')return false;
                    st.pop();
                }
            }
            
        }
        return st.empty();
        
    }
};