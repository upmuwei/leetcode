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
    int height;
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root);
        height = m -1;
        int n = pow(2, m) - 1;
        vector<vector<string>> result;
        for(int i = 0; i < m; i++) {
            vector<string> t(n, "");
            result.push_back(t);
        }
        putNode(result, 0, (n-1)/2, root);
        return result;
    }

    int getHeight(TreeNode * root) {
        if(root == nullptr) {
            return 0;
        } 
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return 1 + (leftHeight > rightHeight ?leftHeight : rightHeight );
    }

    void putNode(vector<vector<string>>& result, int r, int c, TreeNode * root) {
        result[r][c] = to_string(root->val);
        if(root->left != nullptr) {
            putNode(result, r+1, c - pow(2, height -r - 1), root->left);
        } 
        if(root->right != nullptr) {
            putNode(result, r+1,c + pow(2, height -r - 1) , root->right);
        }
    }
};