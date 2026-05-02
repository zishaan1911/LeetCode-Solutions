class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int cursum = nums[i] + nums[left] + nums[right];
                
                if (abs(target - cursum) < abs(target - closum)) {
                    closum = cursum;
                } 

                if (cursum == target) {
                    return cursum;
                } 
                else if (cursum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return closum;
    }
};