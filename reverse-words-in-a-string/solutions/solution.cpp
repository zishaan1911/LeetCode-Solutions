#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            
            if (i >= n) break;

            
            string word = "";
            while (i < n && s[i] != ' ') {
                word.push_back(s[i]);
                i++;
            }
            
            words.push_back(word);
        }

        
        string result = "";
        for (int j = words.size() - 1; j >= 0; j--) {
            result += words[j];
            if (j > 0) {
                result += " ";
            }
        }

        return result;
    }
};