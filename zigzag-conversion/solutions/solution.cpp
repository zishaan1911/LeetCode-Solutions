class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }
        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingdown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingdown = !goingdown;
            }

            currentRow += goingdown ? 1 : -1;
        }
        
        string result = "";
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};