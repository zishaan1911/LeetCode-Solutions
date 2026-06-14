class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        vector<int> cuts(n);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            int min_cut = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j <= 2 || isPal[j + 1][i - 1])) {
                    isPal[j][i] = true;
                    
                    if (j == 0) {
                        min_cut = 0;
                    } else {
                        min_cut = min(min_cut, cuts[j - 1] + 1);
                    }
                }
            }
            cuts[i] = min_cut;
        }

        return cuts[n - 1];
    }
};