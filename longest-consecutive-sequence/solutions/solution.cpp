class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        
        int maxCount = 1;
        int currCount = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                currCount++;
            } else {
                maxCount = max(maxCount, currCount);
                currCount = 1;
            }
        }
        
        return maxCount = max(maxCount, currCount);
    }
};