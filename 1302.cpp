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
    vector<int> depths;
    vector<int> values;
    int maxDepth = 1;
public:
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesAgl(root, 1);
        int sum = 0;
        for(int i = 0; i < depths.size(); i++) {
            if(depths[i] == maxDepth) {
                sum += values[i];
            }
        }
        return sum;
    }

    void deepestLeavesAgl(TreeNode* root, int depth) {
        if(root->left == nullptr && root->right == nullptr) {
            depths.push_back(depth);
            values.push_back(root->val);
            if(depth > maxDepth) {
                maxDepth = depth;
            }
        }
        if(root->left != nullptr) {
            deepestLeavesAgl(root->left, depth + 1);
        }
        if(root->right != nullptr) {
            deepestLeavesAgl(root->right, depth + 1);
        }
    }
};