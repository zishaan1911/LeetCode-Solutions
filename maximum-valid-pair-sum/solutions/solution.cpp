class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n<k+1) return -1;

        int max_ans = INT_MIN;
        int max_i = nums[0];

        for (int j = k; j < n; j++) {
            max_i = max(max_i, nums[j-k]);
            max_ans = max(max_ans, max_i + nums[j]);
        }
        return max_ans;
    }
};