class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        
        double result = (pow(((1 + sqrt5) / 2), n + 1) - pow(((1 - sqrt5) / 2), n + 1)) / sqrt5;
        
        return (int)round(result);
    }
};