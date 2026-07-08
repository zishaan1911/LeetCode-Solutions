class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int sum = numbers[left] + numbers[right];
        while (sum != target) {
            if (sum < target) left++;
            else if (sum > target) right--;
            sum = numbers[left] + numbers[right];
        }
        vector<int> res;
        res.push_back(left + 1);
        res.push_back(right + 1);
        return res;
    }
};