//tc - o(nlogn)
//sc - o(logn + n)
class Solution {
    public:
      // Function to count inversions in the array.
      int cnt;
      
      void count(int low , int mid , int high , vector<int>& arr){
          
          int it1 = low , it2 = mid+1;
          
          while(it1 <= mid && it2 <= high){
              
              int x1 = arr[it1] , x2 = arr[it2];
              
              if(x1 > x2){
                  cnt += (mid+1-it1);
                  it2++;
              }
              else
                  it1++;
              
          }
          
          
          
      }
      
      void conquer(int low , int mid , int high , vector<int>& arr){
          
          vector<int>temp;
          
          int it1 = low , it2 = mid+1;
          while(it1 <= mid && it2 <= high){
              
              if(arr[it1] <= arr[it2])
                  temp.push_back(arr[it1++]);
              else
                  temp.push_back(arr[it2++]);
              
          }
          
          while(it1 <= mid)
              temp.push_back(arr[it1++]);
          while(it2 <= high)
              temp.push_back(arr[it2++]);
              
          for(int i = low ; i <= high ; i++)
              arr[i] = temp[i-low];
          
      }
      
      void divide(int low , int high , vector<int>& arr){
          
          if(low >= high)
              return;
              
          int mid = low + (high - low)/2;
              
          divide(low , mid , arr);
          divide(mid+1 , high , arr);
          
          count(low , mid , high , arr);
          conquer(low , mid , high , arr);
          
      }
      
      int inversionCount(vector<int> &arr) {
          // Your Code Here
          this->cnt = 0;
          int n = arr.size();
          divide(0 , n-1 , arr);
          return this->cnt;
      }
  };