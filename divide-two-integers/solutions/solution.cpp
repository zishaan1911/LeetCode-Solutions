#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to handle absolute of INT_MIN safely
        long long n = labs(dividend);
        long long d = labs(divisor);
        long long quotient = 0;

        // Step 1: Find the largest power of 2 such that (d << i) <= n
        int i = 0;
        while (n >= (d << (i + 1))) {
            i++;
            // Prevent shifting into the sign bit of long long 
            if (i == 62) break; 
        }

        // Step 2: Iterate downwards from that power of 2
        for (; i >= 0; i--) {
            if (n >= (d << i)) {
                n -= (d << i);
                quotient |= (1LL << i); // Set the bit in the quotient
            }
        }

        return isNegative ? (int)-quotient : (int)quotient;
    }
};