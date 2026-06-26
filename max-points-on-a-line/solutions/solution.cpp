#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
struct PointHash {
    size_t operator()(const vector<int>& p) const {
        return ((size_t)p[0] << 32) | (unsigned int)p[1];
    }
};

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        // 1. Compress Input Size by aggregating duplicates
        unordered_map<vector<int>, int, PointHash> point_counts;
        for (const auto& p : points) {
            point_counts[p]++;
        }

        // If all points are duplicates
        if (point_counts.size() == 1) return n;

        vector<vector<int>> unique_points;
        vector<int> counts;
        for (const auto& [pt, cnt] : point_counts) {
            unique_points.push_back(pt);
            counts.push_back(cnt);
        }

        int m = unique_points.size();
        int global_max = 0;

        // 2. Main Loop
        for (int i = 0; i < m; i++) {
            // Pruning: If the remaining potential unique points + current duplicates 
            // cannot beat global_max, we can stop.
            int remaining_possible = counts[i];
            for(int k = i + 1; k < m; k++) remaining_possible += counts[k];
            if (remaining_possible <= global_max) break;

            // Custom hash map utilizing 64-bit integer keys (No String Overhead)
            unordered_map<uint64_t, int> slope_counts;
            int local_max = 0;

            for (int j = i + 1; j < m; j++) {
                int dx = unique_points[j][0] - unique_points[i][0];
                int dy = unique_points[j][1] - unique_points[i][1];

                int g = std::gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Standardize slope orientation
                if (dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;
                }

                // Bit-pack dy and dx into a single 64-bit key
                uint64_t slope_key = ((uint64_t)dy << 32) | (uint32_t)dx;
                
                // Add the weight/count of point j
                slope_counts[slope_key] += counts[j];
                local_max = max(local_max, slope_counts[slope_key]);
            }
            
            // Add the weight of the base point i itself
            global_max = max(global_max, local_max + counts[i]);
        }

        return global_max;
    }
};