class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            
            if (word == endWord) {
                return steps;
            }
            
            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];
                
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
                    word[i] = c;
                    
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, steps + 1});
                        wordSet.erase(word);
                    }
                }
                
                word[i] = originalChar;
            }
        }
        
        return 0;
    }
};