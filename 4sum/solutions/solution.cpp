class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int front = j + 1;
                int back = n - 1;

                while (front < back) {
                    long long sum = (long long)nums[i] + nums[j] + nums[front] + nums[back];

                    if (sum < target) {
                        front++;
                    } else if (sum > target) {
                        back--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[front], nums[back]});
                        while (front < back && nums[front] == nums[front + 1]) front++;
                        while (front < back && nums[back] == nums[back - 1]) back--;

                        front++;
                        back--;
                    }
                }
            }
        }
        return result;
    }
};