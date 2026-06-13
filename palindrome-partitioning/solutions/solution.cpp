class Solution {
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(int start, const string& s, vector<string>& currentPartition, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPartition);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                currentPartition.push_back(s.substr(start, end - start + 1));
                
                backtrack(end + 1, s, currentPartition, result);
                
                currentPartition.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentPartition;
        backtrack(0, s, currentPartition, result);
        return result;
    }
};