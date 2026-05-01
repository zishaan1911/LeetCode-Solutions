class Solution {
    signed char memo[21][21]; 

public:
    bool isMatch(string s, string p) {
        for (int i = 0; i <= s.length(); i++)
            for (int j = 0; j <= p.length(); j++)
                memo[i][j] = -1;
                
        return dp(0, 0, s, p);
    }

    bool dp(int i, int j, const string& s, const string& p) {
        if (memo[i][j] != -1) return memo[i][j];
        
        bool result;
        if (j == p.length()) {
            result = (i == s.length());
        } else {
            bool first_match = (i < s.length() && 
                               (p[j] == s[i] || p[j] == '.'));

            if (j + 1 < p.length() && p[j + 1] == '*') {
                result = dp(i, j + 2, s, p) || 
                         (first_match && dp(i + 1, j, s, p));
            } else {
                result = first_match && dp(i + 1, j + 1, s, p);
            }
        }
        
        return memo[i][j] = result;
    }
};