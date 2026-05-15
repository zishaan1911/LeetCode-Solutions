class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end = nums.size();
        for (int i = 0; i < end; i++) {
            if (!nums[i]) {
                nums.erase(nums.begin() + i);
                nums.insert(nums.begin(), 0);
            }
            else if (nums[i] == 2) {
                nums.erase(nums.begin() + i);
                nums.push_back(2);
                i--;
                end--;
            }
        }
    }
};