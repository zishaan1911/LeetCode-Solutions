class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];

            auto it1 = s2t.find(c1);
            if (it1 != s2t.end() && it1->second != c2) return false;

            auto it2 = t2s.find(c2);
            if (it2 != t2s.end() && it2->second != c1) return false;

            s2t[c1] = c2;
            t2s[c2] = c1;
        }

        return true;
    }
};