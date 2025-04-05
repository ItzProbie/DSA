//tc - o(n)
//sc - o(n)
class Solution {
    public:
      int longestSubarray(vector<int>& arr, int k) {
          // code here
          int n = arr.size();
          unordered_map<int,int>m;
          m[0] = -1;
          int ans = 0;
          
          int currSum = 0;
          for(int i = 0 ; i < n ; i++){
              
              currSum += arr[i];
              //currSum - sumOfPrevSubArr = k;
              //sumOfPrevSubArr = currSum - k;
              
              if(m.find(currSum - k) != m.end()){
                  
                  int start = m[currSum - k] + 1;
                  int end = i;
                  
                  ans = max(ans , end - start + 1);
                  
              }
              
              if(m.find(currSum) == m.end())
                  m[currSum] = i;
              
              
          }
          
          return ans;
      }
  };