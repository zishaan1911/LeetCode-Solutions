class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        
        while (i < words.size()) {
            int j = i + 1;
            int lineLength = words[i].length();
            while (j < words.size() && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            int numWords = j - i;
            int numSpaces = maxWidth - lineLength;
            string line = "";
            
            if (j == words.size() || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } 
            else {
                int spacesBetween = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToApply = spacesBetween + (extraSpaces-- > 0 ? 1 : 0);
                        line += string(spacesToApply, ' ');
                    }
                }
            }
            
            res.push_back(line);
            i = j;
        }
        
        return res;
    }
};