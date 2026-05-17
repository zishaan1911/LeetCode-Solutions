class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
     int rows = board.size();
        int cols = board[0].size();
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Start DFS if the first letter matches
                if (board[r][c] == word[0] && dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int index) {
        // Base case: if we've matched all characters
        if (index == word.length()) {
            return true;
        }
        
        // Check boundaries and character match
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        // Mark the cell as visited by saving it and replacing it
        char temp = board[r][c];
        board[r][c] = '#'; 
        
        // Explore all 4 adjacent directions
        bool found = dfs(board, word, r + 1, c, index + 1) || // Down
                     dfs(board, word, r - 1, c, index + 1) || // Up
                     dfs(board, word, r, c + 1, index + 1) || // Right
                     dfs(board, word, r, c - 1, index + 1);   // Left
        
        // Backtrack: restore the original character
        board[r][c] = temp;
        
        return found;
    }
};