class Solution {
    unordered_map<string, int> adjSteps;
    vector<vector<string>> ans;
    string bWord;

    void dfs(string word, vector<string>& seq) {
        if (word == bWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = adjSteps[word];
        int sz = word.size();

        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (adjSteps.count(word) && adjSteps[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); 
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        if (st.find(endWord) == st.end()) return {};

        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        
        adjSteps[beginWord] = 0;
        bWord = beginWord;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = adjSteps[word];

            if (word == endWord) break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        adjSteps[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (adjSteps.count(endWord)) {
            vector<string> seq = {endWord};
            dfs(endWord, seq);
        }

        return ans;
    }
};