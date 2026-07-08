class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int count = 1;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) curr = nums[i];
            if (nums[i] == curr) count++;
            else {
                count--;
                if (count == 0) curr = nums[i];
            }

        }  
        return curr; 
    }
};