class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size()/2;
        int midEle = nums[mid];
        int count = 0;
        for (int num : nums) {
            if (count > 1) return 0;
            if (num == midEle) {
                count++;
            }
        }

        return count ==1;
    }
};