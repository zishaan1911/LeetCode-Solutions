class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> charMap;
        for (char c : s) {
            charMap[c]++;
        }
        
        for (char c : t) {
            if (!charMap.count(c) || charMap[c] == 0) return false;
            charMap[c]--;
        }
        
        return true;
    }
};