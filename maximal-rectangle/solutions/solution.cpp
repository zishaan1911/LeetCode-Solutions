class Solution {
private:
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!s.empty() && current_height < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                
                int width = s.empty() ? i : i - s.top() - 1;
                max_area = std::max(max_area, height * width);
            }
            s.push(i);
        }
        
        return max_area;
    }

public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int max_rectangle = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0;
                }
            }
            max_rectangle = std::max(max_rectangle, largestRectangleArea(heights));
        }
        
        return max_rectangle;
    }
};