class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        priority_queue<pair<int, int>> maxHeap;

        int n = mat.size();
        int m = mat[0].size();

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    count++;
                }

                maxHeap.push({count, -i});
            }
        }
        auto top = maxHeap.top();
        return {-top.second, top.first};
    }
};