class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O') {
            return;
        }
        
        board[r][c] = '#';
        
        dfs(board, r + 1, c, rows, cols);
        dfs(board, r - 1, c, rows, cols);
        dfs(board, r, c + 1, rows, cols);
        dfs(board, r, c - 1, rows, cols);
    }

public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) return;
        int cols = board[0].size();
        
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0, rows, cols);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1, rows, cols);
        }
        
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j, rows, cols);
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j, rows, cols);
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};