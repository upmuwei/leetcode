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
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        getDepth(root, balance);
        return balance;
    }

    int getDepth(TreeNode * root, bool& balance) {
        if(root == nullptr) {
            return 0;
        }
        int leftDepth = getDepth(root->left, balance);
        int rightDepth = getDepth(root->right, balance);
        if(leftDepth - rightDepth > 1 || rightDepth - leftDepth > 1) {
            balance = false;
        }
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
};