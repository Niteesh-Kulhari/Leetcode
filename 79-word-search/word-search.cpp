class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(backtrack(board, i, j, word, 0)){
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board,int row, int col, string word, int index){
        if(index == word.length()){
            return true;
        }
        
        int n = board.size();
        int m = board[0].size();

        if(row < 0 || row >= n || col < 0 || col >= m || board[row][col] != word[index]){
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';
        

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};


        for(int i=0; i<4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(backtrack(board, newRow, newCol, word, index+1)){
                return true;
            }
        }

        board[row][col] = temp;
        return false;

    }
};