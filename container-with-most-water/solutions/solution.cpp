class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxv = 0;
        int v = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            v = min(height[left], height[right]) * (right - left);
            maxv = max(v, maxv);

            if (height[left] < height[right]) {
                left++;
            }
            else right--;
        }
       
        return maxv;
    }
};