class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // 3. Convert to long long to handle the absolute value of INT_MIN safely
        // labs() is used for long absolute values
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);
        long long quotient = 0;

        // 4. Exponential subtraction logic (Bit Manipulation)
        // We want to see how many "doubled" divisors fit into the dividend
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Shift left (double) the divisor until doubling it again 
            // would exceed the remaining dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the largest power-of-two multiple found
            absDividend -= tempDivisor;
            // Add the corresponding power-of-two to the quotient
            quotient += multiple;
        }

        // 5. Apply the sign and return
        return isNegative ? (int)-quotient : (int)quotient;
    }
};