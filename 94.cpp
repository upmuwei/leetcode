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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traaversal(root, result);
        return result;
    }

    void traaversal(TreeNode* root, vector<int>& result) {
        if(root == nullptr) 
            return;
        traaversal(root->left, result);
        result.push_back(root->val);
        traaversal(root->right, result);
    }
};