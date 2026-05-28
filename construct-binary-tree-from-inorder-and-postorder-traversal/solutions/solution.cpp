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
    unordered_map<int, int> inorder_map;

    TreeNode* helper(vector<int>& postorder, int& postIdx, int inStart, int inEnd) {
        // Base case: if the range is invalid, there are no nodes to process
        if (inStart > inEnd) {
            return nullptr;
        }

        // The current element in postorder is the root of the current subtree
        int rootVal = postorder[postIdx];
        TreeNode* root = new TreeNode(rootVal);
        
        // Move the postorder index to the next root (scanning right to left)
        postIdx--;

        // Find the index of this root in the inorder array
        int inIdx = inorder_map[rootVal];

        // CRITICAL: Build the RIGHT subtree first because postorder traversal 
        // processed from the end goes: Root -> Right Subtree -> Left Subtree
        root->right = helper(postorder, postIdx, inIdx + 1, inEnd);
        root->left = helper(postorder, postIdx, inStart, inIdx - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map to store value -> index for fast lookup in the inorder vector
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        // Start from the last element of the postorder array
        int postIdx = postorder.size() - 1;
        
        return helper(postorder, postIdx, 0, inorder.size() - 1);
    }
};