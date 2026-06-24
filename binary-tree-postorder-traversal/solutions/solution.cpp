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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        postorder(root, res);
        reverse(res.begin(), res.end());
        return res; 
    }

private:
    void postorder(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }

        res.push_back(node->val);
        postorder(node->right, res);
        postorder(node->left, res);
    }
};
