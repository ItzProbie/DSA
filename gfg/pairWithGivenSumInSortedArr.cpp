class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int low = 0 , high = arr.size() - 1 , cnt = 0;
        while(low < high){
            int curr = arr[low] + arr[high];
            
            if(curr == target){
                
                if(arr[low] == arr[high]){
                    int tot = high - low + 1;
                    cnt += (tot*(tot-1))/2;
                    break;
                }
                
                int lc = 1 , rc = 1;
                while(low+1 < high && arr[low] == arr[low+1]){
                    low++;
                    lc++;
                }
                while(high-1 > low && arr[high-1] == arr[high]){
                    high--;
                    rc++;
                }
                cnt += (lc*rc) ;
                low++ , high--;

            }
            else if(curr > target)
                high--;
            else
                low++;
        }
        return cnt;
    }
};