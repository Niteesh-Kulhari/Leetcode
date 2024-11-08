class Solution {
private:
    void bfs(vector<vector<int>> &grid, int &ans, queue<tuple<int, int, int>> &q){
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        // up, down, left, right
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        while(!q.empty()){
            int r = get<0>(q.front());
            int c = get<1>(q.front());
            int t = get<2>(q.front());
            ans = max(ans, t);
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1){
                    q.push({newRow, newCol, t+1});
                    grid[newRow][newCol] = 2;
                }
            } 
        }
        cout << ans << endl;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                }
            }
        }

        if(q.size() >= 1){
            bfs(grid, ans, q);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};