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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int index = nums.size() / 2;
        TreeNode * root = new TreeNode(nums[index]);
        createTrees(nums, 0, index - 1, root);
        createTrees(nums, index + 1, nums.size() - 1, root);
        return root;
    }

    void createTrees(vector<int>& nums, int left, int right, TreeNode* root) {
        if(left > right) {
            return;
        }
        int index = (left + right) / 2;
        createTree(root, nums[index]);
        createTrees(nums, left, index - 1, root);
        createTrees(nums, index + 1, right, root);
    }

    void createTree(TreeNode * root,int val) {
        if(val < root->val && root->left != nullptr) {
            createTree(root->left, val);
        } else if(val < root->val && root->left == nullptr) {
            root->left = new TreeNode(val);
        } else if(val > root->val && root->right != nullptr) {
            createTree(root->right, val);
        } else {
            root->right = new TreeNode(val);
        }
    }
};