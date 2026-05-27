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
    int preorder_index = 0;

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // Base case: if there are no elements to construct the subtree
        if (left > right) return nullptr;

        // Select the preorder_index element as the root and increment it
        int root_value = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_value);

        // Build left and right subtrees based on the root's index in inorder array
        int inorder_root_index = inorder_map[root_value];

        // Elements to the left of inorder_root_index go to the left subtree
        root->left = arrayToTree(preorder, left, inorder_root_index - 1);
        
        // Elements to the right of inorder_root_index go to the right subtree
        root->right = arrayToTree(preorder, inorder_root_index + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_index = 0;
        inorder_map.clear();
        
        // Build a hash map to store value -> index relations for faster lookups
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
};