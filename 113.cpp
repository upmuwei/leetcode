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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> t;
        match(root, targetSum, result, 0, t);
        return result;
    }

    void match(TreeNode * root, int targetSum, vector<vector<int>>& result, int sum,vector<int>& t) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr&&root->right == nullptr) {
            sum += root->val;
            if(sum == targetSum) {
                t.push_back(root->val);
                result.push_back(t);
                t.pop_back();
            }
            return;
        }
        t.push_back(root->val);
        match(root->left, targetSum, result, sum+root->val, t);
        match(root->right, targetSum, result, sum+root->val, t);
        t.pop_back();
    }
};