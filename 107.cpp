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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = getDepth(root);
        vector<vector<int>> result(depth);
        traverse(root, depth - 1, result);
        return result;
    }

    void traverse(TreeNode * root, int depth, vector<vector<int>>& result) {
        if(depth < 0 || root == nullptr) {
            return;
        }
        result[depth].push_back(root->val);
        traverse(root->left, depth - 1, result);
        traverse(root->right, depth - 1, result);
    }

    int getDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return 1 + (left > right ? left : right);
    }
};