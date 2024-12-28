class Solution {
private:
    bool backTrack(vector<vector<char>>& board, string word, int row, int col, int index){
        if( index == word.length() ){
            return true;
        }

        int n = board.size();
        int m = board[0].size();
        // Check if row and col are inside the bounds
        if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] != word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';
        // Movement Left, Right, Up, Down
        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {-1, 1, 0, 0};

        for(int i=0; i<4; i++){
            int newRow = delRow[i] + row;
            int newCol = delCol[i] + col;

            if(backTrack(board, word, newRow, newCol, index+1)){
                return true;
            }
        }
        board[row][col] = temp;
        return false;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(backTrack(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};