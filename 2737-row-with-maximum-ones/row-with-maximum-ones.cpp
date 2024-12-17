class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ansCount = 0;
        int ansRow = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                count += mat[i][j];
            }

            if(count > ansCount){
                ansCount = count;
                ansRow = i;
            }
        }

        return {ansRow, ansCount};
    }
};