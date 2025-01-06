//BRUTE - ACCEPTED
class Solution {

    int lc(int idx , string& boxes){
        int cnt = 0;
        for(int i = idx-1 ; i >= 0 ; i--){

            int diff = idx - i;
            if(boxes[i] == '1')
                cnt += diff;

        }
        return cnt;
    }
    int rc(int idx , string& boxes){
        int cnt = 0;
        for(int i = idx+1 ; i < boxes.size() ; i++){

            int diff = i - idx;
            if(boxes[i] == '1')
                cnt += diff;

        }
        return cnt;
    }

public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        vector<int>ans(n);

        for(int i = 0 ; i < n ; i++)
            ans[i] = lc(i , boxes) + rc(i , boxes);
        

        return ans;

    }
};

//OPTIMISED - 