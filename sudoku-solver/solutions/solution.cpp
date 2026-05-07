class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, r, c, num)) {
                            board[r][c] = num; // Tentatively place
                            
                            if (solve(board)) return true; // Recurse
                            
                            board[r][c] = '.'; // Backtrack
                        }
                    }
                    return false; // Trigger backtracking for previous cells
                }
            }
        }
        return true; // Puzzle solved
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check Row
            if (board[row][i] == c) return false;
            // Check Column
            if (board[i][col] == c) return false;
            // Check 3x3 Box
            // (row / 3 * 3) finds the top row of the current 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};