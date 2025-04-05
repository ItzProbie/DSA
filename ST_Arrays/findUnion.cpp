//tc - o(n1 + n2)
//sc - o(n1 + n2)

class Solution {
    public:
      // a,b : the arrays
      // Function to return a list containing the union of the two arrays.
      vector<int> findUnion(vector<int> &a, vector<int> &b) {
          // Your code here
          // return vector with correct order of elements
          vector<int>ans;
          int it1 = 0 , it2 = 0;
          int n1 = a.size() , n2 = b.size();
          
          while(it1 < n1 && it2 < n2){
              
              int x1 = a[it1] , x2 = b[it2];
              
              if(x1 < x2){
                  ans.push_back(x1);
                  while(it1 < n1 && a[it1] == x1)
                      it1++;
              }
              
              else if(x2 < x1){
                  ans.push_back(x2);
                  while(it2 < n2 && b[it2] == x2)
                      it2++;
              }
              
              else{
                  ans.push_back(x1);
                  while(it1 < n1 && a[it1] == x1)
                      it1++;
                  while(it2 < n2 && b[it2] == x2)
                      it2++;
              }
              
          }
          
          while(it1 < n1){
              
              int x = a[it1];
              ans.push_back(x);
              while(it1 < n1 && a[it1] == x)
                  it1++;
              
          }
          while(it2 < n2){
              
              int x = b[it2];
              ans.push_back(x);
              while(it2 < n2 && b[it2] == x)
                  it2++;
              
          }
          
          return ans;
          
      }
  };