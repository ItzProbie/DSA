
//SC - O(n)
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<bool>a(n+1 , false);
    
        for(auto i : arr){
            if(i > 0 && i <= n)
                a[i] = true;
        }
        
        for(int i = 1 ; i <= n ; i++){
            if(!a[i])return i;
        }
        return n+1;
    }
};

//SC - O(1)
class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        for(auto& i : arr){
            
            if(i <= 0)
                i = n+1;
        }
        
        for(auto i : arr){
            
            int curr = abs(i);
            if(curr <= n)
                arr[curr-1] = -1*(abs(arr[curr-1]));
            
        }
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > 0)
                return i+1;
        }
        
        return n+1;
    }
};