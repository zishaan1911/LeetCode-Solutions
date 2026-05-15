class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> target(128, 0);
        for (char c : t) target[c]++;

        int required = 0;
        for(int count : target) if(count > 0) required++;

        int left = 0, right = 0;
        int formed = 0;
        vector<int> windowCounts(128, 0);

        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCounts[c]++;
            if (target[c] > 0 && windowCounts[c] == target[c]) {
                formed++;
            }
            while (left <= right && formed == required) {
                c = s[left];
                
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                windowCounts[c]--;
                if (target[c] > 0 && windowCounts[c] < target[c]) {
                    formed--;
                }

                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};