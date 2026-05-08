class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // While the current number is in the range [1, n] 
            // and is not at its correct sorted position...
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap it to its target index (nums[i] - 1)
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Second pass to find the first index that doesn't match the expected value
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all positions are correct, the missing number is n + 1
        return n + 1;
    }
};