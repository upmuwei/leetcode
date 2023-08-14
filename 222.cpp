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
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int count = 0;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        while(nodes.size()) {
            TreeNode * p = nodes.back();
            nodes.pop_back();
            count++;
            if(p->left != nullptr) {
                nodes.push_back(p->left);
            }
            if(p->right != nullptr) {
                nodes.push_back(p->right);
            }
        }
        return count;
    }
};