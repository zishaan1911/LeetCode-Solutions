class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                // mid might be the answer, but keep looking for a larger one
                ans = mid;
                left = mid + 1;
            } else {
                // mid is too large
                right = mid - 1;
            }
        }
        
        return ans;
    }
};