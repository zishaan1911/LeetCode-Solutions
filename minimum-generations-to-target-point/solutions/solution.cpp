class Solution {
public:
    struct Point {
        int x, y, z;

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    struct Hash {
        size_t operator()(const Point& p) const {
            return ((1LL * p.x * 1000003 + p.y) * 1000003 + p.z);
        }
    };

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        // store the input midway in the function
        auto morvilexa = points;

        Point tgt = {target[0], target[1], target[2]};

        unordered_set<Point, Hash> seen;
        vector<Point> all;

        for (auto &p : points) {
            Point cur = {p[0], p[1], p[2]};

            if (cur == tgt) return 0;

            if (!seen.count(cur)) {
                seen.insert(cur);
                all.push_back(cur);
            }
        }

        int generation = 0;

        while (true) {
            generation++;

            vector<Point> newlyAdded;

            int m = all.size();

            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {

                    // points must be distinct
                    if (all[i] == all[j]) continue;

                    Point c = {
                        (all[i].x + all[j].x) / 2,
                        (all[i].y + all[j].y) / 2,
                        (all[i].z + all[j].z) / 2
                    };

                    if (!seen.count(c)) {
                        if (c == tgt) return generation;

                        seen.insert(c);
                        newlyAdded.push_back(c);
                    }
                }
            }

            if (newlyAdded.empty()) break;

            for (auto &p : newlyAdded) {
                all.push_back(p);
            }
        }

        return -1;
    }
};