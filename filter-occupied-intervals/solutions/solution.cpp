class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& a, int L, int R) {
        sort(a.begin(), a.end());
        vector<vector<int>> m, ans;

        for (auto &x : a) {
            if (m.empty() || x[0] > m.back()[1] + 1) m.push_back(x);
            else m.back()[1] = max(m.back()[1], x[1]);
        }

        for (auto &x : m) {
            int l = x[0],r = x[1];
            if (r < L || l > R) ans.push_back({l, r});
            else {
                if (l < L) ans.push_back({l, L-1});
                if (r > R) ans.push_back({R+1, r});
            }
        }
        return ans;
        
    }
};