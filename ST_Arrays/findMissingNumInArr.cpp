//tc - o(n)
//sc - o(1)
class Solution {

    int sumOfFirstNIntegers(int n){
        return (n*(n+1))/2;
    }

public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int currSum = 0;

        for(auto i : nums){
            currSum += i > n ? 0 : i;
        }


        int expSum = sumOfFirstNIntegers(n);
        // cout<<currSum<<' '<<expSum;
        return expSum - currSum;

    }
};

//1 + 2 + 3 + 4 = 10
//n*(n+1)/2

//1 + 4 + 9 + 16 = 30
//n*(n+1)*(2n+1)/6