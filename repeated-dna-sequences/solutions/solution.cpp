class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10) return res;

        unordered_set<string> seen;
        unordered_set<string> added;

        for (int i = 0; i <= static_cast<int>(s.length()) - 10; ++i) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                if (!added.count(sub)) {
                    res.push_back(sub);
                    added.insert(sub);
                }
            } else {
                seen.insert(sub);
            }
        }

        return res;
    }
};