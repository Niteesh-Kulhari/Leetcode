class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     //brute force
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m*n - 1;

        while( low <= high){
            int  mid = low + (high -low)/2;
            int element = matrix[mid/n][mid%n];
            if( target == element){
                return true;
            }else if( target < element){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }




     return false;   
    }
};