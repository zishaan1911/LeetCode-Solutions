class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0;
        int current_end = 0;
        int farthest = 0;

        // We iterate to n-1 because once we reach the last index, 
        // we don't need to jump again.
        for (int i = 0; i < n - 1; i++) {
            // Update the furthest we can possibly reach from the current index
            farthest = max(farthest, i + nums[i]);

            // If we've reached the end of our current jump's range
            if (i == current_end) {
                jumps++;
                current_end = farthest;

                // Optimization: if we can already reach the end, break early
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};