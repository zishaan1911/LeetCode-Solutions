class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int write_index = 2; 
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[write_index - 2]) {
                nums[write_index] = nums[i];
                write_index++;
            }
        }
        
        return write_index;
    }
};