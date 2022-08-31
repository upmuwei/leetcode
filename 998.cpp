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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root->val < val) {
            TreeNode * newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        root->right = seek(root->right, val);
        return root;
    }

    TreeNode* seek(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }
        else if(root->val < val) {
            TreeNode * newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        else {
            root->right = seek(root->right, val);
        }
        return root;
    }
};