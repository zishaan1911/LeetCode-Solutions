#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].length();
        int totalLen = wordCount * wordLen;

        // Count frequency of each word in the input list
        unordered_map<string, int> wordFreq;
        for (const string& w : words) {
            wordFreq[w]++;
        }

        // We only need to check starting positions from 0 to wordLen - 1
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;

            // Slide the window across the string in jumps of wordLen
            for (int j = i; j <= n - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordFreq.count(word)) {
                    seen[word]++;
                    count++;

                    // If we have more of 'word' than allowed, shrink from the left
                    while (seen[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found a valid concatenation
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Word not in list: Reset window
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};