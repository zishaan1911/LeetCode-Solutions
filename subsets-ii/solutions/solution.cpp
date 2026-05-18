class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current_subset;
        
        sort(nums.begin(), nums.end());
        
        auto backtrack = [&](auto& self, int start, vector<int>& current_subset) -> void {
            result.push_back(current_subset);
            
            for (int i = start; i < nums.size(); i++) {
                if (i > start && nums[i] == nums[i - 1]) {
                    continue; 
                }
                
                current_subset.push_back(nums[i]);
                self(self, i + 1, current_subset);
                current_subset.pop_back();
            }
        };
        
        backtrack(backtrack, 0, current_subset);
        return result;
    }
};