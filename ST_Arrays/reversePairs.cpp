//tc - o(nlongn)
//sc - o(logn + n)
class Solution {

    bool validPair(int x1 , int x2){

        long long temp = 2*(long long)x2;
        return temp < x1;

    }

    void count(int low , int mid , int high , vector<int>& nums , int& cnt){

        int it1 = low , it2 = mid+1;

        while(it1 <= mid && it2 <= high){

            int x1 = nums[it1] , x2 = nums[it2];

            if(validPair(x1 , x2)){
                cnt += (mid-it1+1);
                it2++;
            }
            else
                it1++;

        }

    }

    void conquer(int low , int mid , int high , vector<int>& nums){

        int it1 = low , it2 = mid+1;
        vector<int>temp;

        while(it1 <= mid && it2 <= high){

            int x1 = nums[it1] , x2 = nums[it2];

            if(x1 <= x2)
                temp.push_back(nums[it1++]);
            else
                temp.push_back(nums[it2++]);

        }

        while(it1 <= mid)
            temp.push_back(nums[it1++]);
        while(it2 <= high)
            temp.push_back(nums[it2++]);

        for(int i = low ; i <= high ; i++)
            nums[i] = temp[i - low];

    }

    void divide(int low , int high , vector<int>& nums , int& cnt){

        if(low >= high)
            return;

        int mid = low + (high - low)/2;

        divide(low , mid , nums , cnt);
        divide(mid+1 , high , nums , cnt);
        count(low , mid , high , nums , cnt);

        conquer(low , mid , high , nums);

    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        divide(0 , n-1 , nums , cnt);
        return cnt;
    }
};