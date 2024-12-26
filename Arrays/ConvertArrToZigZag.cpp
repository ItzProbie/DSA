class Solution {
  public:
    void zigZag(vector<int> &arr) {
        // code here
        
        //brute force
        // sort(arr.begin() , arr.end());
        // for(int i = 1 ; i < arr.size()-1 ; i+=2){
        //     swap(arr[i] , arr[i+1]);
        // }
        
        bool smaller = true;
        for(int i = 0 ; i < arr.size()-1 ; i++){
            
            if(smaller){
                smaller = !smaller;
                if(arr[i] < arr[i+1])
                    continue;
                swap(arr[i] , arr[i+1]);        
            }
            else{
                smaller = !smaller;
                if(arr[i] > arr[i+1])
                    continue;
                swap(arr[i] , arr[i+1]);
            }
            
        }
    }
};