class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        int res = min(ones, n - ones);
        if (ones>=1) res = min(res, ones-1);

        if (n >= 3) {
            int mid = ones - (s[0]=='1') - (s[n-1] =='1');
            int cost = (s[0]!='1') + mid + (s[n-1] !='1');
            res = min(res, cost);
        }
        return res;
    }
};