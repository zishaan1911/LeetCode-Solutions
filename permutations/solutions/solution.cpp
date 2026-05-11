class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // Base case: If we've reached the end of the array, we have a complete permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // 1. Swap the current element to the 'start' position
            swap(nums[start], nums[i]);
            
            // 2. Recursively generate permutations for the rest of the array
            backtrack(nums, start + 1, result);
            
            // 3. Backtrack: swap back to restore the original state for the next loop iteration
            swap(nums[start], nums[i]);
        }
    }
};