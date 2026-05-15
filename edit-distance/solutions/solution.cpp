class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m < n) return minDistance(word2, word1);
        if (n == 0) return m;

        // Use only two rows for O(n) space
        vector<int> prev(n + 1);
        vector<int> curr(n + 1);

        for (int j = 0; j <= n; j++) prev[j] = j;

        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            // MATH OPTIMIZATION: 
            // We only need to check cells where |i - j| is reasonably small.
            // For general LeetCode constraints, we still do the full row,
            // but we use space compression and cache-friendly access.
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    // Min of Replace, Delete, Insert
                    int res = prev[j - 1]; // Replace
                    if (prev[j] < res) res = prev[j]; // Delete
                    if (curr[j - 1] < res) res = curr[j - 1]; // Insert
                    curr[j] = 1 + res;
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};