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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if(root != nullptr) {
            visit(result, root, 1);   
        }
        return result;
    }

    void visit(vector<vector<int>>& result, TreeNode* root, int hight) {
        if(result.size() < hight) {
            vector<int> t;
            result.push_back(t);
        }
        result[hight - 1].push_back(root->val);
        if(root->left != nullptr) {
            visit(result, root->left, hight + 1);
        }
        if(root->right != nullptr) {
            visit(result, root->right, hight + 1);
        }
    }
};