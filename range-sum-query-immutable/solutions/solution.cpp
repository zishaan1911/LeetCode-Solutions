class NumArray {
public:
    vector<int> nums;
    int totalSum = 0;
    NumArray(vector<int>& num) {
        for (int i = 0; i < num.size(); i++) {
            nums.push_back(num[i]);
            totalSum += num[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum = totalSum;
        for (int i = 0; i < left; i++) {
            sum -= nums[i];
        }
        for (int i = right + 1; i < nums.size(); i++) {
            sum -= nums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */