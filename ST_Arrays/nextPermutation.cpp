//tc - o(n)
//sc - o(1)
class Solution {

    int getDip(vector<int>& arr){

        int n = arr.size();
        int j = n-2;

        while(j >= 0){

            if(arr[j] < arr[j+1])
                return j;

            j--;

        }

        return -1;

    }

public:
    void nextPermutation(vector<int>& arr) {
        
        int n = arr.size();
        int dip = getDip(arr);
        cout<<dip<<'\n';

        if(dip == -1){
            reverse(arr.begin() , arr.end());
            return;
        }

        int j = n-1;
        while(j > dip){
            if(arr[j] > arr[dip])
                break;
            j--;
        }
        swap(arr[dip] , arr[j]);
        reverse(arr.begin() + dip + 1 , arr.end());

    }
};

//2 7 1 5 4 0
//2 7 4 0 1 5

//2 7 1 5 4 0
//2 7 4 5 1 0

