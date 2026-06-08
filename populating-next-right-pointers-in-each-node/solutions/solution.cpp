/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* level_start = root;
        
        while (level_start->left) {
            Node* curr = level_start;
            
            while (curr) {
                curr->left->next = curr->right;
                
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }
                
                curr = curr->next;
            }
            
            level_start = level_start->left;
        }
        
        return root;
    }
};