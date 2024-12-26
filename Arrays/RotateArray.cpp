class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n = arr.size();
        d %= n;
        reverse(arr.begin() , arr.begin() + d);
        reverse(arr.begin() + d , arr.end());
        reverse(arr.begin() , arr.end());
    }
};

// idx - 0 1 2 3 4
// arr - 1 2 3 4 5

// idx - 0 1 2 3 4
// arr - 3 4 5 1 2

// d = 2

// arr[i] = arr[(i+d)%n]