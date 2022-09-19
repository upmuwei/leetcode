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
    long nowVal = (long)((int)0x80000000) - 1;
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        if(isValidBST(root->left) && root->val > nowVal) {
            nowVal = root->val;
            return isValidBST(root->right);
        }
        return false;
    }
};