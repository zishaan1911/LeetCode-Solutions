class Solution {
public:
    int climbStairs(int n) {
        
        return round((pow(((1 + sqrt(5)) / 2), n + 1) - pow(((1 - sqrt(5)) / 2), n + 1)) / sqrt(5));
    }
};