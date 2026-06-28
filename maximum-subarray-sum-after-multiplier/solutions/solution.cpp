class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        int n = nums.size();

        for (int op = 0; op < 2; op++) {
            long long d0 = -1e18, d1 = -1e18, d2 = -1e18;
            for (int i = 0; i < n; i++) {
                long long v = nums[i];
                long long t = (op == 0) ? v * k : (v >= 0 ? v/k: -((-v)/k));
                long long n0 = max(d0, 0LL) + v;
                long long n1 = max({d0, d1, 0LL}) +t;
                long long n2 = max(d1,d2) + v;
                d0 = n0; d1 = n1; d2=n2;
                ans = max({ans,d0,d1,d2});
            }
        }
        return ans;
    }
};