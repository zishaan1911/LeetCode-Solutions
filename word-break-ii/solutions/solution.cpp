class Solution {
    unordered_map<string, vector<string>> memo;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        memo.clear();
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

private:
    vector<string> dfs(const string& s) {
        if (memo.count(s)) {
            return memo[s];
        }
        
        if (s.empty()) {
            return {""};
        }
        
        vector<string> result;
        
        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);
            
            if (wordSet.count(prefix)) {
                string suffix = s.substr(i);
                vector<string> suffixSubsentences = dfs(suffix);
                
                for (const string& subsentence : suffixSubsentences) {
                    if (subsentence.empty()) {
                        result.push_back(prefix);
                    } else {
                        result.push_back(prefix + " " + subsentence);
                    }
                }
            }
        }
        
        return memo[s] = result;
    }
};