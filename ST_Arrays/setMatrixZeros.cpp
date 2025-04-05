//tc - o(row*col)
//sc - o(1)
class Solution {
    public:
        void setZeroes(vector<vector<int>>& mat) {
            
            bool fr = false , fc = false;
            int row = mat.size() , col = mat[0].size();
    
            for(int i = 0 ; i < row ; i++){
                for(int j = 0 ; j < col ; j++){
    
                    if(mat[i][j] == 0){
    
                        if(i == 0)
                            fr = true;
                        else
                            mat[i][0] = 0;
                        if(j == 0)
                            fc = true;
                        else
                            mat[0][j] = 0;
    
                            
                    }
    
                }
            }
    
            for(int i = row-1 ; i > 0 ; i--){
                for(int j = col-1 ; j > 0 ; j--){
    
                    if(mat[i][0] == 0 || mat[0][j] == 0)
                        mat[i][j] = 0;
    
                }
            }
    
            if(fr){
                for(int j = 0 ; j < col ; j++)
                    mat[0][j] = 0;
            }
            if(fc){
                for(int j = 0 ; j < row ; j++)
                    mat[j][0] = 0;
            }
    
        }
    };