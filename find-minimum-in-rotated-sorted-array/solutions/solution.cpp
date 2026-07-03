class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] < nums[n-1]) return nums[0];
        for (int i = n-2; i >= 0; i--) {
            if (nums[i+1] < nums[i]) return nums[i+1];
        }
        return -1;
    }
};