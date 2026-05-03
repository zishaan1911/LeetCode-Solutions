class Solution {
public:
    int reverseInt(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num%2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i+2) == 0) return false;
        }
        return true;
    }
    
    int sumOfPrimesInRange(int n) {
        int r = reverseInt(n);
        int lower = min(n, r);
        int upper = max(n, r);

        int sum = 0;

        for (int i = lower; i <= upper; ++i) {
            if (isPrime(i)) {
                sum += i;
            }
        }

        return sum;
    }
};