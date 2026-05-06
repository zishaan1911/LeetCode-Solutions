class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                // Convert char digit to an integer bit position (0-8)
                int num = board[i][j] - '1';
                int mask = 1 << num;
                
                // Determine sub-box index
                int box_idx = (i / 3) * 3 + (j / 3);
                
                // Check if the bit is already set in row, col, or box
                if ((rows[i] & mask) || (cols[j] & mask) || (boxes[box_idx] & mask)) {
                    return false;
                }
                
                // Mark the bit as seen
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[box_idx] |= mask;
            }
        }
        
        return true;
    }
};