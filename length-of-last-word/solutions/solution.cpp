class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) {
            if (s[0] == ' ') return 0;
            else return 1;
        }
        reverse(s.begin(), s.end());
        int i = 0;
        int len = 0;
        while (s[i] == ' ') i++;
        while (i < s.size() && s[i] != ' ') {
            len++;
            i++;
        }
        return len;

    }
};