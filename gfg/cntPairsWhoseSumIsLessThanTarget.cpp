int countPairs(vector<int> &arr, int target) {
        // Your code here
        int n = arr.size();
        sort(arr.begin() , arr.end());
        int cnt = 0;
        for(int i = 0 ; i < n-1 ; i++){
            int curr = arr[i];
            if(curr > target)break;
            
            int low = i + 1 , high = n-1;
            int ans = -1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(curr + arr[mid] < target){
                    ans = mid;
                    low = mid+1;
                }
                else
                    high = mid-1;
            }
            if(ans == -1)break;
            cnt += ans - i;
            
        }
        return cnt;
    }