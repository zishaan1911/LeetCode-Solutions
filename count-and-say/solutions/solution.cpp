class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        // Recursive call to get the previous term
        string prev = countAndSay(n - 1);
        return rle(prev);
    }

private:
    string rle(string s) {
        string result = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int count = 1;
            // Count how many times the current character repeats
            while (i + 1 < n && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            // Append the count, then the character itself
            result += to_string(count);
            result += s[i];
        }
        
        return result;
    }
};