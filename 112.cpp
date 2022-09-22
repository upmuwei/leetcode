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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        return isSum(root, targetSum, 0);
    }

    bool isSum(TreeNode* root, int& targetSum, int high) {
        if(root == nullptr) {
            return false;
        }
        high += root->val;
        if(root->left == nullptr && root->right == nullptr) {
            if(high == targetSum) {
                return true;
            }
            return false;
        }
        return isSum(root->left, targetSum, high) || isSum(root->right, targetSum, high);
    }
};