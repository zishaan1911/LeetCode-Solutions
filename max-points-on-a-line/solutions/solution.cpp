#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int global_max = 0;
        const double EPSILON = 1e-9; // To handle floating-point precision inaccuracies

        for (int i = 0; i < n; i++) {
            vector<double> angles;
            int duplicate = 1;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                // atan2 returns a value between -PI and +PI
                angles.push_back(atan2(dy, dx));
            }

            sort(angles.begin(), angles.end());

            // Find the longest consecutive sequence of identical angles
            int local_max = 0;
            int current_run = 0;
            for (size_t k = 0; k < angles.size(); k++) {
                if (k == 0 || abs(angles[k] - angles[k - 1]) < EPSILON) {
                    current_run++;
                } else {
                    local_max = max(local_max, current_run);
                    current_run = 1;
                }
            }
            local_max = max(local_max, current_run);
            global_max = max(global_max, local_max + duplicate);
        }

        return global_max;
    }
};