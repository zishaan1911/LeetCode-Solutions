class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        
        if (min_val == max_val) return 0;
        
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;
        
        vector<int> min_b(bucket_count, INT_MAX);
        vector<int> max_b(bucket_count, INT_MIN);
        vector<bool> filled(bucket_count, false);
        
        for (int x : nums) {
            int b_idx = (x - min_val) / bucket_size;
            min_b[b_idx] = min(min_b[b_idx], x);
            max_b[b_idx] = max(max_b[b_idx], x);
            filled[b_idx] = true;
        }
        
        int max_gap = 0;
        int prev_max = min_val;
        for (int i = 0; i < bucket_count; i++) {
            if (!filled[i]) continue;
            max_gap = max(max_gap, min_b[i] - prev_max);
            prev_max = max_b[i];
        }
        
        return max_gap;
    }
};