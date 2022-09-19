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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        putNode(result, 0, root);
        return result;
    }

    void putNode(vector<vector<int>>& result, int high, TreeNode *root) {
        if(root == nullptr) {
            return;
        }
        if(result.size() <= high) {
            vector<int> t;
            result.push_back(t);
        }
        putNode(result, high + 1, root->left);
        if(high%2==0) {
            result[high].push_back(root->val);
        } else {
            result[high].insert(result[high].begin(), root->val);
        }
        putNode(result, high + 1, root->right);
    }
};