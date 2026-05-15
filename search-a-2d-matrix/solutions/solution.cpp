class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0, bottom = matrix.size() - 1;
        int row = -1;
        
        while (top <= bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][0] <= target) {
                row = mid;
                top = mid + 1;
            } else {
                bottom = mid - 1;
            }
        }
        if (row == -1) return false;

        int left = 0, right = matrix[0].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return false;
    }
};