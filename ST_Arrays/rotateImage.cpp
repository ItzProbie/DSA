//tc - o(n*n + n*n)
//sc - o(1)
class Solution {
    public:
        void rotate(vector<vector<int>>& mat) {
    
            int row = mat.size() , col = mat[0].size();
            
            for(int i = 1 ; i < row ; i++){
    
                for(int j = 0 ; j < i ; j++){
    
                    swap(mat[i][j] , mat[j][i]);
    
                }
    
            }
    
            for(auto& i : mat)  
                reverse(i.begin() , i.end());
    
                
        }
    };