class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index) {
        // Base Case: Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base Case: Target exceeded or no more candidates
        if (target < 0 || index == candidates.size()) {
            return;
        }

        // Choice 1: Include candidates[index]
        // We stay at 'index' because we can reuse the same number
        current.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], result, current, index);
        
        // Choice 2: Backtrack and skip candidates[index]
        current.pop_back();
        backtrack(candidates, target, result, current, index + 1);
    }
};