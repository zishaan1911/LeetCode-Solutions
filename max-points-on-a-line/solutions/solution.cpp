class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int global_max = 2; // With n > 2, the answer is at least 2

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int local_count = 2;
                
                // Extract line vector constants
                long long dx1 = points[j][0] - points[i][0];
                long long dy1 = points[j][1] - points[i][1];

                for (int k = j + 1; k < n; k++) {
                    long long dx2 = points[k][0] - points[i][0];
                    long long dy2 = points[k][1] - points[i][1];

                    // Cross product: (dx1 * dy2) - (dy1 * dx2) == 0 means collinear
                    if (dx1 * dy2 == dy1 * dx2) {
                        local_count++;
                    }
                }
                global_max = max(global_max, local_count);
            }
        }
        return global_max;
    }
};