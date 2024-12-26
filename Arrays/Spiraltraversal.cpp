class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int row = mat.size() , col = mat[0].size();
        vector<int>ans(row*col);
        int it = 0;
        int i , j;
        
        int sr , sc , er , ec;
        sr = sc = 0;
        er = row-1 , ec = col-1;
        
        
        while(it < row*col){
            for(j = sc ; j <= ec ; j++){
                ans[it++] = mat[sr][j];
            }
            for(i = sr+1 ; i <= er && it < row*col ; i++){
                ans[it++] = mat[i][ec];
            }
            for(int j = ec-1 ; j >= sc && it < row*col ; j--){
                ans[it++] = mat[er][j];
            }
            for(int i = er-1 ; i > sr && it < row*col ; i--){
                ans[it++] = mat[i][sc];
            }
            sr++ , sc++ , er-- , ec--;
        }
        return ans;
    }
};