class Solution {
public:
    int strStr(string haystack, string needle) {
        string o = "";
        for (int i = 0; i < haystack.size() || o == needle; i++) {
            o = haystack.substr(i, needle.size());
            if (o == needle) {
                return i;
            }
        }

        return -1;
        
    }
};