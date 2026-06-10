/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int calculateMaxGain(TreeNode* node, int& globalMax) {
        if (node == nullptr) return 0;

        int leftGain = max(calculateMaxGain(node->left, globalMax), 0);
        int rightGain = max(calculateMaxGain(node->right, globalMax), 0);

        int currentPathSum = node->val + leftGain + rightGain;

        globalMax = max(globalMax, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        int globalMax = INT_MIN;
        calculateMaxGain(root, globalMax);
        return globalMax;
    }
};