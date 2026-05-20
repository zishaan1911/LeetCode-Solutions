#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void backtrack(const string& s, int startIndex, vector<string>& currentSegments, vector<string>& result) {
        if (currentSegments.size() == 4) {
            if (startIndex == s.length()) {
                std::string ip = currentSegments[0] + "." + currentSegments[1] + "." + 
                                 currentSegments[2] + "." + currentSegments[3];
                result.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            // Guard against running past the end of the string
            if (startIndex + len > s.length()) break;

            std::string segmentStr = s.substr(startIndex, len);
            
            // Rule 1: No leading zeros (e.g., "01" is invalid, but "0" is valid)
            if (segmentStr.length() > 1 && segmentStr[0] == '0') continue;

            // Rule 2: The value must be between 0 and 255
            int segmentNum = std::stoi(segmentStr);
            if (segmentNum > 255) continue;

            // Step Forward: Choose this segment
            currentSegments.push_back(segmentStr);
            
            // Recurse to find the next segment
            backtrack(s, startIndex + len, currentSegments, result);
            
            // Step Backward: Backtrack to try a different length
            currentSegments.pop_back();
        }
    }

public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        
        // Quick pruning: an IP string must be between 4 and 12 characters long
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }

        std::vector<std::string> currentSegments;
        backtrack(s, 0, currentSegments, result);
        return result;
    }
};