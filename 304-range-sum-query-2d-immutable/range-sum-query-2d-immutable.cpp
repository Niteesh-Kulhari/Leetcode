class NumMatrix {
private:
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
       int row = matrix.size();
       int col = matrix[0].size();
       mat.resize(row, vector<int>(col, 0));

       for(int i=0; i<row; i++){
        int sum = 0;
        for(int j=0; j<col; j++){
            sum += matrix[i][j];
            if(i == 0){
                mat[i][j] = sum; 
            }else{
                mat[i][j] = sum + mat[i-1][j];
            }
        }
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = mat[row2][col2];
        int extra1 = (col1>0) ? mat[row2][col1-1] : 0;
        int extra2 = (row1>0) ? mat[row1-1][col2] : 0;
        int extra3 = (row1 > 0 && col1 > 0) ? mat[row1-1][col1-1] : 0;

        int ans = total - extra1 - extra2 + extra3;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */