class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        int min_len = INT_MAX;
        int max_len = 0;
        
        for (const string& word : wordDict) {
            wordSet.insert(word);
            int len = word.length();
            min_len = min(min_len, len);
            max_len = max(max_len, len);
        }
        
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = min_len; i <= n; ++i) {
            int start_j = max(0, i - max_len);
            int end_j = i - min_len;
            
            for (int j = end_j; j >= start_j; --j) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};