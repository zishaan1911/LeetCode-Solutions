#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int nums3[m+n];

        for (int i=0; i<m; i++) {
            nums3[i] = nums1[i];
        }

        for (int i=0; i<n; i++) {
            nums3[m+i] = nums2[i];
        }

        sort(nums3, nums3 + (m+n));

        if ((m+n)%2 == 1) {
            return (nums3[(m+n)/2]);
        }

        else {
            return ((nums3[(m+n)/2] + nums3[(m+n)/2 - 1])/2.0);
        }
    }
};