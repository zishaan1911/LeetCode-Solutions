class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle the edge case where n = INT_MIN
        long long N = n; 
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        
        // Recursively find half the power
        double half = fastPow(x, n / 2);
        
        // If n is even: x^n = x^(n/2) * x^(n/2)
        // If n is odd:  x^n = x^(n/2) * x^(n/2) * x
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};