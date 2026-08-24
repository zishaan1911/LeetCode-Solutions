class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                count++;
                n--;
                i--;
            }
        }
        while (count > 0) {
            nums.push_back(0);
            count--;
        }

    }
};