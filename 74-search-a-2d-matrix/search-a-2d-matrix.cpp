class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     //brute force
        cout << matrix.size() << endl;
        cout << matrix[0].size() << endl;


        for(int i=0; i<matrix.size(); i++){
            for( int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
     return false;   
    }
};