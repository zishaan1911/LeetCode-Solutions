class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
            }
            else continue;
        }
        if (s.empty()) return true;
        if (s.size() == 1) return true;
        if (s.size() == 2) {
            if (tolower(static_cast<unsigned char>(s[0])) == tolower(static_cast<unsigned char>(s[1]))) return true;
            else return false;
        }
        for (int i = 0; i < s.size()/2; i++) {
            if (tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[s.size()-1-i]))) {
                return false;
            }
        }
        return true;
    }
};