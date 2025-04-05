//tc - o(n1 + n2)
//sc - o(1)
class Solution {
    public:
        void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
            
            int toGo = n1+n2-1 , it1 = n1-1 , it2 = n2-1;
            
            while(it1 >= 0 && it2 >= 0){
    
                int x1 = nums1[it1];
                int x2 = nums2[it2];
    
                if(x1 >= x2){
                    nums1[toGo--] = nums1[it1--];
                }
                else{
                    nums1[toGo--] = nums2[it2--];
                }
    
            }
    
            while(it2 >= 0)
                nums1[toGo--] = nums2[it2--];       
    
        }
    };