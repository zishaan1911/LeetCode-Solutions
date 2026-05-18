class Solution {
private:
    unordered_map<string, bool> memo;

public:
    bool isScramble(std::string s1, std::string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + " " + s2;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        vector<int> count(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0) return memo[key] = false;
        }
        
        int n = s1.length();
        
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        
        return memo[key] = false;
    }
};