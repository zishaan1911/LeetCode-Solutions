class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPath;
        vector<bool> visited(nums.size(), false);
        
        // 1. Sort to handle duplicates easily
        sort(nums.begin(), nums.end());
        
        backtrack(nums, visited, currentPath, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<bool>& visited, vector<int>& currentPath, vector<vector<int>>& result) {
        // Base case: current path is a full permutation
        if (currentPath.size() == nums.size()) {
            result.push_back(currentPath);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip if already used
            if (visited[i]) continue;

            // 2. Skip duplicates: 
            // If nums[i] == nums[i-1] and the previous duplicate hasn't been used
            // in this specific recursion level, skip it to avoid duplicate branches.
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            // Standard backtracking steps
            visited[i] = true;
            currentPath.push_back(nums[i]);
            
            backtrack(nums, visited, currentPath, result);
            
            // Clean up (backtrack)
            currentPath.pop_back();
            visited[i] = false;
        }
    }
};